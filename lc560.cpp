#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
//是直接去找对应的前缀在不在表里面，如果可以找到累加的前缀使得pre[i]-pre[j-1]=k
//那么实际上直接减就可以了，如果pre[i]-k在表里面，表会记录这个数量
//也就是前缀和中间有多少个不同的前缀和可以刚好凑出pre[i]-k的这个值，那么这些能凑出来的前缀和被现在的总前缀和一减
//就都能得到k，所以前面有多少前缀和的情况，这个地方就增加多少种可能凑出k的方案
//这种方案的正确性是因为任何一个区间都可以被前缀和的区间相减所表示出来，所以情况是完全的，任何一个有效的区间都会被列举出来的
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    map.insert({0,1});
    int presum=0;
    int cnt=0;
    for(int i=0;i<nums.size();i++)
    {
        presum+=nums[i];
        if(map.count(presum-k)!=0)
        {
            cnt+=map[presum-k];
        }
        map[presum]++;
    }
    return cnt;
}

int main()
{
    vector<int> v={1,1,1};
    cout<<subarraySum(v,2);
    return 0;
}