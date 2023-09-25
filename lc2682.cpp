#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> circularGameLosers(int n, int k)
{
    set<int> who;
    who.insert(1);
    int current = 1;
    int ne = k;
    int next_who = (current + ne) % n;
    if (next_who == 0)
        next_who = n;
    while (who.count(next_who) == 0)
    {
        who.insert(next_who);
        current = next_who;
        ne += k;
        next_who = (current + ne) % n;
        if (next_who == 0)
            next_who = n;
    }
    vector<int> re;
    for(int i=1;i<=n;i++)
    {
        if(who.count(i)==0) re.push_back(i);
    }
    return re;
}

int main()
{
    circularGameLosers(5,2);
    return 0;
}