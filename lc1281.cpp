#include <iostream>
#include <vector>
using namespace std;

int subtractProductAndSum(int n)
{
    vector<int> digit;
    while(n)
    {
        digit.push_back(n%10);
        n/=10;
    }
    int sum=0;
    int multi=1;
    for(int i=0;i<digit.size();i++)
    {
        sum+=digit[i];
        multi*=digit[i];
    }
    return multi-sum;
}