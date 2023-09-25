#include<iostream>
#include<vector>
using namespace std;

int min(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    return a>b?b:a;
}
int jump(vector<int>& nums) 
{
    int l=nums.size();
    vector<int> v(l);
    for(int i=1;i<l;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(nums[j]>=i-j)
            {
                v[i]=min(v[i],v[j]+1);
            }
        }
    }
    return v[l-1];
}
int main()
{
    vector<int> v={2,3,0,1,4};
    cout<<jump(v);
    return 0;
}