#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int halveArray(vector<int> &nums)
{
    priority_queue<double,vector<double>> p;
    int num=nums.size();
    double sum=0;
    for(int i=0;i<num;i++)
    {
        sum+=nums[i];
        p.push(nums[i]);
    }
    double half=sum/2;
    int cnt=0;
    while(sum>half)
    {
        double maxn=p.top();
        p.pop();
        p.push(maxn/2);
        sum-=maxn/2;
        cnt++;
    }
    return cnt;
}