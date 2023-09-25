#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int maxSlice(vector<int> &slices)
{
    int len = slices.size();
    int num = (len+1) / 3;
    vector<vector<int>> dp(len, vector<int>(num + 1));
    dp[0][1] = slices[0];
    dp[1][1] = max(slices[1],slices[0]);
    for (int i = 2; i < len; i++)
    {
        for(int j=1;j<=num;j++)
        {
            dp[i][j]=max(dp[i-2][j-1]+slices[i],dp[i-1][j]);
        }
    }
    return dp[len-1][num];
}

int maxSizeSlices(vector<int> &slices)
{
    int num=slices.size();
    int tmp=slices[num-1];
    slices.pop_back();
    int t1=maxSlice(slices);
    slices.push_back(tmp);
    slices.erase(slices.begin());
    int t2=maxSlice(slices);
    return t1<t2?t2:t1;
}

int main()
{
    //                 0 1 2 3 4 5 6 7 8
    vector<int> slice = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << maxSizeSlices(slice);
    return 0;
}