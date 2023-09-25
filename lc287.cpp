#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

//套二分查找模板，我要找第一个大于count的，那么小于count就是不满足条件的类别，要放到前面去，然后返回最前面的条件l
int findDuplicate(vector<int>& nums) {
    int n=nums.size();
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=mid) count++;
        }
        if(count<=mid)//说明这个数在标准答案左边 
            l=mid+1;
        else r=mid-1;
    }
    return l;
}

int main()
{
    vector<int> v={1,3,4,2,2};
    cout<<findDuplicate(v);
    return 0;
}