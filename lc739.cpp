#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> st;
    vector<int> re(temperatures.size(),0);
    for(int i=0;i<temperatures.size();i++)
    {
        while(st.size()&&temperatures[st.back()]<temperatures[i])
        {
            re[st.back()]=i-st.back();
            st.pop_back();
        }
        st.push_back(i);
    }
    while(st.size())
    {
        re[st.back()]=0;st.pop_back();
    }
    return re;
}

int main()
{
    vector<int> test={1};
    dailyTemperatures(test);
    return 0;
}