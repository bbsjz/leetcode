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

unordered_map<long long int,long long int> mp;
long long int cnt = 0;
long long int sum=0;

//是的，在遍历的过程中就可以通过类似进栈退栈的方式来进行前缀和的遍历搜索
//遍历到一个新的节点的时候只需要考虑这个新的状态
void getSum(TreeNode* root,int target)
{
    if(root==NULL) return;
    sum+=root->val;
    if(mp.count(sum-target)!=0)
        cnt+=mp[sum-target];
    mp[sum]++;
    if(root->left) getSum(root->left,target);
    if(root->right) getSum(root->right,target);
    mp[sum]--;
    sum-=root->val;
}

int pathSum(TreeNode *root, int targetSum)
{

    mp[0]=1;
    getSum(root,targetSum);
    return cnt;
}

int main()
{
    TreeNode *t1 = new TreeNode(10);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(-3);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(2);
    TreeNode *t6 = new TreeNode(11);
    TreeNode *t7 = new TreeNode(3);
    TreeNode *t8 = new TreeNode(-2);
    TreeNode* t9=new TreeNode(1);
    t1->left = t2;
    t1->right = t3;
    t2->left=t4;
    t2->right=t5;
    t3->right=t6;
    t4->left=t7;
    t4->right=t8;
    t5->right=t9;
    cout<<pathSum(t1,8);
    return 0;
}