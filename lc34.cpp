#include<iostream>
#include<vector>
using namespace std;

int find2(vector<int> v,int l,int r,int target)
{
    if(l>r)
    {
        return -1;
    }
    int mid=(l+r)/2;
    if(v[mid]==target)
    {
        return mid;
    }
    else if(v[mid]<target)
    {
        return find2(v,mid+1,r,target);
    }
    else if(v[mid]>target)
    {
        return find2(v,l,mid-1,target);
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    int position=find2(nums,0,nums.size()-1,target);
    if(position==-1)
    {
        return {-1,-1};
    }
    int l=position,r=position;
    for(int i=position-1;i>=0;i--)
    {
        if(nums[i]==nums[position])
        {
            l--;
        }
        else
        {
            break;
        }
    }
    for(int i=position+1;i<nums.size();i++)
    {
        if(nums[i]==nums[position])
        {
            r++;
        }
        else
        {
            break;
        }
    }
    return {l,r};
}

int main()
{
    vector<int> v={5,7,7,8,8,10};
    vector<int> vn= searchRange(v,6);
    for(int i=0;i<vn.size();i++)
    {
        cout<<vn[i]<<" ";
    }
    return 0;
}