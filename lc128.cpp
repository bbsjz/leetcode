#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    for(int i=0;i<nums.size();i++)//哈希表插入是On
    {
        st.insert(nums[i]);
    }
    int maxsum=1;
    for(int i:st)//遍历外循环是On
    {
        int maxt=1;
        if(st.count(i-1)!=0) continue;
        while(st.count(i+1)!=0)//内循环加起来严格是On，所有的数最多只会出现一次
        {
            maxt++;
            i++;
        }
        maxsum=max(maxsum,maxt);
    }
    return maxsum;
}
