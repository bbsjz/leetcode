#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=310;
int dp[N];

bool check(int pos,string s,string word)
{
    if(pos<word.length()) return false;
    for(int j=pos-word.length(),i=0;j<pos;j++,i++)
    {
        if(s[j]!=word[i]) return false;
    }
    return true;
}

bool wordBreak(string s, vector<string>& wordDict) {
    dp[0]=true;
    for(int i=1;i<=s.length();i++)
    {
        for(string word:wordDict)
        {
            dp[i]|=(check(i,s,word)&&dp[i-word.length()]);
        }
    }
    return dp[s.length()];
}