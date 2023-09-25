#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int maxProfit(vector<int>& prices) {
    vector<int> maxprice(prices.size(),0);
    maxprice[prices.size()-1]=prices[prices.size()-1];
    for(int i=prices.size()-2;i>=0;i--)
    {
        maxprice[i]=max(prices[i],maxprice[i+1]);
    }
    int maxpro=0;
    for(int i=0;i<prices.size()-1;i++)
    {
        maxpro=max(maxpro,maxprice[i+1]-prices[i]);
    }
    return maxpro;
}