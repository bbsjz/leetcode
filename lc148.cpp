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

//链表排序的时候反而只能用归并时间复杂度才满足要求，因为这是严格的logn
ListNode* cut(ListNode* head,ListNode*& rear)
{
    if(head==NULL) return NULL;
    else if(head->next==NULL) return head;
    ListNode* slow=head;ListNode* quick=head;
    while(quick->next&&quick->next->next) {slow=slow->next;quick=quick->next->next;}
    rear=slow->next;
    slow->next=NULL;
    return head;
}

ListNode* merge(ListNode* l,ListNode* r)
{
    ListNode* head=new ListNode;
    ListNode* h=head;
    while(l&&r)
    {
        if(l->val>r->val){head->next=r;r=r->next;head=head->next;}
        else{head->next=l;l=l->next;head=head->next;}
    }
    while(l)
    {
        head->next=l;
        l=l->next;
        head=head->next;
    }
    while(r)
    {
        head->next=r;
        r=r->next;
        head=head->next;
    }
    h=h->next;

    return h;
}

ListNode* sortList(ListNode*& head) {
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    ListNode* f;
    ListNode* r=NULL;
    f=cut(head,r);
    f=sortList(f);
    r=sortList(r);
    return merge(f,r);
}

int main()
{
    ListNode* t1=new ListNode;
    t1->val=4;
    ListNode* t2=new ListNode;
    t2->val=2;
    t1->next=t2;
    ListNode* t3=new ListNode;
    t3->val=1;
    t2->next=t3;
    ListNode* t4=new ListNode;
    t4->val=3;
    t4->next=NULL;
    t3->next=t4;
    ListNode* t=sortList(t1);
    return 0;
}