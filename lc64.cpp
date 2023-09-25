#include<iostream>
#include<vector>
using namespace std;

int min(int a,int b)
{
    return a>b?b:a;
}

// int minPath(vector<vector<int>> v,int m,int n,int sum)
// {
//     sum+=v[m][n];
//     if(m==v.size()-1&&n==v[0].size()-1)
//     {
//         return sum;
//     }
//     else
//     {
//         int sum1=INT_MAX,sum2=INT_MAX;
//         if(m<v.size()-1)
//         {
//             sum1=minPath(v,m+1,n,sum);
//         }
//         if(n<v[0].size()-1)
//         {
//             sum2=minPath(v,m,n+1,sum);
//         }
//         return min(sum1,sum2);
//     }
// }

int minPathSum(vector<vector<int>>& grid) 
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    dp[0][0]=grid[0][0];
    for(int i=1;i<n;i++)
    {
        dp[0][i]=dp[0][i-1]+grid[0][i];
    }
    for(int j=1;j<m;j++)
    {
        dp[j][0]=dp[j-1][0]+grid[j][0];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=min(dp[i][j-1]+grid[i][j],dp[i-1][j]+grid[i][j]);
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> v={{1,2,3},{4,5,6}};
    cout<<minPathSum(v);
    return 0;
}