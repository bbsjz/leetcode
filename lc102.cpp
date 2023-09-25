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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> re;
    if(root==NULL) return {};
    queue<TreeNode*> q1;
    q1.push(root);
    while(q1.size())
    {
        vector<int> tmp;
        queue<TreeNode*> q2;
        while(q1.size())
        {
            TreeNode* t=q1.front();
            q1.pop();
            tmp.push_back(t->val);
            if(t->left) q2.push(t->left);
            if(t->right) q2.push(t->right);
        }
        re.push_back(tmp);
        q1=q2;
    }
    return re;
}