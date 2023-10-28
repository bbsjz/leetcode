#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{
    int mod = 1e9 + 7;
    horizontalCuts.push_back(h);
    verticalCuts.push_back(w);
    horizontalCuts.insert(horizontalCuts.begin(),0);
    verticalCuts.insert(verticalCuts.begin(),0);
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int maxh=0,maxw=0;
    for(int i=1;i<horizontalCuts.size();i++)
        maxh=max(maxh,horizontalCuts[i]-horizontalCuts[i-1]);
    for(int i=1;i<verticalCuts.size();i++)
        maxw=max(maxw,verticalCuts[i]-verticalCuts[i-1]);
    return ((long long int)maxh*maxw)%mod;
}

int main()
{
    vector<int> h = {1, 2, 4};
    vector<int> w = {1, 3};
    cout << maxArea(5, 4, h, w);
    return 0;
}