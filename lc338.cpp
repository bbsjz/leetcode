#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <queue>
using namespace std;

int divideby2(int x)
{
    return x&(x-1);
}

vector<int> countBits(int n) {
    vector<int> dp;
    dp.push_back(0);
    int latestnum=0;
    for(int i=1;i<=n;i++)
    {
        int num=divideby2(i);
        if(num==0) {dp.push_back(1);latestnum=i;}
        else dp.push_back(1+dp[i-latestnum]);
    }
    return dp;
}