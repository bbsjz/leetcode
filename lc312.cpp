#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int N=310;
int dp[N][N];
vector<int> val;
//它这样相当于全部遍历了一遍
//如果每次选择戳破一个气球的话，会导致数组的变化
//但是看做相反的过程每次添加一个气球是不需要的，每次添加的这个气球就是这一次被戳破的气球
int solve(int l,int r)
{
    if(l+1>=r) return 0;
    else if(dp[l][r]!=0) return dp[l][r];
    else 
    {
        for(int i=l+1;i<r;i++)
        {
            dp[l][r]=max(val[l]*val[i]*val[r]+solve(l,i)+solve(i,r),dp[l][r]);
        }
        return dp[l][r];
    }
}

int maxCoins(vector<int>& nums) {
    int n=nums.size();
    val.resize(n+2);
    val[0]=1;val[n+1]=1;
    for(int i=1;i<=n;i++)
    {
        val[i]=nums[i-1];
    }
    return solve(0,n+1);
}
//如果是dp的话我觉得主要是不知道它上一个状态从什么地方转移过来啊
//比如abc可以从ac转移过来，但是ac中间隔了一个b所以不是连续的啊，怎么找到ac这个状态呢
//靠，但是看成是添加气球的话就可以转移了，就是可以看作xabcx之间遍历，先在xx之间加上a，再在ax之间加上c，最后在ac之间加上b
//就是上面等价的状态