#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int countSubstrings(string s) {
    int cnt=0;
    vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
    for(int i=0;i<s.length();i++)
    {
        dp[i][i]=true;cnt++;
    }
    for(int len=1;len<s.length();len++)
    {
        for(int j=0;j+len<s.length();j++)
        {
            if(s.at(j)==s.at(j+len)&&len>1)
            {
                dp[j][j+len]=dp[j+1][j+len-1];
                if(dp[j][j+len]) cnt++;
            }
            else if(s.at(j)==s.at(j+len)) 
            {
                dp[j][j+len]=true;cnt++;
            }
            else dp[j][j+len]=false;
        }
    }
    return cnt;
}