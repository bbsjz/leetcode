#include <iostream>
using namespace std;
int countDigits(int num)
{
    int cp=num;
    int divide=0;
    while(num)
    {
        int digit=num%10;
        if(cp%digit==0) divide++;
        num/=10;
    }
    return divide;
}