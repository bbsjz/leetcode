#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
set<vector<int>> re;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> re;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i <= n - 4; i++)
    {
        // 我靠，不能这样写，我以为是两者相加肯定会变得更大，所以第一个数大于了，后面的数相加只会更大
        // 但是就算后面的数更大比如-5，-4，两者相加起来也可能更小啊
        // 所以剪枝不是你这么剪的
        //  if (nums[i] > target)
        //      break;
        // 如果按照最小都会超过target，那么此时确实就是往后枚举的四个数之和会比现在的最小值还要大了，那就没必要继续枚举了
        if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            break;
        // 如果按照最大的来算，最大的都不满足，那么第一个数（也就是当前我们在考虑的这个数）选小了，应该要更大才可以
        if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
            continue;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j <= n - 3; j++)
        {
            // if (nums[i] + nums[j] > target)
            //     break;
            if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                break;
            if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                continue;
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int tar = target - nums[i] - nums[j];
            for (int k = j + 1, x = n - 1; k < x; )
            {
                while (x > k && nums[k] + nums[x] > tar)
                    x--;
                if (x > k && nums[k] + nums[x] == tar)
                {
                    while (x > k && nums[k] + nums[x] == tar)
                    {
                        re.push_back(nums[i]);
                        re.push_back(nums[j]);
                        re.push_back(nums[k]);
                        re.push_back(nums[x]);
                        ans.push_back(re);
                        re.clear();
                        k++;
                        x--;
                        while (x > k && nums[k] == nums[k - 1])
                            k++;
                        while (x > k && nums[x] == nums[x + 1])
                            x--;
                    }
                }
                else k++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, -2, -5, -4, -3, 3, 3, 5};
    vector<vector<int>> v;
    v = fourSum(nums, -11);
    return 0;
}