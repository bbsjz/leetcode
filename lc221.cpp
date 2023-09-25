#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int row=matrix.size();
    int column=matrix[0].size();
    vector<int> line(column+1,0);
    line[column]=-1;
    vector<int> line_cp;
    int max_area=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(matrix[i][j]=='1') line[j]++;
            else line[j]=0;
        }
        line_cp=line;
        stack<int> st;
        for(int j=0;j<=column;j++)
        {
            if(st.empty()||line_cp[st.top()]<line_cp[j]) st.push(j);
            else
            {
                int last_pop;
                while(st.size()&&line_cp[st.top()]>=line_cp[j])
                {
                    int mark=st.top();
                    st.pop();
                    last_pop=mark;
                    // if(j-mark==line_cp[mark]) max_area=max(max_area,(j-mark)*line_cp[mark]);
                    int duanbian=min(j-mark,line_cp[mark]);
                    max_area=max(max_area,duanbian*duanbian);
                }
                line_cp[last_pop]=line_cp[j];
                st.push(last_pop);
            }
        }
    }
    return max_area;
}

int main()
{
    vector<vector<char>> v={{'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}};
    cout<<maximalSquare(v);
    return 0;
}