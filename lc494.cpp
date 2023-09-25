#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int cnt=0;
//如果用dp的话，那些更大的元素成为负数的情况不用考虑，只需要小的元素这边可以凑出neg就可以了，而且全为+
//因为这些元素全为+的话，剩下的元素全取-，这样就可以凑出来，每次dp考虑选中当前元素或者不选，选中表示当前元素被标记为+
void traceback(vector<int>& nums, int target, int pos,int sum)
{
    if(pos==nums.size())
    {
        if(target==sum) cnt++;
        return;
    } 
    traceback(nums,target,pos+1,sum+nums[pos]);
    traceback(nums,target,pos+1,sum-nums[pos]);
}

int findTargetSumWays(vector<int>& nums, int target) {
    traceback(nums,target,0,0);
    return cnt;
}