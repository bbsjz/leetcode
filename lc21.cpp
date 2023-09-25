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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    ListNode *head;
    if (list1->val < list2->val)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
    }
    ListNode *tmp = head;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            tmp->next = list1;
            list1 = list1->next;
            tmp = tmp->next;
        }
        else
        {
            tmp->next = list2;
            list2 = list2->next;
            tmp = tmp->next;
        }
    }
    while (list1 != NULL)
    {
        tmp->next = list1;
        list1 = list1->next;
        tmp = tmp->next;
    }
    while (list2 != NULL)
    {
        tmp->next = list2;
        list2 = list2->next;
        tmp = tmp->next;
    }
    return head;
}