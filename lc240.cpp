#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;
//在两个维度上搜索，每次只能排除右边的元素一定大于我
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int pos=matrix[0].size()-1;
    for (int i = 0; i < matrix.size(); i++)
    {
        int l = 0, r = pos;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (matrix[i][mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(r<0) return false;
        else if(matrix[i][r]==target) return true;
        pos=r;
    }
    return false;
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    cout << searchMatrix(v, 19);
    return 0;
}