#include<iostream>
#include<map>
#include<vector>
using namespace std;

bool recursion(vector<vector<char>>& board, string word, int po,int i,int j,map<pair<int,int>,int> path)
{
    if(po==word.length())
    {
        return true;
    }
    int row=board.size();
    int column=board[0].size();
    if(i-1>=0)//在不重复的路径中匹配po上的字母
    {
        pair<int,int> p={i-1,j};
        if(path.find(p)==path.end())//此点不在path中，则可以走
        {
            if(board[i-1][j]==word[po])
            {
                path[p]=1;
                if(recursion(board,word,po+1,i-1,j,path))
                {
                    return true;
                }
                path.erase(p);
            }
        }
    }
    if(i+1<row)
    {
        pair<int,int> p={i+1,j};
        if(path.find(p)==path.end())//此点不在path中，则可以走
        {
            if(board[i+1][j]==word[po])
            {
                path[p]=1;
                if(recursion(board,word,po+1,i+1,j,path))
                {
                    return true;
                }
                path.erase(p);
            }
        }
    }
    if(j-1>=0)
    {
        pair<int,int> p={i,j-1};
        if(path.find(p)==path.end())//此点不在path中，则可以走
        {
            if(board[i][j-1]==word[po])
            {
                path[p]=1;
                if(recursion(board,word,po+1,i,j-1,path))
                {
                    return true;
                }
                path.erase(p);
            }
        }
    }
    if(j+1<column)
    {
        pair<int,int> p={i,j+1};
        if(path.find(p)==path.end())//此点不在path中，则可以走
        {
            if(board[i][j+1]==word[po])
            {
                path[p]=1;
                if(recursion(board,word,po+1,i,j+1,path))
                {
                    return true;
                }
                path.erase(p);
            }
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word)
{
    int row=board.size();
    int column=board[0].size();
    int length=word.length();
    map<pair<int,int>,int> path;
    int sign=false;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(board[i][j]==word[0])//find all the begin point
            {
                path[{i,j}]=1;
                if(recursion(board,word,1,i,j,path))
                {
                    sign=true;
                    break;
                }
                path.erase({i,j});
            }
        }
        if(sign)
        {
            break;
        }
    }
    return sign;
}

int main()
{
    vector<vector<char>> board={{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    string word="AAB";
    cout<<exist(board,word);
    return 0;
}