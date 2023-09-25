#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    vector<vector<int>> re;
    vector<pair<int,int>> p;
    for(int i=0;i<intervals.size();i++)
    {
        pair<int,int> tmp;
        tmp.first=intervals[i][0];
        tmp.second=intervals[i][1];
        p.emplace_back(tmp);
    }
    sort(p.begin(),p.end(),[](const pair<int,int>&x,const pair<int,int>& y)
    ->
    int{
        return x.first<y.first;
    });
    int begin=p[0].first;
    int end=p[0].second;
    for(int i=0;i<p.size()-1;i++)
    {
        if(end>=p[i+1].first)
        {
            //注意不是直接end=p[i+1].second，可能第二个区间的second比第一个还要小，比如[1,4],[2,3]
            //注意是区间最远的那个位置的数相比较
            end=max(p[i+1].second,end);
        }
        else
        {
            vector<int> v;
            v.emplace_back(begin);
            v.emplace_back(end);
            re.emplace_back(v);
            begin=p[i+1].first;
            end=p[i+1].second;
        }
    }
    vector<int> v;
    v.emplace_back(begin);
    v.emplace_back(end);
    re.emplace_back(v);
    return re;
}

int main()
{
    vector<vector<int>> v={{1,10},{2,3},{4,5},{6,7},{8,9}};
    vector<vector<int>> re=merge(v);
    for(int i=0;i<re.size();i++)
    {
        for(int j=0;j<re[i].size();j++)
        {
            cout<<re[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}