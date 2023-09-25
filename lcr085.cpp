#include <iostream>
#include<vector>
using namespace std;
vector<string> generateParenthesis(int n)
{
    vector<vector<string>> v(n+1,vector<string>());
    v[0]={""};
    v[1]={"()"};
    for(int i=2;i<=n;i++)
    {
        int left=i-1;
        for(int q=0;q<=left;q++)
        {
            int zuo=q;int you=left-q;
            for(string sl:v[zuo])
            {
                for(string sr:v[you])
                {
                    v[i].push_back("("+sl+")"+sr);
                }
            }
        }
    }
    return v[n];
}