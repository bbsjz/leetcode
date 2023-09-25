#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if(head==NULL||head->next==NULL) return head;  
    ListNode* tmp=new ListNode;
    ListNode* t1=head;
    ListNode* t2=head->next;
    while(t2)
    {
        t1->next=tmp->next;
        tmp->next=t1;
        t1=t2;
        t2=t2->next;
    }
    t1->next=tmp->next;
    tmp->next=t1;
    return tmp->next;
}