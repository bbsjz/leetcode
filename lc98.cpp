#include<iostream>
#include<vector>
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

int getmax(TreeNode* root)
{
    int tmp=root->val;
    if(root->left) tmp=max(tmp,getmax(root->left));
    if(root->right) tmp=max(tmp,getmax(root->right));
    return tmp;
}

int getmin(TreeNode* root)
{
    int tmp=root->val;
    if(root->left) tmp=min(tmp,getmin(root->left));
    if(root->right) tmp=min(tmp,getmin(root->right));
    return tmp;
}

bool isValidBST(TreeNode* root) {
    if(root==NULL) return true;
    int mid=root->val;
    if(root->left)
    {
        int l=getmax(root->left);
        if(l>mid) return false;
    }
    if(root->right)
    {
        int r=getmin(root->right);
        if(r<mid) return false;
    }
    return isValidBST(root->left)&&isValidBST(root->right);
}