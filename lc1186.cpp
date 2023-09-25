#include <vector>
using namespace std;
// 这样没办法通过[-8,1,2,-7,6,5]
// 枚举删除所有负数的情况，然后依次做比较

int maxsumpos(int pos, vector<int> arr)
{
    arr.erase(pos + arr.begin());
    int maxre = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > 0)
            arr[i] += arr[i - 1];
        maxre = max(maxre, arr[i]);
    }
    return maxre;
}

int maximumSum(vector<int> &arr)
{
    if (arr.size() == 1)
        return arr[0];
    int maxre = arr[0];
    int sign = true;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            maxre = max(maxre, maxsumpos(i, arr));
            sign = false; // have negtive num
        }
    }
    if (sign)
    {
        int sum=0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum+=arr[i];
        }
        maxre=max(maxre,sum);
    }
    return maxre;
}
