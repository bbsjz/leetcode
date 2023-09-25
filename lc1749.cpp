#include <iostream>
#include <vector>
using namespace std;
int maxAbsoluteSum(vector<int> &nums)
{
    int n=nums.size();
    vector<int> minv(n),maxv(n);
    int re=0;
    for(int i=0;i<nums.size();i++)
    {
        if(i>0&&maxv[i-1]>0)
        {
            maxv[i]=maxv[i-1]+nums[i];
        }
        else maxv[i]=nums[i];
        re=max(re,abs(maxv[i]));
        if(i>0&&minv[i-1]<0)
        {
            minv[i]=minv[i-1]+nums[i];
        }
        else minv[i]=nums[i];
        re=max(re,abs(minv[i]));
    }
    return re;
}