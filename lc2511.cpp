#include <iostream>
#include<vector>
using namespace std;
int captureForts(vector<int> &forts)
{
    int re=0;
    int flag=false;
    int tmp=0;
    for(int i=0;i<forts.size();i++)
    {
        if(forts[i]==1)
        {
            int tmp=0;
            for(int j=i-1;j>=0;j--)
            {
                if(forts[j]==0) tmp++;
                else if(forts[j]==-1) {re=max(re,tmp);break;}
                else if(forts[j]==1) break;
            }
            tmp=0;
            for(int j=i+1;j<forts.size();j++)
            {
                if(forts[j]==0) tmp++;
                else if(forts[j]==-1) {re=max(re,tmp);break;}
                else if(forts[j]==1) break;
            }
        }
    }
    return re;
}


int main()
{
    vector<int> v={1,0,0,-1,0,0,0,0,1};
    cout<<captureForts(v);
    return 0;
}