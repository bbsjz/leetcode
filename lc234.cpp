#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
deque<int> d;
bool isPalindrome(ListNode *head)
{   
    if(head==NULL||head->next==NULL) return true;
    else
    {
        while(head)
        {
            d.push_back(head->val);
            head=head->next;
        }
        while(d.size()&&d.size()!=1)
        {
            if(d.back()!=d.front())
            {
                return false;
            }
            d.pop_back();d.pop_front();
        }
        return true;
    }
}