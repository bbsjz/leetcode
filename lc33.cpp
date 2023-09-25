#include<iostream>
#include<vector>
using namespace std;

int find2(vector<int> &nums,int l,int r,int target)
{
    if(l>r)
    {
        return -1;
    }
    int mid=(l+r)/2;
    if(target==nums[mid])
    {
        return mid;
    }
    else if(target>nums[mid])
    {
        return find2(nums,mid+1,r,target);
    }
    else
    {
        return find2(nums,l,mid-1,target);
    }
}
int search(vector<int>& nums, int target) 
{
    int l=nums.size();
    int bound=0;
    for(int i=0;i<l-1;i++)
    {
        if(nums[i]>nums[i+1])
        {
            bound=i;
        }
    }
    int left=find2(nums,0,bound,target);
    if(left==-1)
    {
        int right=find2(nums,bound+1,l-1,target);
        return right;
    }
    else
    {
        return left;
    }
}

int main()
{
    vector<int> v={1};
    cout<<search(v,2);
    return 0;
}