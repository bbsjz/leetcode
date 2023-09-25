#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
const int N=10;
int du[N];
int qu[N],tt,hh;
int h[N],e[N],ne[N],idx;

void add(int a,int b)
{
    e[++idx]=b;
    ne[idx]=h[a];h[a]=idx;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    for(int i=0;i<prerequisites.size();i++)
    {
        du[prerequisites[i][1]]++;
        add(prerequisites[i][0],prerequisites[i][1]);
    }
    for(int i=0;i<numCourses;i++)
    {
        if(du[i]==0) {qu[tt++]=i;}
    }
    while(hh<tt)
    {
        int f=qu[hh++];
        for(int i=h[f];i;i=ne[i])
        {
            int j=e[i];
            du[j]--;
            if(du[j]==0) qu[tt++]=j;
        }
    }
    if(tt!=numCourses) return false;
    return true;
}

int main()
{
    vector<vector<int>> prerequisites={{1,0}};
    cout<<canFinish(2,prerequisites);
    return 0;
}