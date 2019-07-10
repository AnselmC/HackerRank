#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Matrix {
    public:
        Matrix(){};
        vector<vector<int>> a;
        Matrix operator + (Matrix &otherMatrix){
            Matrix result;
            for(int i=0; i<otherMatrix.a.size(); i++){
                vector<int> b;
                for(int j=0; j<otherMatrix.a[i].size(); j++){
                    b.push_back(a[i][j] + otherMatrix.a[i][j]);
                }
                result.a.push_back(b);
            }
            return result;
        }
}
