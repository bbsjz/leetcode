#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> all;

void traceback(vector<int> v,vector<int> position,int sum,int target,int po)
{
    if(sum>target)
    {
        return;
    }
    else if(sum==target)
    {
        all.push_back(position);
        return;
    }
    else
    {
        for(int i=po;i<v.size();i++)
        {
            position.push_back(v[i]);
            traceback(v,position,sum+v[i],target,i);
            position.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    traceback(candidates,{},0,target,0);
    return all;
}

int main()
{
    vector<int> v={2,3,5};
    vector<vector<int>> a=combinationSum(v,8);
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