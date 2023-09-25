#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checknum(char c)
{
    if('0'<=c&&c<='9') return true;
    else return false;
}

int maximumValue(vector<string>& strs) {
    int maxre=0;
    for(string s:strs)
    {
        int sum=0;
        bool sign=false;
        for(char c:s)
        {
            if(checknum(c))
            {
                sum=10*sum+c-'0';
            }
            else 
            {
                sign=true;break;
            }
        }
        if(sign) maxre=max(maxre,(int)s.length());
        else maxre=max(maxre,sum);
    }
    return maxre;
}