#include<vector>
#include<iostream>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    vector<int> stack;
    heights.push_back(-1);
    int maxarea=0;
    for(int i=0;i<heights.size();i++)
    {
        if(stack.empty()||heights[stack.back()]<=heights[i])
            stack.push_back(i);
        else
        {
            int lastpos;
            while(stack.size()&&heights[stack.back()]>heights[i])
            {
                lastpos=stack.back();
                maxarea=max(maxarea,(i-lastpos)*heights[lastpos]);
                stack.pop_back();
            }
            heights[lastpos]=heights[i];
            stack.push_back(lastpos);
        }
    }
    return maxarea;
}

int main()
{
    vector<int> v={2,4};
    cout<<largestRectangleArea(v);
    return 0;
}