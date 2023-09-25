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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> re;
    vector<int> tmp;
    if(root==NULL)
        return {};
    tmp=inorderTraversal(root->left);
    if(tmp.size()) re.insert(re.end(),tmp.begin(),tmp.end());
    re.push_back(root->val);
    tmp=inorderTraversal(root->right);
    if(tmp.size()) re.insert(re.end(),tmp.begin(),tmp.end());
    return re;
}