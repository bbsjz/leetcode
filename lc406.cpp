#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a,vector<int> b)
{
    return a[1]<b[1];
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(),cmp);
    for(int i=0;i<people.size();i++)
    {
        int count=0;
        int pos=0;
        for(int j=0;j<i;j++)
        {
            if(people[j][0]>=people[i][0]) count++;
            if(count>people[i][1]) {pos=j;break;}
        }
        if(count>people[i][1])
        {
            vector<int> tmp=people[i];
            people.erase(people.begin()+i);
            people.insert(people.begin()+pos,tmp);
        }
    }
    return people;
}

int main()
{
    vector<vector<int>> p={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    reconstructQueue(p);
    return 0;
}