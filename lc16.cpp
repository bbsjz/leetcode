#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int re=nums[0]+nums[1]+nums[2];
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<=n-3;i++)
    {
        if(i>0&&nums[i]==nums[i-1]) continue;
        int l=i+1,r=n-1;
        while(l<r)
        {
            int sum=nums[i]+nums[l]+nums[r];
            if(sum==target) return sum;
            else if(sum<target) 
            {
                if(target-sum<abs(re-sum)) re=sum;
                l++;
            }
            else 
            {
                if(sum-target<abs(re-sum)) re=sum;
                r--;
            }
        }
    }
    return re;
}