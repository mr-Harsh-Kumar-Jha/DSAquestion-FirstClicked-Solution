#include <bits/stdc++.h>
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

   if (list1->val <= list2->val)
   {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
   }
   else
   {
      list2->next = mergeTwoLists(list2->next, list1);
      return list2;
   }
}

int main()
{
   ListNode *head1 = new ListNode(5);
   ListNode *head2 = new ListNode(1);
   ListNode *temp1 = head1;
   ListNode *temp2 = head2;
   temp1->next = new ListNode(6);
   temp1 = temp1->next;
   temp1->next = new ListNode(7);
   temp2->next = new ListNode(8);
   temp2 = temp2->next;
   temp2->next = new ListNode(9);

   ListNode *ans = mergeTwoLists(head1, head2);
   while (ans != NULL)
   {
      cout << ans->val << " ";
      ans = ans->next;
   }
}