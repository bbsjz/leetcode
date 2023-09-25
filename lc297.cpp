#include <iostream>
#include <list>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//这样做序列化的话会有负数，而我用来做分割的是
//可能有的元素+'0'之后得到的就是,，这样元素就和分隔符重复了
//出问题的是-4，因为-4+'0'=-4+48=44也就是,，这样转换到序列表示的时候
//本来希望把,作为元素内容，但是却把它当成了分隔符

//解了上面的问题，又出现了新的问题，如果出现相同的元素，那么就不能通过前序和中序遍历的顺序确定树长成什么样子

//题解就是把所有的NULL节点也存下来了，这个时候相当于一棵满二叉树，满二叉树甚至只需要一个序列就可以确定下来 
// class Codec
// {
//     vector<int> inv,prev;
// public:

//     string numtostring(int num)
//     {
//         stack<int> st;
//         string s;
//         if(num==0) return "0";
//         while(num)
//         {
//             st.push(num%10);
//             num/=10;
//         }
//         while(st.size())
//         {
//             s+=(st.top()+'0');
//             st.pop();
//         }
//         return s;
//     }

//     int stringtonum(string s)
//     {
//         int re=0;
//         for(int i=0;i<s.length();i--)
//         {
//             int digit=s.at(i)-'0';
//             re += re*10+digit;
//         }
//         return re;
//     }

//     void getin(TreeNode *root)
//     {
//         if(root==NULL) return;
//         getin(root->left);
//         inv.push_back(root->val);
//         getin(root->right);
//     }

//     void getpre(TreeNode *root)
//     {
//         if(root==NULL) return ;
//         prev.push_back(root->val);
//         getpre(root->left);
//         getpre(root->right);
//     }
//     // Encodes a tree to a single string.
//     string serialize(TreeNode *root)
//     {
//         string in,pre;
//         getin(root);
//         getpre(root);
//         for(int i=0;i<inv.size();i++)
//         {
//             in+=numtostring(inv[i]);
//             in+="#";
//         }
//         for(int i=0;i<prev.size();i++)
//         {
//             pre+=numtostring(prev[i]);
//             pre+="#";
//         }
//         return in+"p"+pre;
//     }

//     TreeNode *restore(vector<int> reinv,vector<int> reprev)
//     {
//         if(reprev.empty()) return NULL;
//         else if(reprev.size()==1)
//         {
//             TreeNode *leaf=new TreeNode(reprev.back());
//             return leaf;
//         }
//         int mid=reprev[0];
//         int pos=0;
//         for(;pos<reinv.size();pos++)
//         {
//             if(reinv[pos]==mid) break;
//         }
//         vector<int> inl,inr,prel,prer;
//         inl.insert(inl.end(),reinv.begin(),reinv.begin()+pos);
//         inr.insert(inr.end(),reinv.begin()+pos+1,reinv.end());
//         prel.insert(prel.end(),reprev.begin()+1,reprev.begin()+pos+1);
//         prer.insert(prer.end(),reprev.begin()+pos+1,reprev.end());
//         TreeNode* l=restore(inl,prel);
//         TreeNode* r=restore(inr,prer);
//         TreeNode* m=new TreeNode(mid);
//         m->left=l;
//         m->right=r;
//         return m;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode *deserialize(string data)
//     {
//         int ppos=data.find('p');
//         string in,pre;
//         in=data.substr(0,ppos);
//         pre=data.substr(ppos+1,data.length()-ppos-1);
//         vector<int> reinv,reprev;
//         while(in.length())
//         {
//             int pos=in.find('#');
//             string num=in.substr(0,pos);
//             int n=stringtonum(num);
//             reinv.push_back(n);
//             in=in.substr(pos+1,in.length()-pos-1);
//         }
//         while(pre.length())
//         {
//             int pos=pre.find('#');
//             string num=pre.substr(0,pos);
//             int n=stringtonum(num);
//             reprev.push_back(n);
//             pre=pre.substr(pos+1,pre.length()-pos-1);
//         }
//         return restore(reinv,reprev);
//     }
// };

class Codec {
    string s;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) 
        { 
            s.append("None,");return s;
        }
        int var=root->val;
        s.append(to_string(var));
        s.append(",");
        serialize(root->left);
        serialize(root->right);
        return s;
    }

    //卡在这里了，就是考虑到左子树递归结束之后，开始递归右子树的时候，不知道把谁传进去
    //答案的做法是用一个额外的数组存储，之后每次都会改变值
    // Decodes your encoded data to tree.
    TreeNode* de(list<string>& v)
    {
        string sub=v.front();
        v.pop_front();
        if(sub=="None") return NULL;
        TreeNode* root=new TreeNode(stoi(sub));
        TreeNode* l=de(v);
        TreeNode* r=de(v);
        root->left=l;
        root->right=r;
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> v;
        while(data.size())
        {
            int pos=data.find(',');
            v.push_back(data.substr(0,pos));
            data.erase(0,pos+1);
        }
       return de(v);
    }
};
int main()
{
    // TreeNode* root=new TreeNode(4);
    // TreeNode* r1=new TreeNode(-7);
    // TreeNode* r2=new TreeNode(-3);
    // TreeNode* r3=new TreeNode(-9);
    // TreeNode* r4=new TreeNode(-3);
    // TreeNode* r5=new TreeNode(9);
    // TreeNode* r6=new TreeNode(-7);
    // TreeNode* r7=new TreeNode(-4);
    // TreeNode* r8=new TreeNode(6);
    // TreeNode* r9=new TreeNode(-6);
    // TreeNode* r10=new TreeNode(-6);
    // TreeNode* r11=new TreeNode(0);
    // TreeNode* r12=new TreeNode(6);
    // TreeNode* r13=new TreeNode(5);
    // TreeNode* r14=new TreeNode(9);
    // TreeNode* r15=new TreeNode(-1);
    // TreeNode* r16=new TreeNode(-4);
    // TreeNode* r17=new TreeNode(-2); 
    // root->left=r1;
    // root->right=r2;
    // r2->left=r3;
    // r2->right=r4;
    // r3->left=r5;
    // r3->right=r6;
    // r4->left=r7;
    // r5->left=r8;
    // r6->left=r9;
    // r6->right=r10;
    // r8->left=r11;
    // r8->right=r12;
    // r9->left=r13;
    // r10->left=r14;
    // r11->right=r15;
    // r12->left=r16;
    // r14->left=r17;
    Codec ser, deser;
    TreeNode* root=new TreeNode(1);
    TreeNode* r1=new TreeNode(2);
    TreeNode* r2=new TreeNode(3);
    TreeNode* r3=new TreeNode(4);
    TreeNode* r4=new TreeNode(5);
    root->left=r1;
    root->right=r2;
    r2->left=r3;
    r2->right=r4;
    string s=ser.serialize(root);
    TreeNode* ans = deser.deserialize(s);
    return 0;
}