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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> st;
    while(headA&&headB)
    {
        if(st.count(headA)==0) {st.insert(headA);headA=headA->next;}
        else return headA;
        if(st.count(headB)==0) {st.insert(headB);headB=headB->next;}
        else return headB;
    }
    while(headA)
    {
        if(st.count(headA)==0) {st.insert(headA);headA=headA->next;}
        else return headA;
    }
    while(headA)
    {
        if(st.count(headB)==0) {st.insert(headB);headB=headB->next;}
        else return headB;
    }
    return NULL;
}