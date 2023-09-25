#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
using namespace std;
const int N=10010;
int dp[N];
int numSquares(int n) {
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;dp[1]=1;
    vector<int> base;
    base.push_back(1);
    for(int i=2;i<=n;i++)
    {
        int gen=sqrt(i);
        if(base.back()<gen) base.push_back(gen);
        for(int j=0;j<base.size();j++)
        {   
            int square=base[j]*base[j];
            dp[i]=min(dp[i],i/square+dp[i-i/square*square]);
        }
    }
    return dp[n];
}

int main()
{
    cout<<numSquares(13);
    return 0;
}