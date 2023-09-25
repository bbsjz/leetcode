#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

//0表示当天买入股票，1表示当天处于冻结，2表示当天不持股票是不行的
// int maxProfit(vector<int>& prices) {
//     vector<int> dp[3];//0-mairu,1-dongjie,2buchigu
//     dp[0].push_back(-prices[0]);dp[1].push_back(0);dp[2].push_back(0);
//     for(int i=1;i<prices.size();i++)
//     {
//         //mairu only when buchigu
//         dp[0].push_back(dp[2].back()-prices[i]);
//         //dongjie only when maichu
//         dp[1].push_back(dp[2].back());
//         //buchigu can shift from buchigu or mairu
//         dp[2].push_back(max(dp[2].back(),dp[0].back()+prices[i]));
//     }
// }

//应是0表示当天持有股票，这个股票可以是当天买入的，如果当天要买入，那么要求前一天结束的时候不是冻结期，也可以是i-1天就有的，而当天没有进行任何操作
//1表示当天不持有股票，并且不处于冻结期，那么当天不会卖出股票，他由前一个不持股的状态转移过来，要么处于冻结期，要么不处于冻结期
//不能由持股状态转移过来，因为这里规定了不能持股
//2表示当天不持有股票，并且处于冻结期，说明前一天卖出了股票，要求i-2天持有股票，且i-1天卖出了股票
//（错误的，主要是这样表示不好整，是假设当天卖出了股票，之后处于冻结期
// 冻结期在第二天体现出的效果是在1中，可以由冻结期转移过来
int max3(int a,int b,int c)
{
    if(a>b)
        if(a>c) return a;
        else return c;
    else
        if(b>c) return b;
        else return c;
}
int maxProfit(vector<int>& prices) {
    vector<int> dp[3];
    dp[0].push_back(-prices[0]);dp[1].push_back(0);dp[2].push_back(0);
    for(int i=1;i<prices.size();i++)
    {
        dp[0].push_back(max(dp[0].back(),dp[1].back()-prices[i]));
        dp[1].push_back(max(dp[1].back(),dp[2].back()));
        dp[2].push_back(dp[0].back()+prices[i]);
    }
    return max3(dp[0][prices.size()-1],dp[1][prices.size()-1],dp[2][prices.size()-1]);
}

int main()
{
    vector<int> v={1,2,3,0,2};
    cout<<maxProfit(v);
    return 0;
}