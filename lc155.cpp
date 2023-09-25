#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class MinStack {
    vector<int> v;
    vector<int> minv;
public:
    MinStack() {

    }
    
    void push(int val) {
        v.push_back(val);
        if(minv.empty()) minv.push_back(val);
        else minv.push_back(min(minv.back(),val));
    }
    
    void pop() {
        if(v.size())
        {
            v.pop_back();
            minv.pop_back();
        }
    }
    
    int top() {
        if(v.size()) return v.back();
        else return -1;
    }
    
    int getMin() {
        if(v.size()) return minv.back();
        else return -1;
    }
};