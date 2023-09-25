#include <iostream>
#include <vector>
#include <set>
#include <map>
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
int re;
//节点更好计算一些，所以这个地方是取到了节点，计算最大的节点个数，最后-1就是边的数量
int findMax(TreeNode* root)
{
    if(root==NULL) return -1;
    int left=findMax(root->left);
    int right=findMax(root->right);
    int tmp=0;
    if(root->left) tmp+=left+1;
    if(root->right) tmp+=right+1;
    re=max(re,tmp);
    return max(left,right)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    findMax(root);
    return re;
}

int main()
{
    TreeNode* r1=new TreeNode;
    TreeNode* r2=new TreeNode;
    TreeNode* r3=new TreeNode;
    TreeNode* r4=new TreeNode;
    TreeNode* r5=new TreeNode;
    r1->val=1;
    r2->val=2;
    r3->val=3;
    r4->val=4;
    r5->val=5;
    r2->left=r4;
    r2->right=r5;
    r1->left=r2;
    r1->right=r3;
    cout<<diameterOfBinaryTree(r1);
    return 0;
}