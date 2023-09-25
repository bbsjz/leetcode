#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int course=2000+10;
vector<int> v[course];
int du[course];
set<int> st;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    for(int i=0;i<prerequisites.size();i++)
    {
        int after=prerequisites[i][0];
        int before=prerequisites[i][1];
        v[before].push_back(after);
    }
    for(int i=0;i<numCourses;i++)
    {
        for(int j:v[i])
        {
            du[j]++;
        }
        st.insert(i);
    }
    queue<int> q;
    vector<int> re;
    for(int i=0;i<numCourses;i++)
    {
        if(du[i]==0)
        {
            q.push(i);
            st.erase(i);
        }
    }
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        re.emplace_back(tmp);
        for(int i:v[tmp])
        {
            du[i]--;
        }
        for(auto it=st.begin();it!=st.end();)//不能在迭代的时候搞删除
        {
            if(du[*it]==0)
            {
                q.push(*it);
                it=st.erase(it);
            }
            else
            {
                it++;
            }
        }
    }
    if(re.size()!=numCourses)
    {
        re.clear();
    }
    return re;
}

int main()
{
    vector<vector<int>> v={{1,0},{0,1},{1,2}};
    vector<int> re=findOrder(3,v);
    for(int i=0;i<re.size();i++)
    {
        printf("%d",re[i]);
    }
    printf("\n");
    return 0;
}