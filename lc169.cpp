#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate=nums[0];
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(count==0) candidate=nums[i];
        if(nums[i]==candidate) count++;
        else count--;
    }
    return candidate;
}