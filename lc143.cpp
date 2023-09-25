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

void reorderList(ListNode *head)
{
    if(head==NULL||head->next==NULL)return; 
    // break to 2 list
    int count = 0;
    ListNode *t = head;
    while (t)
    {
        t = t->next;
        count++;
    }
    ListNode *head2 = head;
    int cnt = count / 2;
    if (count % 2 == 0)
        cnt--;
    while (cnt>0)
    {
        head2 = head2->next;
        cnt--;
    } // 1 2(head2) 3 4, 1 2 3(head2) 4 5
    ListNode *tail = head2;
    head2 = head2->next;
    tail->next = NULL;
    // reverse the second list
    ListNode *tmp1 = head2;
    ListNode *tmp2 = head2->next;
    tmp1->next = NULL;
    while (tmp2)
    {
        ListNode *tmp3 = tmp2->next;
        tmp2->next = tmp1;
        tmp1 = tmp2;
        tmp2 = tmp3;
    }
    // tmp1 become new head, then merge
    ListNode *re = head;
    ListNode* res=re;
    head = head->next;
    cnt = 1;
    while (head && tmp1)
    {
        if (cnt % 2 == 1)
        {
            re->next = tmp1;
            tmp1 = tmp1->next;
        }
        else
        {
            re->next = head;
            head = head->next;
        }
        re = re->next;
        cnt++;
    }
    while (head)
    {
        re->next = head;
        re = re->next;
        head = head->next;
    }
    while (tmp1)
    {
        re->next = tmp1;
        re = re->next;
        tmp1 = tmp1->next;
    }
    head = res;
}

int main()
{
    ListNode *t1 = new ListNode(1);
    ListNode *t2 = new ListNode(2);
    ListNode *t3 = new ListNode(3);
    ListNode *t4 = new ListNode(4);
    t1->next = t2;
    // t2->next = t3;
    // t3->next = t4;
    reorderList(t1);
    return 0;
}