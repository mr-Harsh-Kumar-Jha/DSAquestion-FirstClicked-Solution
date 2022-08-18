// this is a solution with time complexity : O(n) and Space Complexity: O(1);
//https://leetcode.com/problems/linked-list-cycle-ii/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
   if (head == NULL || head->next == NULL)
      return NULL;

   ListNode *slow = head;
   ListNode *fast = head;
   ListNode *entry = head;

   while (fast->next && fast->next->next)
   {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) // code for detecting cycle
      {
         while (slow != entry) // finding the entry location
         {
            slow = slow->next;
            entry = entry->next;
         }
         return entry;
      }
   }
   return NULL;
}

int main(){
    ListNode *head1 = new ListNode(5);
    ListNode *temp1 = head1;
    ListNode *temp2 = head1;
    ListNode *pos ;
   temp1->next = new ListNode(6);
   temp1 = temp1->next;
   temp1->next = new ListNode(7);
   temp1 = temp1->next;
   pos = temp1;
   temp1->next = new ListNode(8);
   temp1 = temp1->next;
   temp1->next = new ListNode(9);
   temp1 = temp1->next;
   temp1->next = pos;

   ListNode *ans = detectCycle(head1);
   int count=1;
   while (temp2 != NULL){
      if(temp2==ans){
         cout<<" The cycle starts at position "<<count<<endl;
         break;
      }
      count+=1;
      temp2=temp2->next;
   }
}