#include<iostream>
#include<vector>
#include<string>
using namespace std;


bool isMatch(string s, string p)
{
    string new_s=" "+s;
    string new_p=" "+p;
    int m=new_s.length();
    int n=new_p.length();
    vector<vector<int>> v(m,vector<int>(n));
    v[0][0]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(new_s[i]==new_p[j]||(new_p[j]=='?'&&i!=0))
            {
                v[i][j]=v[i-1][j-1];
            }
            else if(new_p[j]=='*')
            {
                if(i-1>=0)
                {
                    v[i][j]|=v[i-1][j];
                }
                if(j-1>=0)
                {
                    v[i][j]|=v[i][j-1];
                }
            }
        }
    }
    return v[m-1][n-1];
}

int main()
{
    cout<<isMatch("acdcb","a*c?b");
    return 0;
}