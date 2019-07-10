#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Message {
    private:
        string text;
        static int counter;
        int id;
    public: 
        Message():id(++counter){}
        Message(string msg):id(++counter),text(msg){}
        const string& get_text() {
            return text;
        }
        bool operator<(const Message& otherMessage){
            if(id < otherMessage.id){
                return true;
            }
            else{
                return false;
            }
        }
};

int Message::counter=0;

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message msg = Message(text);
        return msg;
    }
}
