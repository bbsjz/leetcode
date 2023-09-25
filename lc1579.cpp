#include <iostream>
#include <vector>
#include<set>
#include <queue>
using namespace std;

struct node
{
    int a, b, type, idx;
    const bool operator<(const node n) const
    {
        if (type == n.type)
        {
            if (a == n.a)
                return b < n.b;
            return a < n.a;
        }
        return type < n.type;
    }
};

class Disjoint
{
    static const int N = 1e5 + 10;
    int disjoint[N];
    int n;

public:
    Disjoint(int n)
    {
        this->n = n;
        for (int i = 0; i <= n; i++)
        {
            disjoint[i] = i;
        }
    }

    int find(int root)
    {
        if (disjoint[root] == root)
            return root;
        return disjoint[root] = find(disjoint[root]);
    }

    bool findAndUnion(int a, int b)
    {
        int fa = find(a);
        int fb = find(b);
        if (fa == fb)
            return false;
        disjoint[fa] = fb;
        return true;
    }
};

int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{
    priority_queue<node, vector<node>> pq,pq2;
    for (int i = 0; i < edges.size(); i++)
    {
        node no;
        no.a = edges[i][2];
        no.b = edges[i][1];
        no.type = edges[i][0];
        no.idx = i;
        pq.push(no);
        pq2.push(no);
    }
    set<int> length;
    Disjoint disAlice(n), disBob(n);
    // Alice 3 1
    int cnt = 0;
    while (pq.size())
    {
        node no = pq.top();
        pq.pop();
        if (no.type == 2)
            continue;
        int a = no.a;
        int b = no.b;
        if (disAlice.findAndUnion(a, b))
        {
            cnt++;
            length.insert(no.idx);
        }
        if (cnt == n - 1)
            break;
    }
    if (cnt < n - 1)
        return -1;
    // bob 3 2
    cnt = 0;
    while (pq2.size())
    {
        node no = pq2.top();
        pq2.pop();
        if (no.type == 1)
            continue;
        int a = no.a;
        int b = no.b;
        if (disBob.findAndUnion(a, b))
        {
            cnt++;
            length.insert(no.idx);
        }
        if (cnt == n - 1)
            break;
    }
    if (cnt < n - 1)
        return -1;
    return edges.size()-length.size();
}

int main()
{
    vector<vector<int>> v={{3,1,2}};
    cout<<maxNumEdgesToRemove(2,v);
    return 0;
}