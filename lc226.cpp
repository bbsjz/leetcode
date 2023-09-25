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

void reverse(TreeNode*& l,TreeNode*& r)
{
    if(l&&(l->left||l->right)) reverse(l->left,l->right);
    if(r&&(r->left||r->right)) reverse(r->left,r->right);
    swap(l,r);
}

TreeNode* invertTree(TreeNode* root) {
    if(root==NULL||(root->left==NULL&&root->right==NULL)) return root;
    reverse(root->left,root->right);
    return root;
}