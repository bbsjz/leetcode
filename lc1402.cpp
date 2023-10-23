#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// int maxSatisfaction(vector<int> &satisfaction)
// {   
//     sort(satisfaction.begin(),satisfaction.end());
//     vector<int> cp=satisfaction;
//     for(int i=1;i<cp.size();i++)
//     {
//         cp[i]+=cp[i-1];
//     }
//     int i=0;
//     for(;i<cp.size();i++)
//     {
//         if(satisfaction[i]+cp[cp.size()-1]-cp[i]>=0) break;
//     }
//     int sum=0;
//     for(int j=i;j<satisfaction.size();j++)
//     {
//         sum+=(j-i+1)*satisfaction[j];
//     }
//     return sum;
// }
int maxSatisfaction(vector<int> &satisfaction)
{   
    sort(satisfaction.begin(),satisfaction.end());
    int num=satisfaction.size();
    vector<vector<int>> dp(num,vector<int>(num,0));
    
}