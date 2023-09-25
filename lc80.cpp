#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> tmp(m+n);
    int t1=0,t2=0,t3=0;
    while(t2<m&&t3<n)
    {
        if(nums1[t2]<nums2[t3])
        tmp[t1++]=nums1[t2++];
        else tmp[t1++]=nums2[t3++];
    }
    while(t2<m) tmp[t1++]=nums1[t2++];
    while(t3<n) tmp[t1++]=nums2[t3++];
    for(int i=0;i<m+n;i++)
    {
        nums1[i]=tmp[i];
    }
}