#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
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

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    if(preorder.empty()) return NULL;
    else if(preorder.size()==1)
    {
        TreeNode* t=new TreeNode;
        t->val=preorder[0];
        t->left=NULL;
        t->right=NULL;
        return t;
    }
    int root=preorder[0];
    int left=preorder[1];
    int pos=0;
    for(int i=0;i<postorder.size();i++)
        if(postorder[i]==left) 
        {pos=i;break;}
    vector<int> preorderl,preorderr,postorderl,postorderr;
    preorderl.insert(preorderl.end(),preorder.begin()+1,preorder.begin()+pos+2);
    preorderr.insert(preorderr.end(),preorder.begin()+pos+2,preorder.end());
    postorderl.insert(postorderl.end(),postorder.begin(),postorder.begin()+pos+1);
    postorderr.insert(postorderr.end(),postorder.begin()+pos+1,postorder.end()-1);
    TreeNode* l=constructFromPrePost(preorderl,postorderl);
    TreeNode* r=constructFromPrePost(preorderr,postorderr);
    TreeNode* t=new TreeNode;
    t->val=root;
    t->left=l;t->right=r;
    return t;
}

int main()
{
    vector<int> a={1,2,4,5,3,6,7};
    vector<int> b={4,5,2,6,7,3,1};
    constructFromPrePost(a,b);
    return 0;
}