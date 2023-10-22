#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 1e5 + 10;
const int M = 4e5 + 10;
// h存的是节点i的边从哪条边开始，存的是边的边号，e存的是某条边连接的是哪个顶点，从这个链表的顶点->被指向的顶点，ne存的是这条边之后的下一条边哪条边
int h[N], e[M], ne[M], idx;
bool st[N];
vector<int> link;
int stk;
//思考如何加入一条新的边，就可以记住
void add(int a, int b)
{
    e[++idx] = b;   // 现在有一条新的边，这条边指向的顶点是b
    ne[idx] = h[a]; // 这条新的边的下一条边应该和a这个顶点的其他边连上，因此让这条边的下一条边指向这个顶点的第一条边
    h[a] = idx;     // 现在这条边连接了原本的下一条边，所以这条边现在变成了a节点打头的第一条边
}

void dfs(int node)
{
    stk++;
    st[node]=true;
    for(int i=h[node];i;i=ne[i])
    {
        int son=e[i];
        if(!st[son])
        {
            dfs(son);
        }
    }
}

long long countPairs(int n, vector<vector<int>> &edges)
{
    for (vector<int> v : edges)
    {
        add(v[0], v[1]);
        add(v[1], v[0]);
    }
    for (int i = 0; i < n; i++)
    {
        if (!st[i])
        {
            stk=0;
            dfs(i);
            link.push_back(stk);
        }
    }
    vector<int> link_cp=link;
    for(int i=1;i<link_cp.size();i++)
    {
        link_cp[i]+=link_cp[i-1];
    }
    long long int sum=0;
    for(int i=0;i<link_cp.size();i++)
    {
        sum+=(long long int)link[i]*(link_cp[link_cp.size()-1]-link_cp[i]);
    }
    return sum;
}