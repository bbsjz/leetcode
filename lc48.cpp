#include<iostream>
#include<vector>
using namespace std;

void rr(vector<vector<int>>& m,int row,int n)
{
    if(row>=n/2)
    {
        return;
    }
    else
    {
        for(int i=row;i<n-row-1;i++)
        {
            int t=m[row][i];
            m[row][i]=m[n-i-1][row];
            m[n-i-1][row]=m[n-row-1][n-i-1];
            m[n-row-1][n-i-1]=m[i][n-row-1];
            m[i][n-row-1]=t;
        }
        rr(m,row+1,n);
    }
}
void rotate(vector<vector<int>>& matrix) 
{
    rr(matrix,0,matrix.size());   
}

int main()
{
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    rotate(v);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}