#include<iostream>
#include<map>
#include<string>
using namespace std;

bool check(map<char,int> ori,map<char,int> cur)
{
    for(auto it:ori)
    {
        if(cur.find(it.first)==cur.end()||cur[it.first]<it.second)
        {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) 
{
    map<char,int> ori,cur;
    for(char c:t)
    {
        ori[c]++;
    }
    int pre=0;
    for(int i=0;i<s.length();i++)
    {
        if(ori.find(s[i])!=ori.end())
        {
            pre=i;
            break;
        }
    }
    s=s.substr(pre,s.length()-pre);
    int l=0,r=0,len=INT_MAX,ansL=0;
    for(int i=0;i<s.size();i++)
    {
        cur[s[i]]++;
        while(check(ori,cur)&&l<=r)
        {
            if(len>r-l+1)
            {
                len=r-l+1;
                ansL=l;
            }
            if(ori.find(s[l])!=ori.end())//其实是不需要找的啊，直接-，因为之前必然是被加进到cur中去过的，这个地方额外判断会浪费时间啊
            {
                cur[s[l]]--;
            }
            l++;
        }
        r++;
    }
    return len==INT_MAX?"":s.substr(ansL,len);
}

int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<minWindow(s,t);
    return 0;
}
   