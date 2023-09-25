#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> st;
    if(head==NULL) return NULL;
    ListNode* slow=head;
    ListNode* quick=head;
    while(slow->next&&quick->next&&quick->next->next)//注意这里要判断两次
    {
        slow=slow->next;
        quick=quick->next->next;
        if(slow==quick)
        {
            ListNode* t=head;
            st.insert(head);
            while(st.count(t->next)==0)
            {
                st.insert(t->next);
                t=t->next;
            }
            return t->next;
        }
    }
    return NULL;
}