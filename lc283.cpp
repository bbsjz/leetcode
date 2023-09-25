#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
//双指针的精髓在于l每次也移动，这样l左边的一定是正常的顺序，就是顺序不会发生变化
//如果l从左边找第一个是0的数，而r从右边找第一个不是0的数这样交换的话，肯定会乱序的
void moveZeroes(vector<int>& nums) {
    int l=0;
    for(int r=0;r<nums.size();r++)
    {
        if(nums[r])
        {
            swap(nums[l],nums[r]);
            l++;
        }
    }
}