#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
int hr[4]={-1,1,0,0},hc[4]={0,0,-1,1};

//只要再多放一个参数就会爆栈，但实际上不需要那个参数
void mark(vector<vector<char>>& grid,int r,int c)
{
    int row=grid.size(),column=grid[0].size();
    grid[r][c]='0';
    for(int i=0;i<4;i++)
    {
        int newc=hc[i]+c;
        int newr=hr[i]+r;
        if(0<=newr&&newr<row&&0<=newc&&newc<column&&grid[newr][newc]=='1')
        {
            mark(grid,newr,newc);
        }
    }
}   

int numIslands(vector<vector<char>>& grid) {
    int sign=0;
    int row=grid.size(),column=grid[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(grid[i][j]=='1')
            {
                sign++;
                mark(grid,i,j);
            }
        }
    }
    return sign;
}