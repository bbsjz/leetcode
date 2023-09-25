#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mod=1e9+7;
int numFactoredBinaryTrees(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int num = arr.size();
    vector<int> dp(num);
    for (int i = 0; i < num; i++)
    {
        dp[i] = 1;
        int target = arr[i];
        int l = 0, r = i - 1;
        while (l <= r)
        {
            int he = arr[l] + arr[r];
            while (he == target)
            {
                int adder = (dp[l]%mod * dp[r]%mod)%mod;
                if (arr[l] != arr[r])
                    adder = (2*adder)%mod;
                dp[i]=(dp[i]+adder)%mod;
                l++;r--;
                he = arr[l] + arr[r];
            }
            if(he<target) l++;
            else if(he>target) r--;
        }
    }
    return dp[num-1];
}

int main()
{
    vector<int> v={2,4,5,10};
    cout<<numFactoredBinaryTrees(v);
    return 0;
}