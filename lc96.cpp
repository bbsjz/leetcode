#include<iostream>
#include<vector>
using namespace std;
int numTrees(int n) {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    for(int i=2;i<=n;i++)
    {
        int gn=0;
        for(int j=1;j<=i;j++)
        {
            int left=j-1,right=i-j;
            gn+=v[left]*v[right];
        }
        v.push_back(gn);
    }
    return v[n];
}

int main()
{
    cout<<numTrees(3);
    return 0;
}