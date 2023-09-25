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

bool ifSame(TreeNode* l,TreeNode* r)
{
    if(l==NULL&&r==NULL) return true;
    else if(l==NULL||r==NULL) return false;
    else if(l->val!=r->val) return false;
    return ifSame(l->left,r->right)&&ifSame(l->right,r->left);
}

bool isSymmetric(TreeNode* root) {
    if(root==NULL) return true;
    else if(root->left==NULL&&root->right==NULL) return true;
    else if(root->left==NULL||root->right==NULL) return false;
    else return ifSame(root->left,root->right);
}