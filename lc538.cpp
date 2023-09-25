#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
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

//傻逼吧你，中间结果用额外变量存啊
int sum=0;
TreeNode *convertBST(TreeNode *root)
{
    if(root==NULL) return NULL;
    if(root->right) 
        convertBST(root->right);
    sum+=root->val;
    root->val=sum;
    if(root->left) 
        convertBST(root->left);
    return root;
}

int main()
{
    TreeNode* t1=new TreeNode(1);
    TreeNode* t2=new TreeNode(0);
    TreeNode* t3=new TreeNode(2);
    t1->left=t2;
    t1->right=t3;
    convertBST(t1);
    return 0;
}