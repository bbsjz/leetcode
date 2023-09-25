#include <iostream>
#include <vector>
#include <set>
using namespace std;
// int beginr, beginc;
// struct node
// {
//     int r,c;
//     const bool operator<(const node n)const
//     {
//         if(c==n.c) return r<n.r;
//         return c<n.c;
//     }
// };

// set<node> st;

int hr[4] = {-1, 1, 0, 0}, hc[4] = {0, 0, -1, 1};
// bool search(int r, int c, int far,int fac, vector<vector<char>> &grid)
// {
//     int row = grid.size(), column = grid[0].size();
//     st.insert({r,c});
//     for (int i = 0; i < 4; i++)
//     {
//         int newr = hr[i] + r;
//         int newc = hc[i] + c;
//         if ((newr != far ||newc!=fac)&& newc == beginc && newr == beginr)
//             return true;
//         if (newr < 0 || newr >= row || newc < 0 || newc >= column)
//             continue;
//         if (grid[newr][newc] == grid[r][c]  && (st.find({newr,newc})==st.end()))
//             if (search(newr, newc, r,c, grid))
//                 return true;
//     }
//     st.erase({r,c});
//     return false;
// }

// bool containsCycle(vector<vector<char>> &grid)
// {
//     int row = grid.size(), column = grid[0].size();
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//             beginr = i;
//             beginc = j;
//             st.clear();
//             if (search(i, j, i ,j, grid))
//                 return true;
//         }
//     }
//     return false;
// }

int find(int root, vector<int> &disjoint)
{
    if (root == disjoint[root])
        return root;
    return disjoint[root] = find(disjoint[root], disjoint);
}

void merge(int a, int b, vector<int> &disjoint)
{
    int fa = find(a, disjoint);
    int fb = find(b, disjoint);
    disjoint[fa] = fb;
}

// bool dfs(int r, int c, int far, int fac, vector<vector<bool>> &st, vector<vector<char>> &grid, vector<int> &disjoint)
// {
//     int row = st.size();
//     int column = st[0].size();
//     st[r][c] = true;
//     for (int i = 0; i < 4; i++)
//     {
//         int newr = hr[i] + r;
//         int newc = hc[i] + c;
//         if (newr < 0 || newr >= row || newc < 0 || newc >= column)
//             continue;
//         if ((newr != far || newc != fac) && grid[newr][newc] == grid[r][c])
//         {
//             int hasa = newr * column + newc;
//             int hasb = r * column + c;
//             if (find(hasa, disjoint) == find(hasb, disjoint))
//                 return true;
//             merge(hasa, hasb, disjoint);
//             if (st[newr][newc] == false &&
//                 dfs(newr, newc, r, c, st, grid, disjoint))
//                 return true;
//         }
//     }
//     return false;
// }

//dfs如果不允许访问已经访问过的点，那成环的时候就检查不出来
//如果允许访问已经访问过的点，那么一个是aa这种回退以为成环，加上父节点判断可以避免这个，但是会出现bcc这种
//第一次访问的时候两个c关联起来了
//答案妙在遍历的时候，只统一只在左边和上方的点，如果右下的点和他们有关系的话才加进来，不是dfs
//如果只有一棵树的话，那大家默认都是相关的，就遍历所有的边，加到并查集就可以了
//但是问题是现在这里是混杂在一起的，就是不止一个图
//所以我的做法也就是拆开成一个一个的图（每次dfs只走相同的点），每次遍历这一个图
//本质是遍历所有的边，把所有的边的两端合并到并查集里面去
bool dfs(int r, int c, int far, int fac, vector<vector<bool>> &st, vector<vector<char>> &grid, vector<int> &disjoint)
{
    int row = st.size();
    int column = st[0].size();
    st[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        int newr = hr[i] + r;
        int newc = hc[i] + c;
        if (newr < 0 || newr >= row || newc < 0 || newc >= column)
            continue;
        if ((newr != far || newc != fac) && grid[newr][newc] == grid[r][c])
        {
            int hasa = newr * column + newc;
            int hasb = r * column + c;
            if (find(hasa, disjoint) == find(hasb, disjoint))
                return true;
            merge(hasa, hasb, disjoint);
        }
        if (st[newr][newc] == false &&
            dfs(newr, newc, r, c, st, grid, disjoint))
            return true;
    }
    return false;
}

bool containsCycle(vector<vector<char>> &grid)
{
    int row = grid.size();
    int column = grid[0].size();
    vector<int> disjoint(row * column);
    for (int i = 0; i < disjoint.size(); i++)
        disjoint[i] = i;
    vector<vector<bool>> st(row, vector<bool>(column, false));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (st[i][j]==false&&dfs(i, j, i, j, st, grid, disjoint))
                return true;
        }
    }
    return false;
}

int main()
{
    // vector<vector<char>> v = {{'b', 'c', 'd', 'e', 'a', 'a', 'a'}, {'a', 'a', 'a', 'f', 'a', 'g', 'a'}, {'a', 'h', 'a', 'a', 'a', 'i', 'a'}, {'a', 'j', 'k', 'l', 'm', 'n', 'a'}, {'a', 'a', 'a', 'a', 'a', 'a', 'a'}};
    vector<vector<char>> v = {{'c', 'a'}, {'a', 'a'}, {'a', 'a'}};
    cout << containsCycle(v);
    return 0;
}