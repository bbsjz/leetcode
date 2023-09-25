#include<iostream>
#include<vector>
using namespace std;

//只想到了按行去计算，却没有想到按列去计算，实际上，按列计算就可以dp，而且非常快

int max(int a,int b)
{
    return a<b?b:a;
}

int min(int a,int b)
{
    return a<b?a:b;
}

// int trap(vector<int>& height) 
// {
//     int l=height.size();
//     int m=0;
//     for(int i=0;i<l;i++)
//     {
//         m=max(m,height[i]);
//     }
//     int *dp=new int[m+1];
//     for(int i=1;i<m+1;i++)
//     {
//         dp[i]=0;
//     }
//     for(int i=1;i<m+1;i++)//for height i,find the first i and the last i,and between are the volumn
//     {
//         int left=-1;
//         int fsum=0;
//         for(int j=0;j<l;j++)
//         {
//             if(left==-1&&height[j]>=i)
//             {
//                 left=j;
//             }
//             else if(left!=-1&&height[j]<i)
//             {
//                 fsum++;
//             }
//             else if(left!=-1&&height[j]>=i&&fsum!=0)
//             {
//                 dp[i]+=fsum;
//                 fsum=0;
//             }
//         }
//     }
//     int sum=0;
//     for(int i=1;i<m+1;i++)
//     {
//         sum+=dp[i];
//     }
//     return sum;
// }

//从中间往两边找最高的柱子，然后减去当前位置柱子的高度，就是当前列能够容纳的水
int trap(vector<int>& height) 
{
    int l=height.size();
    int *left=new int[l];
    int *right=new int[l];
    left[0]=height[0];
    right[l-1]=height[l-1];
    for(int i=1;i<l;i++)
    {
        left[i]=max(height[i],left[i-1]);
    }
    for(int i=l-2;i>=0;i--)
    {
        right[i]=max(height[i],right[i+1]);
    }
    int sum=0;
    for(int i=0;i<l;i++)
    {
        sum+=min(right[i],left[i])-height[i];
    }
    return sum;
}

int main()
{
    vector<int> h={4,2,0,3,2,5};
    cout<<trap(h);
    return 0;
}