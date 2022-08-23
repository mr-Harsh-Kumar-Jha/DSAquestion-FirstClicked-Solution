// https://leetcode.com/problems/palindrome-linked-list/
// this is one of easy to understand solution ,time Complexity:- O(n) and Space Complexity:- O(1);

// our main funda is to just separate linkedlist from middle part and reverse the second part and then compare the following two linkedlist .

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

ListNode *reverseLinked(ListNode *head)
{ // logic for reversing the linkedlist
   if (head->next == NULL)
      return head;
   ListNode *Head = reverseLinked(head->next);
   head->next->next = head;
   head->next = NULL;
   return Head;
}

bool isPalindrome(ListNode *head)
{
   if (head->next == NULL || head == NULL)
      return true;
   ListNode *temp1 = head;
   ListNode *temp2 = head;
   while (temp2->next != NULL && temp2->next->next != NULL)
   {
      temp1 = temp1->next;
      temp2 = temp2->next->next;
   }
   temp2 = temp1->next;
   temp1->next = NULL; // making mid part next node = null to get second linkedlist
   temp1 = head;
   temp2 = reverseLinked(temp2); // reversing the second part of the linkedlist .
   while (head != NULL && temp2 != NULL)
   { // comparing the two linked list
      if (head->val != temp2->val)
         return false;
      head = head->next;
      temp2 = temp2->next;
   }

   return true;
}

int main()
{

   ListNode *head1 = new ListNode(1);
   ListNode *temp1 = head1;
   temp1->next = new ListNode(2);
   temp1 = temp1->next;
   temp1->next = new ListNode(3);
   temp1 = temp1->next;
   temp1->next = new ListNode(2);
   temp1 = temp1->next;
   temp1->next = new ListNode(1);
   temp1 = temp1->next;

   cout << isPalindrome(head1);
   return 0;
}