#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int hammingDistance(int x, int y) {
    int re=x^y;
    int count=0;
    while(re)
    {
        if(re&1) count++;
        re=re>>1;
    }
    return count;
}

int main()
{
    cout<<hammingDistance(1,4);
    return 0;
}