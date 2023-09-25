#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

// map<int,int,greater<int>> m;
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> v;
//     for(int i=0;i<k;i++)
//     {
//         m[nums[i]]++;
//     }
//     v.push_back(m.begin()->first);
//     for(int i=k;i<nums.size();i++)
//     {
//         if (m[nums[i-k]]>1) m[nums[i-k]]--;
//         else m.erase(nums[i-k]);
//         m[nums[i]]++;
//         v.push_back(m.begin()->first);
//     }
//     return v;
// }
struct node
{
    int num,pos;
};
deque<node> st;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> v;
    for(int i=0;i<k;i++)
    {
        if(st.empty()||st.back().num>nums[i]) st.push_back({nums[i],i});
        else 
        {
            while(st.size()&&st.back().num<=nums[i]) st.pop_back();
            st.push_back({nums[i],i});
        }
    }
    v.push_back(st.front().num);
    for(int i=k;i<nums.size();i++)
    {
        if(st.empty()||st.back().num>nums[i]) st.push_back({nums[i],i});
        else 
        {
            while(st.size()&&st.back().num<=nums[i]) st.pop_back();
            st.push_back({nums[i],i});
        }
        while(st.front().pos<=i-k) st.pop_front();
        v.push_back(st.front().num);
    }
    return v;
}
int main()
{
    vector<int> n={-1,1};
    vector<int> re=maxSlidingWindow(n,1);
    return 0;
}