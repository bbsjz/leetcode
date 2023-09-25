#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int** dp;
    int* minTime;
    int coinsSize;
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount==0)
        {
            return 0;
        }
        coinsSize=coins.size();
        dp=new int*[amount+1];
        minTime=new int[amount+1];//记录每个数值最小凑出需要的硬币
        for(int i=0;i<amount+1;i++)
        {
            dp[i]=new int[coinsSize];
        }

        for(int i=0;i<amount+1;i++)//i表示要凑的钱数
        {
            for(int j=0;j<coinsSize;j++)
            {
                if(i-coins[j]==0)//刚好一枚可以凑
                {
                    dp[i][j]=1;
                }
                else if(i-coins[j]<0)//负数，凑不了
                {
                    dp[i][j]=-1;
                }
                else//理论上可以凑，在要凑的钱数-目前的硬币面值所需最小的硬币数的基础上+1
                {
                    if(minTime[i-coins[j]]==-1)//但是如果要凑的钱数-目前的硬币面值是无效的，那么当前的也凑不出来，从而也是无效的
                    {
                        dp[i][j]=-1;
                    }
                    else
                    {
                        dp[i][j]=minTime[i-coins[j]]+1;
                    }               
                } 
            }
            minTime[i]=min(i);
        }
        return minTime[amount];
    }

    int min(int j)//要凑j元，即第j行的情况
    {
        int min=INT_MAX;
        for(int i=0;i<coinsSize;i++)
        {
            if(dp[j][i]==-1)
            {
                continue;
            }
            else if(dp[j][i]<min)
            {
                min=dp[j][i];
            }
        }
        if(min==INT_MAX)//如果一直没有被改变，那么就都是无效的
        {
            return -1;
        }
        else
        {
            return min;
        }
    }
};

int main()
{
    vector<int> coins={2};
    Solution so;
    cout<<so.coinChange(coins,3);
    return 0;
}