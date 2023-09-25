#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums) 
{
    int l=nums.size();
    int position=-1;
    int tmp=0;
    for(int i=l-1;i>0;i--)
    {
        if(nums[i-1]<nums[i])
        {
            position=i-1;
            tmp=nums[i-1];
            break;
        }
    }
    if(position==-1)
    {
        sort(nums.begin(),nums.end());
        return;
    }
    for(int i=l-1;i>0;i--)
    {
        if(nums[i]>tmp)
        {
            nums[position]=nums[i];
            nums[i]=tmp;
            auto b=nums.begin()+position+1;
            sort(b,nums.end());
            break;
        }
    }
}

int main()
{
    vector<int> v={1,1,5};
    nextPermutation(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}