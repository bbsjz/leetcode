#include <iostream>
#include <vector>
using namespace std;

int max3(int a,int b,int c)
{
    int t1=max(a,b);
    int t2=max(t1,c);
    return t2;
}
int maxProfit(int k, vector<int> &prices)
{
    int num=prices.size();
    vector<vector<int>> in(num,vector<int>(num+1,0));
    vector<vector<int>> out(num,vector<int>(num+1,0));
    //持股 遍历了前n个物体，做了n笔交易-恰好进行j笔交易（买入再卖出就是一笔交易）
    //状态怎么初始化？比如遍历了0个物体，但是做了1，2，3，4笔交易，这不可能吧
    in[0][0]=-prices[0];out[0][0]=0;
    for(int i=1;i<num;i++)
    {
        out[i][0]=0;
        in[i][0]=max(-prices[i],in[i-1][0]);
    }
    for(int i=1;i<num;i++)
    {
        for(int j=1;j<=k;j++)
        {
            //第i天是否买入股票
            in[i][j]=max(in[i-1][j],out[i-1][j-1]-prices[i]);
            //第i天是否卖出股票
            out[i][j]=max(out[i-1][j],in[i-1][j-1]+prices[i]);
        }
    }
    //交易次数不是越多越好
    return max(in[num-1][k],out[num-1][k]);
}

int main()
{
    vector<int> v={2,4,1};
    cout<<maxProfit(2,v);
    return 0;
}