#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& v,int s,int e)
{
    int tmp=v[s];
    int i=s,j=e;
    while(i<j)
    {
        while(i<j)
        {
            if(v[j]>=tmp)
            {
                j--;
            }
            else
            {
                v[i]=v[j];
                break;
            }
        }
        while(i<j)
        {
            if(v[i]<=tmp)
            {
                i++;
            }
            else
            {
                v[j]=v[i];
                break;
            }
        }
    }
    v[i]=tmp;
    return i;
}

void quickSort(vector<int>& v,int s,int e)
{
    if(s<e)
    {
        int po=partition(v,s,e);
        quickSort(v,s,po-1);
        quickSort(v,po+1,e);
    }
}

void sortColors(vector<int>& nums) 
{
    quickSort(nums,0,nums.size()-1);
}

int main()
{
    vector<int> v={2,0,2,1,1,0};
    sortColors(v);
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}