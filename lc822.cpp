#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct node
{
    int front, back;
    const bool operator<(const node n) const
    {
        if (back == n.back)
            return front < n.front;
        return back < n.back;
    }
};

int flipgame(vector<int> &fronts, vector<int> &backs)
{
    int n = fronts.size();
    set<int> bukeneng;
    set<int> keneng;
    for (int i = 0; i < n; i++)
        if (fronts[i] == backs[i])
            bukeneng.insert(fronts[i]);
    for (int i = 0; i < n; i++)
    {
        if(bukeneng.count(fronts[i])==0) keneng.insert(fronts[i]);
        if(bukeneng.count(backs[i])==0) keneng.insert(backs[i]);
    }
    if(keneng.size()) return (*keneng.begin());
    else return 0;
}