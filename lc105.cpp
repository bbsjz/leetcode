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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty()) return NULL;
    int value=preorder[0];
    TreeNode* t = new TreeNode;
    t->val=value;
    int pos=-1;
    for(int i=0;i<inorder.size();i++)
        if(inorder[i]==value)
        {
            pos=i;break;
        }   
    vector<int> lpre,lino,rpre,rino;
    lpre.insert(lpre.end(),preorder.begin()+1,preorder.begin()+pos+1);
    lino.insert(lino.end(),inorder.begin(),inorder.begin()+pos);
    rpre.insert(rpre.end(),preorder.begin()+pos+1,preorder.end());
    rino.insert(rino.end(),inorder.begin()+pos+1,inorder.end());
    TreeNode* tl=buildTree(lpre,lino);
    TreeNode* tr=buildTree(rpre,rino);
    t->left=tl;
    t->right=tr;
    return t;
}