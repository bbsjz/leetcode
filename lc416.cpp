#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++) sum+=nums[i];
    if(sum%2==1) return false;
    vector<bool> dp(sum/2+1,0);
    dp[0]=true;
    for(int i=1;i<=nums.size();i++)
    {
        for(int j=sum/2;j>=nums[i-1];j--)
        {
            if(dp[j-nums[i-1]])
                dp[j]=true;
        }
    }
    return dp[sum/2];
}

int main()
{
    vector<int> v={1,2,5};
    cout<<canPartition(v);
    return 0;
}