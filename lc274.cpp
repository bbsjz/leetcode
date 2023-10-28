#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int hIndex(vector<int> &citations)
{
    sort(citations.begin(),citations.end());
    int r=citations.size();
    // 边界问题
    int l=1;
    int h=0;
    while(l<=r)
    {
        int mid=r+l>>1;
        if(citations[citations.size()-mid]>mid) {l=mid+1;h=max(h,mid);}
        else if(citations[citations.size()-mid]<mid) r=mid-1;
        //因为已经排过序了，所以此时如果相等肯定是最大的h，不存在还有更大的h的情况
        else return mid;
    }
    return h;
}

int main()
{
    vector<int> citations={3,0,6,1,5};
    cout<<hIndex(citations);
    return 0;
}