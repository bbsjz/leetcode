#include<iostream>
#include<vector>
using namespace std;
const int N=1010;
int q[N];
int pivotInteger(int n) {
    for(int i=1;i<=n;i++)
    {
        q[i]=i;
        q[i]+=q[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        if(q[n]-q[i-1]==q[i]-q[0]) return i;
    }
    return -1;
}

int main()
{
    cout<<pivotInteger(8);
    return 0;
}