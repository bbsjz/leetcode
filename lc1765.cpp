#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int hr[4] = {-1, 1, 0, 0};
int hc[4] = {0, 0, -1, 1};
vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
{
    queue<pair<int, int>> q;
    int row = isWater.size(), column = isWater[0].size();
    vector<vector<int>> re(row, vector<int>(column, -1));
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < column; c++)
        {
            if (isWater[r][c] == 1)
            {
                q.push({r * row + c, 0});
            }
        }
    }
    while (q.size())
    {
        pair<int, int> pii = q.front();
        q.pop();
        int r = pii.first / row, c = pii.first % row;
        if(re[r][c]!=-1) continue;
        int step = pii.second;
        re[r][c] = step;
        for (int i = 0; i < 4; i++)
        {
            int newr = hr[i] + r;
            int newc = hc[i] + c;
            if (0 <= newc && newc < column && 0 <= newr && newr < row && re[newr][newc] == -1)
            {
                q.push({newr * row + newc, step + 1});
            }
        }
    }
    return re;
}