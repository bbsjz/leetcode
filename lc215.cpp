#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

//但是在这种快速排序划分中，带等号
//是从右往左找到严格小于
int partition(int l,int r,vector<int>& nums)
{
    int base=nums[l],i=l,j=r;
    while(i<j)
    {
        while(nums[j]<=base&&i<j) j--;
            nums[i]=nums[j];
        while(nums[i]>=base&&i<j) i++;
            nums[j]=nums[i];
    }
    nums[i]=base;
    return i;
}

int findKthLargest(vector<int>& nums, int k) {
    if(nums.size()==1) return nums.back();
    int l=0,r=nums.size()-1;
    while(l<=r)
    {
        int pos=partition(l,r,nums);
        if(pos==k-1) return nums[pos];
        else if(pos<k-1) l=pos+1;
        else r=pos-1; 
    }
    return -1;
}

int main()
{
    vector<int> nums={2,1};
    cout<<findKthLargest(nums,2);
    return 0;
}