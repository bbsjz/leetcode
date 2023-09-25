#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int hc[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, hr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int sum = 0;
void find(vector<vector<int>> &land, int r, int c)
{
    sum++;
    land[r][c] = 1;
    for (int i = 0; i < 8; i++)
    {
        int newc = hc[i] + c;
        int newr = r + hr[i];
        if (0 <= newc && newc < land[0].size() && 0 <= newr && newr < land.size() && land[newr][newc] == 0)
        {
            find(land, newr, newc);
        }
    }
}

vector<int> pondSizes(vector<vector<int>> &land)
{
    vector<int> v;
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            if (land[i][j] == 0)
            {
                sum = 0;
                find(land, i, j);
                v.push_back(sum);
            }
        }
    }
    sort(v.begin(),v.end());
    return v;
}

int main()
{
    vector<vector<int>> v = {
        {0, 2, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 1}};
    pondSizes(v);
    return 0;
}