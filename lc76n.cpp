#include<iostream>
#include<map>
#include<string>
using namespace std;
map<char,int> src;
map<char,int> cur;

bool check()
{
    for(auto it=src.begin();it!=src.end();it++)
    {
        if(cur[(*it).first]<src[(*it).first])
            return false;
    }
    return true;
}
string minWindow(string s, string t) 
{
    for(int i=0;i<t.length();i++)
    {
        src[t.at(i)]++;
    }
    int l=0,r=0;
    int minL=0x3f3f3f3f;
    int minl;
    for(int i=0;i<s.length();i++)
    {
        cur[s.at(i)]++;
        while(check())
        {
            if(minL>r-l+1)
            {
                minL=r-l+1;
                minl=l;
            }
            cur[s.at(l++)]--;
        }
        r++;
    }
    return minL==0x3f3f3f3f?"":s.substr(minl,minL);
}

int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<minWindow(s,t);
    return 0;
}
   