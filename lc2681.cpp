#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int sumOfPower(vector<int> &nums)
{
    int mod=1e9+7;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<int> dp(n,0);
    vector<int> prefix(n,0);
    long long t2=(long long)nums[0]*nums[0]%mod;
    long long sum=(t2*nums[0])%mod;
    dp[0]=nums[0];
    prefix[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=(prefix[i-1]+nums[i])%mod;
        prefix[i]=(dp[i]+prefix[i-1])%mod;
        long long t1=(long long)nums[i]*nums[i]%mod;
        long long t=(t1*dp[i])%mod;
        sum=(sum+t)%mod;
    }
    return (int)sum;
}
