#include <queue>
#include <algorithm>
#include<iostream>
using namespace std;
struct building
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[2] < b[2];
    }
};
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
class Solution
{

    priority_queue<vector<int>, vector<vector<int>>, building> build; //优先队列记录建筑物
    vector<vector<int>> skyLine;
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        int length = buildings.size();
        sort(buildings.begin(), buildings.end(), cmp);
        vector<int> q; //记录所有的关键点x，按横坐标从小到大排序
        int where = 0;                //现在加入到第几个建筑物了
        vector<int> last = {-1, -1};
        for (int i = 0; i < length * 2; i += 2)
        {
            q.push_back(buildings[i / 2][0]);
            q.push_back(buildings[i / 2][1]);
        }
        sort(q.begin(), q.end());
        for (int i = 0; i < length * 2; i++)
        {
            while (where < length && buildings[where][0] <= q[i] && buildings[where][1] > q[i]) //满足这个条件则说明当前指针指向的建筑物包含正在遍历的这个点，加入优先队列
            {
                build.push(buildings[where]);
                where++;
            }
            vector<int> tmp;
            if(!build.empty())
            {
                tmp=build.top();
            }          
            while (!(build.empty()) && !(tmp[0] <= q[i] && tmp[1] > q[i])) //如果优先队列不为空，且第一个元素不满足包含当前遍历的这个点，则删去这个建筑
            {
                build.pop();
                if(!build.empty())
                {
                    tmp=build.top();
                }
            }
            vector<int> now;
            if (!build.empty())
            {
                now = {q[i], tmp[2]};
               
            }
            else
            {
                now={q[i],0};
            }
            if(now[1]==last[1])
            {
                continue;
            }
            else
            {
                skyLine.push_back(now);
                last=now;
            }
        }
        return skyLine;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> sky={{1,2,1},{1,2,2},{1,2,3}};
    vector<vector<int>> re=solution.getSkyline(sky);
    for (int i = 0; i < re.size(); i++)
    {
        for(int j=0; j<re[i].size();j++)
        {
            cout<<re[i][j]<<" ";
        }
        cout<<"  ";
    }
    
}