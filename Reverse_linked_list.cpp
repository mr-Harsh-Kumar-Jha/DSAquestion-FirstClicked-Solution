// https://leetcode.com/problems/reverse-linked-list/
// this is a recursive approach

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

ListNode *reverseList(ListNode *head)
{
   if (!head || !(head->next))
   {
      return head;
   }
   ListNode *node = reverseList(head->next);
   head->next->next = head;
   head->next = NULL;
   return node;
}

int main(){
   ListNode *head1 = new ListNode(5);
   ListNode *temp1 = head1;
   temp1->next = new ListNode(6);
   temp1 = temp1->next;
   temp1->next = new ListNode(7);
   temp1 = temp1->next;
   temp1->next = new ListNode(8);
   temp1 = temp1->next;
   temp1->next = new ListNode(9);
   ListNode* ans = reverseList(head1);
   while(ans!=NULL){
      cout << ans->val << " ";
      ans = ans->next;
   }
   return 0;
}