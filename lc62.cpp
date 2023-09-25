#include<iostream>
using namespace std;

// int traceback(int m,int n,int sum)
// {
//     int begin=sum;
//     if(m==1||n==1)
//     {
//         return 1;
//     }
//     else
//     {
//         sum+=traceback(m-1,n,begin);
//         sum+=traceback(m,n-1,begin);
//         return sum;
//     }
// }
// int uniquePaths(int m, int n) 
// {
//    return traceback(m,n,0);
// }

// long long int A(int n,int m)
// {
//       long long int sum=1;
//       for(int i=0;i<m;i++)
//       {
//             sum*=(n-i);
//       }
//       return sum;
// }

// int C(int n,int m)
// {
//       int tm=min(m,n-m);
//       long long int fenzi=A(n,tm);
//       long long int fenmu=A(tm,tm);
//       return fenzi/fenmu;
// }

int C(int a,int b)
{
    int ans=1;//为什么改成long就可以了?????
    for(int x=a-b+1,y=1;y<b+1;x++,y++)
    {
        ans=ans*x/y;
    }
    return ans;
}

int uniquePaths(int m, int n) 
{
   int tm=m-1;
   int tn=m+n-2;
   return C(tn,tm);
}

int main()
{
    cout<<uniquePaths(23,12);
    return 0;
}