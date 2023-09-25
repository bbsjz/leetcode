#include <iostream>
#include <vector>
using namespace std;
int min3(int a,int b,int c)
{
    if(a<b)
    {
        if(a<c) return a;
        else return c;
    }
    else
    {
        if(b<c) return b;
        else return c;
    }
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int row=matrix.size();
    int column=matrix[0].size();
    vector<vector<int>> dp=vector<vector<int>>(row,vector<int>(column,0));
    for(int i=0;i<column;i++) dp[0][i]=matrix[0][i];
    for(int i=1;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            int shangyibu=dp[i-1][j];
            if(j-1>=0) shangyibu=min(shangyibu,dp[i-1][j-1]);
            if(j+1<column) shangyibu=min(shangyibu,dp[i-1][j+1]);
            dp[i][j]=shangyibu+matrix[i][j];
        }
    }
    int result=dp[row-1][0];
    for(int j=1;j<column;j++)
    {
        result=min(result,dp[row-1][j]);
    }
    return result;
}

int main()
{
    vector<vector<int>> test={{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(test);
    return 0;
}