#include <iostream>
#include <vector>
#include <map>
using namespace std;
int maxL = 0;

void move(int &x, int &y, int direction, int movel, map<int, vector<int>>& mapx, map<int, vector<int>>& mapy)
{
    if (direction == 0)
    {
        int realmove = y + movel;
        for (int i = 0; i < mapx[x].size(); i++)
        {
            if (mapx[x][i] > y && mapx[x][i] <= y + movel)
            {
                realmove = min(realmove, mapx[x][i] - 1);
            }
        }
        y = realmove;
    }
    else if (direction == 2)
    {
        int realmove = y - movel;
        for (int i = 0; i < mapx[x].size(); i++)
        {
            if (mapx[x][i] < y && mapx[x][i] >= y - movel)
            {
                realmove = max(realmove, mapx[x][i] + 1);
            }
        }
        y = realmove;
    }
    else if (direction == 1)
    {
        int realmove = x - movel;
        for (int i = 0; i < mapy[y].size(); i++)
        {
            if (mapy[y][i] < x && mapy[y][i] >= x - movel)
            {
                realmove = max(realmove, mapy[y][i] + 1);
            }
        }
        x = realmove;
    }
    else if (direction == 3)
    {
        int realmove = x + movel;
        for (int i = 0; i < mapy[y].size(); i++)
        {
            if (mapy[y][i] > x && mapy[y][i] <= x + movel)
            {
                realmove = min(realmove, mapy[y][i] - 1);
            }
        }
        x = realmove;
    }
    maxL = max(maxL, x * x + y * y);
}

void rotate(int commands, int &direction)
{
    if (commands == -2) // left
        direction = (direction + 1) % 4;
    if (commands == -1) // right
        direction = (direction - 1 + 4) % 4;
}

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    // for (int i = 0; i < obstacles.size(); i++)
    // {
    //     if (obstacles[i][0] == 0 && obstacles[i][1] == 0)
    //         return 0;
    // }
    map<int, vector<int>> mapx;
    map<int, vector<int>> mapy;
    for (int i = 0; i < obstacles.size(); i++)
    {
        mapx[obstacles[i][0]].push_back(obstacles[i][1]);
        mapy[obstacles[i][1]].push_back(obstacles[i][0]);
    }
    int x = 0, y = 0;
    int direction = 0; // 0-shang,1-zuo,2-xia,3-you
    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i] == -1 || commands[i] == -2)
        {
            rotate(commands[i], direction);
        }
        else
            move(x, y, direction, commands[i], mapx, mapy);
    }
    return maxL;
}

int main()
{
    vector<int> com = {-2, -1, -2, 3, 7};
    vector<vector<int>> ob = {{1, -3}, {2, -3}, {4, 0}, {-2, 5}, {-5, 2}, {0, 0}, {4, -4}, {-2, -5}, {-1, -2}, {0, 2}};
    cout << robotSim(com, ob);
    return 0;
}