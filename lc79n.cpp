#include<iostream>
#include<vector>
using namespace std;
//这个逻辑确实比之前清晰，之前是用map存每个点对是否已经走过了
//现在不是，现在是直接用一个bool数组存，那判断走没走过
//直接是O1的，map的话还得是Ologn的，那肯定是O1的快
int hc[4]={0,0,-1,1},hr[4]={-1,1,0,0};
bool re(vector<vector<char>>& board,vector<vector<bool>>& st,int r,int c,string left)
{
    if(left=="") return true;
    int row=board.size(),column=board[0].size();
    for(int i=0;i<4;i++)
    {
        int newc=c+hc[i];int newr=r+hr[i];
        if((0<=newc)&&(newc<column)&&(0<=newr)&&(newr<row)&&(!st[newr][newc])&&(board[newr][newc]==left.at(0)))
        {
            st[newr][newc]=true;
            if(re(board,st,newr,newc,left.substr(1,left.length()-1))) return true;
            st[newr][newc]=false;
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word)
{
    int row=board.size(),column=board[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(board[i][j]==word.at(0))
            {
                vector<vector<bool>> st(row,vector<bool>(column));
                st[i][j]=true;
                if(re(board,st,i,j,word.substr(1,word.length()-1)))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board={{'A'},{'A'}};
    string word="AAA";
    cout<<exist(board,word);
    return 0;
}