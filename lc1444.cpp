#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;
int mod=1e9+7;
struct node
{
    int lx, ly, rx, ry, k;
    bool operator==(const node n) const
    {
        bool t1 = lx == n.lx;
        bool t2 = ly == n.ly;
        bool t3 = rx == n.rx;
        bool t4 = ry == n.ry;
        bool t5 = k == n.k;
        return t1 && t2 && t3 && t4 && t5;
    }
};
struct node1
{
    int lx, ly, rx, ry;
    bool operator==(const node1 n) const
    {
        bool t1 = lx == n.lx;
        bool t2 = ly == n.ly;
        bool t3 = rx == n.rx;
        bool t4 = ry == n.ry;
        return t1 && t2 && t3 && t4;
    }
};
struct hash_node
{
    size_t operator()(const node n) const
    {
        return hash<int>()(n.lx) ^ hash<int>()(n.ly) ^ hash<int>()(n.rx) ^ hash<int>()(n.ry);
    }
};

struct hash_node1
{
    size_t operator()(const node1 n) const
    {
        return hash<int>()(n.lx) ^ hash<int>()(n.ly) ^ hash<int>()(n.rx) ^ hash<int>()(n.ry);
    }
};

unordered_map<node, int, hash_node> ha;
unordered_map<node1 ,bool, hash_node1> OK;

bool ifOK(int lx, int ly, int rx, int ry, vector<string> &pizza)
{
    if(OK.count({lx,ly,rx,ry})!=0) return OK[{lx,ly,rx,ry}];
    for (int row = lx; row <= rx; row++)
    {
        for (int column = ly; column <= ry; column++)
        {
            if (pizza[row][column] == 'A')
                {OK[{lx,ly,rx,ry}]=true;
                return true;}
        }
    }
    OK[{lx,ly,rx,ry}]=false;
    return false;
}

int dongtaiguihua(int lx, int ly, int rx, int ry, int left, vector<string> &pizza)
{
    if (left == 0&&ifOK(lx,ly,rx,ry,pizza))
        return 1;
    else if (ha.count({lx,ly,rx,ry,left}) != 0)
        return ha[{lx,ly,rx,ry,left}];
    int sum=0;
    for (int row = lx + 1; row <= rx; row++)
    {
        if (ifOK(lx, ly, row - 1, ry, pizza) && ifOK(row, ly, rx, ry, pizza))
            sum += dongtaiguihua(row, ly, rx, ry, left - 1, pizza);
            sum=sum%mod;
    }
    for (int column = ly + 1; column <= ry; column++)
    {
        if (ifOK(lx, ly, rx, column - 1, pizza) && ifOK(lx, column, rx, ry, pizza))
            sum += dongtaiguihua(lx, column, rx, ry, left - 1, pizza);
            sum=sum%mod;
    }
    ha[{lx,ly,rx,ry,left}]=sum;
    return sum;
}

int ways(vector<string> &pizza, int k)
{
    int row = pizza.size();
    int column = pizza[0].size();
    return dongtaiguihua(0, 0, row - 1, column - 1, k - 1, pizza);
}

int main()
{
    vector<string> v = {"...", "...", "..."};
    cout << ways(v, 1);
    return 0;
}