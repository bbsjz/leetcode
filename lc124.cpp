#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//二叉树的最大路径和，不能一个节点走两次，最多只能走一次，每次计算两个节点添加起来的结果，但是只往上传递更大的那个结果（如果两者都大于0）
int getmax(TreeNode* root,int& maxsum)
{
    if(root->left==NULL&&root->right==NULL) 
    {
        maxsum=max(maxsum,root->val);
        return root->val;
    }
    int mid=root->val;
    int maxl,maxr;
    if(root->left) 
    {
        maxl=getmax(root->left,maxsum);
        if(maxl>0) mid+=maxl;
    }
    if(root->right) 
    {
        maxr=getmax(root->right,maxsum);
        if(maxr>0) mid+=maxr;
    }
    maxsum=max(maxsum,mid);
    if(root->left&&root->right&&maxl>0&&maxr>0) 
    {
        int minlr=min(maxl,maxr);
        return mid-minlr;
    }
    else return mid;
}

int maxPathSum(TreeNode* root) {
   int maxsum=root->val;
   getmax(root,maxsum);
   return maxsum;
}