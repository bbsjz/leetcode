#include <iostream>
#include <vector>
using namespace std;
//dp[i][j]:the number of solutions which use the first i-th dices to get j total
int numRollsToTarget(int n, int k, int target)
{
    int mod=1e9+7;
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    for(int i=1;i<=min(target,k);i++)
    {
        dp[1][i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=i;j<=min(target,i*k);j++)//the total solution that could be made
        {
            for(int q=1;q<=k&&j-q>=0;q++)//the contribution the i-th dice made this time
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-q])%mod;
            }
        }
    }
    return dp[n][target];
}

int main()
{
    cout<<numRollsToTarget(30,30,500);
    return 0;
}