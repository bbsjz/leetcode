#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;

// void rememberSearch(int begin, int end, vector<vector<set<int>>> &dp, vector<int> &digits)
// {
//     if (begin == end)
//     {
//         dp[begin][end].insert(digits[begin]);
//         return;
//     }
//     for (int i = begin; i < end; i++)
//     {
//         if (dp[begin][i].empty())
//             rememberSearch(begin, i, dp, digits);
//         if (dp[i + 1][end].empty())
//             rememberSearch(i + 1, end, dp, digits);
//         for (int j : dp[begin][i])
//         {
//             for (int k : dp[i + 1][end])
//             {
//                 dp[begin][end].insert(j + k);
//                 int sum=0;
//                 for(int i=begin;i<=end;i++)
//                 {
//                     sum=sum*10+digits[i];
//                 }
//                 dp[begin][end].insert(sum);
//             }
//         }
//     }
// }

// bool isPenalty(int n)
// {
//     int cp = n;
//     n *= n;
//     vector<int> digits;
//     while (n)
//     {
//         int digit = n % 10;
//         n /= 10;
//         digits.push_back(digit);
//     }
//     int num = digits.size();
//     vector<int> reversed;
//     for(int i=digits.size()-1;i>=0;i--)
//         reversed.push_back(digits[i]);
//     vector<vector<set<int>>> dp(num, vector<set<int>>(num, set<int>()));
//     rememberSearch(0, num - 1, dp, reversed);
//     for (int sum : dp[0][num - 1])
//         if (sum == cp)
//             return true;
//     return false;
// }

//这个回溯的过程是重要的
bool isPenalty(int pos, int total, int target, vector<int> &digits)
{
    if (pos == digits.size())
        return total == target;
    int sum = 0;
    for (int i = pos; i < digits.size(); i++)
    {
        sum = sum * 10 + digits[i];
        if (sum + total > target)
            return false;
        if (isPenalty(i + 1, sum + total, target, digits))
            return true;
    }
    return false;
}

int punishmentNumber(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int i2 = i * i;
        vector<int> digits;
        while (i2)
        {
            digits.push_back(i2 % 10);
            i2 /= 10;
        }
        reverse(digits.begin(), digits.end());
        if (isPenalty(0, 0, i, digits))
        {
            sum += i * i;
        }
    }
    return sum;
}

int main()
{
    cout << punishmentNumber(37);
    return 0;
}