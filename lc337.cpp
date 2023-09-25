#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
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
struct node
{
    int toule;
    int meitou;
};

node* treedp(TreeNode* root)
{
    if(root==NULL) return NULL;
    if(root->left==NULL&&root->right==NULL)
    {
        node* n=new node;
        n->meitou=0;
        n->toule=root->val;
        return n;
    }
    node* n=new node;
    n->meitou=0;
    n->toule=root->val;
    if(root->left)
    {
        node* tmp=treedp(root->left);
        n->meitou+=max(tmp->toule,tmp->meitou);
        n->toule+=tmp->meitou;
    }
    if(root->right)
    {
        node* tmp=treedp(root->right);
        n->meitou+=max(tmp->toule,tmp->meitou);
        n->toule+=tmp->meitou;
    }
    return n;
}

int rob(TreeNode* root) {
    if(root==NULL) return 0;
    node* n=treedp(root);
    return max(n->meitou,n->toule);
}