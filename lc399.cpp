#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<int> node;
vector<double> weight;
unordered_map<string, int> mp;
//查询到谁，就会把谁和它路径上所有的点都进行压缩
//但是和这个东西不在同一条路径上的点在这次查询中不会被压缩
//在压缩的途中进行查找
int find(int son)
{
    int father;
    if(node[son]==son)
        return son;
    father=find(node[son]);
    weight[son]=weight[son]*weight[node[son]];
    node[son]=father;
    return father;
}

void init(vector<vector<string>> &equations, vector<double> &values)
{
    int idx = 0;
    int root=0,son=0;
    for (int i = 0; i < equations.size(); i++)
    {
        if (mp.count(equations[i][0]) == 0)
        {
            mp[equations[i][0]] = idx;
            node.push_back(idx);
            weight.push_back(1.0);
            root=idx++;
        }
        else
            root=find(mp[equations[i][0]]);
        if (mp.count(equations[i][1]) == 0)
        {
            mp[equations[i][1]] = idx;
            node.push_back(idx);
            weight.push_back(1.0);
            son=idx++;
        }
        else son=find(mp[equations[i][1]]);
        node[son] = root;
        weight[son] = 
        weight[mp[equations[i][0]]]/weight[mp[equations[i][1]]]*values[i];
    }
}

double query(vector<string> &queries)
{
    if(mp.count(queries[0])==0||mp.count(queries[1])==0) return -1;
    int root0=find(mp[queries[0]]);
    int root1=find(mp[queries[1]]);
    if(root0==root1) return weight[mp[queries[1]]]/weight[mp[queries[0]]];
    else return -1;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    vector<double> re;
    init(equations,values);
    for(vector<string> v:queries)
    {
        re.push_back(query(v));
    }
    return re;
}

int main()
{
    vector<vector<string>> equations={{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values={1.5,2.5,5.0};
    vector<vector<string>> queries={{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    calcEquation(equations,values,queries);
    return 0;
}