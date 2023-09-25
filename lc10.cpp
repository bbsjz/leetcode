#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> f(3,vector<int>(2));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<f[i][j];
        }
    }
    return 0;
}
