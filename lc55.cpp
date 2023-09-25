#include<iostream>
#include<vector>
using namespace std;

int maxn(int a,int b)
{
    return a>b?a:b;
}
bool canJump(vector<int>& nums)
{
    int max=0;
    for(int i=0;i<nums.size();i++)
    {
        max=maxn(max,i+nums[i]);
        if(max==i&&i!=nums.size()-1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> v={3,2,1,0,4};
    cout<<canJump(v);
    return 0;
}

