#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> re;

void traceback(vector<int> v,vector<int> oneRe, int cut,int tar,int po)
{
    if(cut==tar)
    {
        re.emplace_back(oneRe);
    }
    else
    {
        for(int i=po;i<v.size();i++)
        {
            oneRe.emplace_back(v[i]);
            traceback(v,oneRe,cut+1,tar,i+1);
            oneRe.pop_back();
        }
    }
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    for(int i=0;i<=nums.size();i++)
    {
        traceback(nums,{},0,i,0);
    }
    return re;
}

int main()
{
    vector<int> v={0};
    vector<vector<int>> r=subsets(v);
    for(int i=0;i<r.size();i++)
    {
        for(int j=0;j<r[i].size();j++)
        {
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}