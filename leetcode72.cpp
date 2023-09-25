#include<iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1=word1.length()+1;
        int l2=word2.length()+1; 

        int **dp=new int*[l2];
        for(int i=0;i<l2;i++)
        {
            dp[i]=new int[l1];
        }

        for(int i=0;i<l1;i++)
        {
            dp[0][i]=i;
        }

        for(int i=0;i<l2;i++)
        {
            dp[i][0]=i;
        }

        for(int i=1;i<l2;i++)
        {
            for(int j=1;j<l1;j++)
            {
                char tmp1=word1.at(j-1);
                char tmp2=word2.at(i-1);
                if(tmp1==tmp2)
                {
                    dp[i][j]=min(dp[i-1][j]+1,dp[i-1][j-1],dp[i][j-1]+1);
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j]+1,dp[i-1][j-1]+1,dp[i][j-1]+1);
                }
            }
        }

        return dp[l2-1][l1-1];
    
    }

    int min(int a,int b,int c)
    {
        if(a<b)
        {
            if(a<c)
            {
                return a;
            }
            else
            {
                return c;
            }
        }
        else if(c<b)
        {
            return c;
        }
        else
        {
            return b;
        }
    }
};

int main()
{
    Solution so;
    cout << so.minDistance("intention","execution");
    return 0;
}