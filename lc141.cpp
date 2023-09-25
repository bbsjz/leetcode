#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(head==NULL) return false;
    ListNode* slow=head;
    ListNode* quick=head;
    while(slow->next&&quick->next&&quick->next->next)
    {
        slow=slow->next;
        quick=quick->next->next;
        if(slow==quick) return true;
    }
    return false;
}