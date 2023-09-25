#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int capability=0;
        int total_zero=0;
        if(n==0)
        {
            return true;
        }
        if(flowerbed.size()==1&&flowerbed[0]==0)
        {
            if(n<=1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(flowerbed.size()==1)
        {
            return false;
        }
        int if1=false;
        if(flowerbed[0]==1)
        {
            if1=true;
        }
        for(int i=0;i<flowerbed.size();i++)
        {
           if(flowerbed[i]==1)
            {
                if(!if1)//第一个数不是1
                {
                    capability+=total_zero/2;
                    if1=true;
                }
                else
                {
                    capability+=(total_zero-1)/2;
                }
                total_zero=0;
            }
            else if (flowerbed[i]==0)
            {
                total_zero+=1;
            } 
        }
        if(if1==true)
        {
            capability+=total_zero/2;
        }
        else
        {
            capability+=(total_zero+1)/2;
        }
        if(capability>=n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    vector<int> a={0,0,0};
    cout<<s.canPlaceFlowers(a,2);
    return 0;
}