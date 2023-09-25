#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> re;
    sort(nums.begin(),nums.end());
    re.push_back(nums);
    int l=nums.size();
    int position=-1;
    int element=0;
    for(int i=l-1;i>0;i--)
    {
        if(nums[i-1]<nums[i])
        {
            position=i-1;
            element=nums[position];
            break;
        }
    }
    while (position!=-1)
    {
        for(int i=l-1;i>0;i--)
        {
            if(nums[i]>element)
            {
                nums[position]=nums[i];
                nums[i]=element;
                break;
            }
        }
        auto it=nums.begin()+position+1;
        sort(it,nums.end());
        re.push_back(nums);
        position=-1;
        for(int i=l-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                position=i-1;
                element=nums[position];
                break;
            }
        }
    }
    return re;
}

int main()
{
    vector<int> v={1};
    vector<vector<int>> a=permute(v);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}