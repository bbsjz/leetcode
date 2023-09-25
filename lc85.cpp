#include<iostream>
#include<vector>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    int row=matrix.size(),column=matrix[0].size();
    vector<int> tmp(column+1,0);
    tmp[column]=-1;
    int maxarea=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(matrix[i][j]=='0') tmp[j]=0;
            else tmp[j]++;
        }
        //note that you modify the value of t in the monotonous stack step
        //so you shouldn't add new number on it
        //it should be a copy
        vector<int> t=tmp;
        vector<int> stack;
        for(int j=0;j<column+1;j++)
        {
            if(stack.empty()||t[stack.back()]<=t[j])
                stack.push_back(j);
            else
            {
                int pos;
                while(stack.size()&&t[stack.back()]>t[j])
                {
                    pos=stack.back();
                    maxarea=max(maxarea,(j-pos)*t[pos]);
                    stack.pop_back();
                }
                t[pos]=t[j];
                stack.push_back(pos);
            }
        }
    }
    return maxarea;
}

int main()
{
    vector<vector<char>> matrix={{'1','0','1','1','1',},{'1','1','0','0','1'},{'1','1','1','0','0'},{'1','1','1','1','0'}};
    cout<<maximalRectangle(matrix);
    return 0;
}