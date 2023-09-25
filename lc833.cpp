#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

struct node
{
    int indice;
    string source,target;
    bool operator<(const node n)const
    {
        return indice<n.indice;
    }
};

string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
{
    int num = indices.size();
    vector<node> v;
    for(int i=0;i<num;i++)
    {
        node n;
        n.indice=indices[i];n.source=sources[i];n.target=targets[i];
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if(s.find(v[i].source,v[i].indice)==v[i].indice)
        {
            int pos=s.find(v[i].source,v[i].indice);
            int len=v[i].source.size();
            s=s.replace(pos,len,v[i].target);
            int balance=v[i].target.size()-v[i].source.size();
            for(int j=i+1;j<v.size();j++)
            {
                v[j].indice+=balance;
            }
        }
    }
    return s;
}

int main()
{
    string s="wreorttvosuidhrxvmvo";
    vector<int> v={14,12,10,5,0,18};
    vector<string> sources={"rxv","dh","ui","ttv","wreor","vo"};
    vector<string> target={"frs","c","ql","qpir","gwbeve","n"};
    cout<<findReplaceString(s,v,sources,target);
    return 0;
}