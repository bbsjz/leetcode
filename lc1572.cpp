#include <iostream>
#include <vector>
using namespace std;
int diagonalSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int begin = i, end = n - i - 1;
        sum += mat[i][begin];
        if (begin != end)
        {
            sum += mat[i][end];
        }
    }
    return sum;
}