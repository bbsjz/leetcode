#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

//三次循环解决，找到最小的乱序的数字，最后一个需要调整的数字肯定是在遍历过程中碰到的最后一个数字
//最前面需要调整的数字就是把最小的数字插到前面去就可以了，只要乱序数字中最小的数归位了
//那么这个区间排序后再和大的区间合并起来肯定就没问题
int findUnsortedSubarray(vector<int>& nums) {
    vector<int> maxv;
    maxv.push_back(nums[0]);
    for(int i=1;i<nums.size();i++)
        maxv.push_back(max(maxv.back(),nums[i]));
    int minb=0,mine=0;
    int minnum=0x3f3f3f3f;
    for(int i=0;i<nums.size();i++)
        if(nums[i]<maxv[i])
        {
            mine=i;minnum=min(minnum,nums[i]);
        }
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>minnum)
        {
            minb=i;break;
        }
    }
    if(minb==mine) return 0;
    else return mine-minb+1;
}

int main()
{
    vector<int> v={2,1};
    cout<<findUnsortedSubarray(v);
    return 0;
}