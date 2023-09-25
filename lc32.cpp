#include<iostream>
#include<string>
using namespace std;

//字符串越界，另外一种情况的概括
int longestValidParentheses(string s) {
    int l=s.length();
    int *dp=new int[l];//dp[i]表示以i个字符为结尾的最长子串的个数，由于完整的子串一定是以）结尾的，所以所有的（处的dp值都是0
    int max=0;
    for(int i=0;i<l;i++)
    {
        dp[i]=0;
    }
    for(int i=0;i<l-1;i++)
    {
        if(s[i]=='('&&s[i+1]==')')
        {
            if(i==0)
            {
                dp[1]=2;
                if(dp[1]>max)
                {
                    max=dp[1];
                }
            }
            else
            {
                dp[i+1]=dp[i-1]+2;
                if(dp[i+1]>max)
                {
                    max=dp[i+1];
                }
            }
        }
        else if(s[i]==')'&&s[i+1]==')')
        {
            if((i-dp[i]>=0)&&s[i-dp[i]]=='(')
            {
                if(i-dp[i]-1>=0)
                {
                    dp[i+1]=dp[i-dp[i]-1]+dp[i]+2;//不只是dp[i+1]=dp[i]+2，还要加上dp[i-dp[i]-1]，比如()(()())这种情况
                }
                else
                {
                    dp[i+1]=dp[i]+2;//防越界，比如(()())这种情况
                }
                if(dp[i+1]>max)
                {
                    max=dp[i+1];
                }
            }
        }
    }
    return max;
}

int main()
{
    cout<<longestValidParentheses("(()())");
    return 0;
}
