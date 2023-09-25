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

//在内部改变节点，拆分，递归的进行这个过程
void flatten(TreeNode* root) {
    if(root==NULL) return;
    TreeNode* l=root->left;
    TreeNode* r=root->right;
    root->left=NULL;
    flatten(l);
    root->right=l;
    flatten(r);
    while(root->right) root=root->right;
    root->right=r;
}