#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<int,vector<int>> pq;
    for(int i:gifts)
        pq.push(i);
    for(int i=0;i<k;i++)
    {
        int max_gift=pq.top();
        pq.pop();
        pq.push(sqrt(max_gift));
    }
    long long int sum=0;
    while(pq.size())
    {
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}