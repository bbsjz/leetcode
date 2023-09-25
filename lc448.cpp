#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums) {
    set<int> st;
    vector<int> re;
    for(int i=1;i<=nums.size();i++)
    {
        st.insert(i);
    }
    for(int i=0;i<nums.size();i++)
    {
        if(st.count(nums[i])!=0) st.erase(nums[i]);
    }
    for(auto it=st.begin();it!=st.end();it++)
    {
        re.push_back((*it));
    }   
    return re;
}

int main()
{
    vector<int> v={2};
    findDisappearedNumbers(v);
    return 0;
}