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

TreeNode* tree;

bool dfs(TreeNode* root,TreeNode* p, TreeNode* q)
{
    if(root==NULL) return false;
    bool lson=dfs(root->left,p,q);
    bool rson=dfs(root->right,p,q);
    if(lson&&rson||(root==p||root==q)&&(lson||rson))
    {
        tree=root;
    }
    return root==p||root==q||lson||rson;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root,p,q);
    return tree;
}