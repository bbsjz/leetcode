#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int N = 30;
int dp[N][N];
string ss[N][N] = {""};
set<string> ress[N][N];
set<string> st;
bool match(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    else
        return false;
}
// match怎么办，不match怎么办
// 要求最小的次数，但是本来就是0，但是如果初始化成很大的数的时候，又会导致加上错误的结果
// 处理方式是初始化成很大的数，但是转换的时候做一下判断
// 每个过程都要存下来，不只是最后一步，在这个过程中都存在子区间有多种情况的现象，所以在这个过程中就要遍历
vector<string> removeInvalidParentheses(string s)
{
    if (s.length() == 1)
    {
        if (s.at(0) == '(' || s.at(0) == ')')
            return {""};
        else
            return {s};
    }
    int n = s.length();
    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        if (s.at(i) != '(' && s.at(i) != ')')
        {
            dp[i + 1][i + 1] = 0;
            string str(1, s.at(i));
            ss[i + 1][i + 1] = str;
            ress[i + 1][i + 1].insert(str);
        }
        else
        {
            dp[i + 1][i + 1] = 1;
            ress[i + 1][i + 1].insert("");
        }
    }
    for (int len = 1; len < n; len++) // length
    {
        for (int j = 1; j + len <= n; j++) // begin
        {
            if (match(s.at(j - 1), s.at(j + len - 1)))
            {
                if (dp[j][j + len] > dp[j + 1][j + len - 1])
                {
                    dp[j][j + len] = dp[j + 1][j + len - 1];
                    ss[j][j + len] = "(" + ss[j + 1][j + len - 1] + ")";
                }
                else
                {
                    dp[j][j + len] = 0;
                    ss[j][j + len] = "()";
                }
            }
            for (int k = j; k < j + len; k++) // breakpoint
            {
                if (dp[j][j + len] > dp[j][k] + dp[k + 1][j + len])
                {
                    dp[j][j + len] = dp[j][k] + dp[k + 1][j + len];
                    ss[j][j + len] = ss[j][k] + ss[k + 1][j + len];
                }
            }
            if (match(s.at(j - 1), s.at(j + len - 1)) && (dp[j + 1][j + len - 1] == dp[j][j + len] || len <= 2))
            {
                ress[j][j + len].insert("(" + ss[j + 1][j + len - 1] + ")");
                for (auto it = ress[j + 1][j + len - 1].begin(); it != ress[j + 1][j + len - 1].end(); it++)
                    ress[j][j + len].insert("(" + (*it) + ")");
            }
            for (int k = j; k < j + len; k++) // after those we get the zuixiao to modefy
            {
                if (dp[j][j + len] == dp[j][k] + dp[k + 1][j + len])
                {
                    for (auto ita = ress[j][k].begin(); ita != ress[j][k].end(); ita++)
                    {
                        // 因为是空的，所以没东西
                        for (auto itb = ress[k + 1][j + len].begin(); itb != ress[k + 1][j + len].end(); itb++)
                        {
                            ress[j][j + len].insert((*ita) + (*itb));
                        }
                    }
                }
            }
        }
    }
    vector<string> v;
    for (auto it = ress[1][n].begin(); it != ress[1][n].end(); it++)
    {
        v.push_back((*it));
    }
    return v;
}

int main()
{
    string s = "(()()()))((";
    removeInvalidParentheses(s);
    return 0;
}
