#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool same(unordered_map<char,int> current,unordered_map<char,int> target)
{
    for(auto it=target.begin();it!=target.end();it++)
        if(current.count((*it).first)==0||current[(*it).first]!=target[(*it).first])
            return false;
    return true;
}

vector<int> findAnagrams(string s, string p) {
    if(s.length()<p.length()) return {};
    vector<int> re;
    unordered_map<char,int> current;
    unordered_map<char,int> target;
    for(int i=0;i<p.length();i++)
        target[p.at(i)]++;
    for(int i=0;i<p.length();i++)
        current[s.at(i)]++;
    //same有更快的方式，可以字母转数字，最多26个数字数组去表示
    //然后vector可以直接比较大小，比map快感觉
    if(same(current,target)) re.push_back(0);
    for(int i=p.length();i<s.length();i++)
    {
        current[s.at(i-p.length())]--;
        current[s.at(i)]++;
        if(same(current,target)) re.push_back(i-p.length()+1);
    }
    return re;
}