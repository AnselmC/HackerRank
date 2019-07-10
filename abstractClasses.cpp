#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache: public Cache {
    private:
        int cp;
        Node* head;
        Node* tail;
        std::vector<Node*> nodes;
    public:
        LRUCache(int cap): cp(cap), head(NULL), tail(NULL){};
        void set(int key, int value){
            auto foundNode = mp.find(key) != mp.end();
            auto node = foundNode ? mp[key] : new Node(key, value); 
            if(!foundNode){
                nodes.insert(nodes.begin(), node);
                mp[key] = node;
                if(mp.size()>cp){
                    mp.erase(nodes.back()->key);
                    nodes.pop_back();
                }
            } else {
                node->value = value;
                std::vector<Node*>::iterator pos = std::find(nodes.begin(), nodes.end(), mp[key]);
                nodes.erase(pos);
                nodes.insert(nodes.begin(), node);
            }
        }
        int get(int key){
            auto foundNode = mp.find(key) != mp.end();
            if(!foundNode){
                return -1;
            }
            else {
                return mp[key]->value;
            }
        }
}
