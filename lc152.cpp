#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
const int N=20010;
int dpmin[N];
int dpmax[N];
int maxProduct(vector<int>& nums) {
    int maxsum;
    maxsum=dpmin[0]=dpmax[0]=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        int t1,t2;
        if(nums[i-1]==0)
        {
            t1=t2=nums[i];
        }
        else {t1 = dpmax[i-1]*nums[i];t2 = dpmin[i-1]*nums[i];}
        dpmax[i]=max(nums[i],t1);
        dpmax[i]=max(dpmax[i],t2);
        maxsum=max(maxsum,dpmax[i]);
        dpmin[i]=min(nums[i],t1);
        dpmin[i]=min(dpmin[i],t2);
    }
    return maxsum;
}