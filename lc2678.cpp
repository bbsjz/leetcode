#include <iostream>
#include <vector>
#include <string>
using namespace std;
int countSeniors(vector<string> &details)
{
    int sum=0;
    for (string s : details)
    {
        string num=s.substr(11,2);
        int age=stoi(num);
        if(age>60) sum++;
    }
    return sum;
}