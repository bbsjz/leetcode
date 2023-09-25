#include <iostream>
#include <vector>
using namespace std;
int minFallingPathSum(vector<vector<int>> &grid)
{
    int row=grid.size(),column=grid[0].size();
    vector<vector<int>> dp(row,vector<int>(column,0x3f3f3f3f));
    for(int i=0;i<column;i++)
    {
        dp[0][i]=grid[0][i];
    }
    int result=0x3f3f3f3f;
    for(int i=1;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            for(int k=0;k<column;k++)
            {
                if(j!=k)
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+grid[i][j]);
                }
            }
        }
    }
    for(int i=0;i<column;i++)
    {
        result=min(result,dp[row-1][i]);
    }
    return result;
}