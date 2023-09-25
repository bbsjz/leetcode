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

ListNode *swapPairs(ListNode *head)
{
    if(head==NULL||head->next==NULL) return head;
    ListNode* t1=head;
    ListNode* t2=head->next;
    head=t2;
    while(t2->next!=NULL&&t2->next->next!=NULL)
    {
        ListNode* t3=t2->next;
        t1->next=t3->next;
        t2->next=t1;
        t1=t3;
        t2=t3->next;
    }
    t1->next=t2->next;
    t2->next=t1;
    return head;
}