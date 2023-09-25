#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *tmp = NULL;
    ListNode* head=NULL;
    for(auto it=lists.begin();it!=lists.end();)
    {
        if((*it)==NULL)
        {
            it=lists.erase(it);
        }
        else
        {
            it++;
        }
    }
    while (lists.size())
    {
        ListNode *minNode = lists[0];
        int i=0;
        for (auto it = lists.begin(); it != lists.end();it++)
        {
            ListNode* t=(*it);
            if (t->val < minNode->val)
            {
                minNode = t;
                i=(it-lists.begin());
            }
        }
        if (tmp == NULL)
        {
            tmp = minNode;
            head=tmp;
        }
        else
        {
            tmp->next = minNode;
            tmp = tmp->next;
        }
        lists[i]=lists[i]->next;
        if(lists[i]==NULL)
        {
            lists.erase(lists.begin()+i);
        }
    }
    return head;
}

int main()
{
    ListNode* t1=new ListNode(1);
    ListNode* t2=new ListNode(4);
    ListNode* t3=new ListNode(5);
    t1->next=t2;
    t2->next=t3;
    ListNode* t4=new ListNode(1);
    ListNode* t5=new ListNode(3);
    ListNode* t6=new ListNode(4);
    t4->next=t5;
    t5->next=t6;
    ListNode* t7=new ListNode(2);
    ListNode* t8=new ListNode(6);
    t7->next=t8;
    vector<ListNode*> v;
    v.push_back(t1);
    v.push_back(t4);
    v.push_back(t7);
    mergeKLists(v);
    return 0;
}