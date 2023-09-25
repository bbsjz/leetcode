#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

bool ifnum(char c)
{
    if('0'<=c&&c<='9')
        return true;
    else return false;
}

int getnum(string s)
{
    int num=0;
    for(int i=0;i<s.length();i++)
    {
        num=num*10+s.at(i)-'0';
    }
    return num;
}

string decodeString(string s) {
    string re;
    for(int i=0;i<s.length();)
    {
        string tmp;
        if(ifnum(s.at(i)))
        {
            string num;
            while(ifnum(s.at(i)))//if num can not cross the boundary
            {
                num.append(1,s.at(i));
                i++;
            }
            int number=getnum(num);
            stack<int> st;
            st.push(1);
            i++;
            int pos=i;
            while(st.size())
            {
                if(s.at(i)=='[') st.push(1);
                else if(s.at(i)==']') st.pop();
                i++;
            }
            string tmpre=decodeString(s.substr(pos,i-pos-1));
            for(int i=0;i<number;i++)
                tmp.append(tmpre);
        }
        else
        {
            while(i<s.length()&&!ifnum(s.at(i)))
            {
                tmp.append(1,s.at(i));
                i++;
            }
        }
        re.append(tmp);
    }
    return re;
}

int main()
{
    cout<<decodeString("2[abc]3[cd]ef");
    return 0;
}