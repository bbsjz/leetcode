#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
struct node
{
    int num,frequency;
    bool operator>(const node n)const
    {
        if(frequency==n.frequency) return num>n.num;
        else return frequency>n.frequency;
    }
};


vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> m;
    for(int i=0;i<nums.size();i++) m[nums[i]]++;
    set<node,greater<node>> st;
    for(auto it=m.begin();it!=m.end();it++)
        st.insert({(*it).first,(*it).second});
    vector<int> v;
    for(auto it=st.begin();it!=st.end()&&v.size()!=k;it++)
    {
        v.push_back((*it).num);
    }
    return v;
}

int main()
{
    vector<int> nums={1,2};
    topKFrequent(nums,2);
    return 0;
}