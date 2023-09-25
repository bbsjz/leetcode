#include<iostream>
#include<vector>
using namespace std;
// int climbStairs(int n) 
// {
//     if(n==1)
//     {
//         return 1;
//     }
//     else if(n==2)
//     {
//         return 2;
//     }
//     else
//     {
//         return climbStairs(n-1)+climbStairs(n-2);
//     }
// }

int climbStairs(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    vector<int> v=vector<int>(n+1);
    v[1]=1;
    v[2]=2;
    for(int i=3;i<n+1;i++)
    {
        v[i]=v[i-1]+v[i-2];
    }
    return v[n];
}

int main()
{
    cout<<climbStairs(44);
    return 0;
}
