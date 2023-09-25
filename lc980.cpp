#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// int traceback(vector<vector<int>> &grid,vector<vector<int>>&memory ,int r,int c, int num)
// {
//     if(memory[r][c]!=-1) return memory[r][c];
//     int sum=0;
//     if(r==endr&&c==endc)
//     {
//         if(num==n+1) return 1;
//         else return 0;
//     }
//     for(int i=0;i<4;i++)
//     {
//         int newr=r+hr[i],newc=c+hc[i];
//         if(newr>=0&&newr<grid.size()&&newc>=0&&newc<grid[0].size()&&(grid[newr][newc]==0||grid[newr][newc]==2))
//         {
//             if(grid[newr][newc]==0)
//             grid[newr][newc]=-1;
//             sum+=traceback(grid,memory,newr,newc,num+1);
//             if(grid[newr][newc]==-1)
//             grid[newr][newc]=0;
//         }
//     }
//     memory[r][c]=sum;
//     return sum;
// }
// int traceback(vector<vector<int>> &grid,int r,int c, int num)
// {
//     int sum=0;
//     if(r==endr&&c==endc)
//     {
//         if(num==n+1) return 1;
//         else return 0;
//     }
//     for(int i=0;i<4;i++)
//     {
//         int newr=r+hr[i],newc=c+hc[i];
//         if(newr>=0&&newr<grid.size()&&newc>=0&&newc<grid[0].size()&&(grid[newr][newc]==0||grid[newr][newc]==2))
//         {
//             if(grid[newr][newc]==0)
//             grid[newr][newc]=-1;
//             sum+=traceback(grid,newr,newc,num+1);
//             if(grid[newr][newc]==-1)
//             grid[newr][newc]=0;
//         }
//     }
//     return sum;
// }

int traceback(vector<vector<int>> &grid,int r,int c, int left)
{
    if(r<0||r>=grid.size()||c<0||c>=grid[0].size()||grid[r][c]<0) return 0;
    if(grid[r][c]==2) return left==0;
    grid[r][c]=-1;
    int sum= traceback(grid,r-1,c,left-1)+traceback(grid,r,c-1,left-1)+
    traceback(grid,r+1,c,left-1)+traceback(grid,r,c+1,left-1);
    grid[r][c]=0;
    return sum;
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    vector<vector<int>> memory(grid.size(),vector<int>(grid[0].size(),-1));
    int begin,end;
    int n=0;
    for(int r=0;r<grid.size();r++)
    {
        for(int c=0;c<grid[r].size();c++)
        {
            if(grid[r][c]==0) n++;
            if(grid[r][c]==1)
            {
                begin=r;end=c;
            }
        }
    }
    return traceback(grid,begin,end,n+1);
}

int main()
{
    vector<vector<int>> v={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout<<uniquePathsIII(v);
    return 0;
}