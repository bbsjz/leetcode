#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 3e4 + 10;
int h[N], e[2 * N], ne[2 * N], idx;
vector<int> ans;
void add(int a, int b)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

void dfs(int node, int fa, vector<int> &dp, vector<int> &sz)
{
    for (int i = h[node]; i; i = ne[i])
    {
        int b = e[i];
        if (b != fa)
        {
            dfs(b, node, dp, sz);
            sz[node] += sz[b];
            dp[node] += (dp[b] + sz[b]);
        }
    }
    sz[node] += 1;
}

void changeroot(int origin, int newroot, vector<int> &dp, vector<int> &sz)
{
    dp[origin] -= (dp[newroot] + sz[newroot]);
    sz[origin] -= sz[newroot];
    dp[newroot] += (dp[origin] + sz[origin]);
    sz[newroot] += sz[origin];
}

void dfs2(int root, int fa, vector<int> dp, vector<int> sz)
{
    // 妙啊，每次进入的时候是固定的，所以每次都进入的时候相等就可以了
    ans[root] = dp[root];
    for (int i = h[root]; i; i = ne[i])
    {
        int b = e[i];
        if (b != fa)
        {
            changeroot(root, b, dp, sz);
            dfs2(b, root, dp, sz);
            changeroot(b, root, dp, sz);
        }
    }
}
vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        add(a, b);
        add(b, a);
    }
    ans.resize(n);
    vector<int> dp(n, 0);
    vector<int> sz(n, 0);
    dfs(0, 0, dp, sz);
    dfs2(0, 0, dp, sz);
    return ans;
}

int main()
{
    vector<vector<int>> v = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    sumOfDistancesInTree(6, v);
    return 0;
}