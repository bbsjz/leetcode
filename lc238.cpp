#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int l=nums.size();
    vector<int> f(l,nums[0]);
    vector<int> r(l,nums.back());
    vector<int> ans(l,0);
    for(int i=1;i<l;i++)
    {
        f[i]=f[i-1]*nums[i];
    }
    for(int i=l-2;i>=0;i--)
    {
        r[i]=r[i+1]*nums[i];
    }
    for(int i=0;i<l;i++)
    {
        if(i==0) ans[i]=r[i+1];
        else if(i==l-1) ans[i]=f[i-1];
        else ans[i]=f[i-1]*r[i+1];
    }
    return ans;
}