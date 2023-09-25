#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    map<string,vector<string>> m;
    vector<vector<string>> re;
    for(int i=0;i<strs.size();i++)
    {
        string s=strs[i];
        sort(s.begin(),s.end());
        m[s].push_back(strs[i]);
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        re.push_back(it->second);
    }
    return re;
}
int main()
{
    vector<string> v={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> re=groupAnagrams(v);
    for(int i=0;i<re.size();i++)
    {
        for(int j=0;j<re[i].size();j++)
        {
            cout<<re[i][j]<<" ";
        }
        cout<<endl;
    }
}