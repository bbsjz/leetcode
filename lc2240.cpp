#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int dp[N];
long long waysToBuyPensPencils(int total, int cost1, int cost2)
{
    dp[0] = 1;
    for (int i = 0; i <= total; i++)
    {
        if (i >= cost1)
            dp[i] += dp[i - cost1];
    }
    long long sum=0;
    for (int i = 0; i <= total; i++)
    {
        if (i >= cost2)
            dp[i]+=dp[i-cost2];
        sum+=dp[i];    
    }
    return sum;
}