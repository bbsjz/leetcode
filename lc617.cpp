#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
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

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    TreeNode* t=NULL;
    if(root1!=NULL||root2!=NULL)
    {
        int val=0;
        if(root1!=NULL) val+=root1->val;
        if(root2!=NULL) val+=root2->val;
        t=new TreeNode(val);
        TreeNode* left=mergeTrees(root1!=NULL?root1->left:NULL,root2!=NULL?root2->left:NULL);
        TreeNode* right=mergeTrees(root1!=NULL?root1->right:NULL,root2!=NULL?root2->right:NULL);
        t->left=left;
        t->right=right;
    }
    return t;
}