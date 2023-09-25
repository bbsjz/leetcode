#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int r, c, value;
    const bool operator<(const node n)const
    {
        if(value==n.value)
        {
            if(r==n.r) return c<n.c;
            else return r<n.r;
        }
        return value>n.value;
    }
};

// 1 -> 2 <- 3 xia 4 shang
//因为我永远都会优先的去扩展那些为0的路径，优先走为0的路径
int minCost(vector<vector<int>> &grid)
{
    int row = grid.size(), column = grid[0].size();
    vector<vector<bool>> fangwen(row, vector<bool>(column, false));
    int hr[4] = {0, 0, 1, -1};
    int hc[4] = {1, -1, 0, 0};
    priority_queue<node,vector<node>> pq;
    pq.push({0,0,0});
    while(pq.size())
    {
        node no=pq.top();
        pq.pop();
        if(fangwen[no.r][no.c]) continue;
        if(no.r==row-1&&no.c==column-1) return no.value;
        fangwen[no.r][no.c]=true;
        for(int i=0;i<4;i++)
        {
            int newr=no.r+hr[i],newc=no.c+hc[i];
            if(newr>=0&&newr<row&&newc>=0&&newc<column&&!fangwen[newr][newc])
            {
                pq.push({newr,newc,no.value+(grid[no.r][no.c]!=i+1)});
            }
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> v={{1,1,3},{3,2,2},{1,1,4}};
    cout<<minCost(v);
    return 0;
}