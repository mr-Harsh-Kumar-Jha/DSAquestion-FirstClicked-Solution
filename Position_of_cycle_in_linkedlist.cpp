// this is a solution with time complexity : O(n) and Space Complexity: O(n);
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
   unordered_map<ListNode *, int> s; // storing cound for each node
   ListNode *head2 = head;
   int i = 1;
   while (head2 != NULL)
   { // for list which is not cyclic
      if (s.find(head2) != s.end())
      { // detecting Cycle if the node is present in the map then it will return the node.
         return head2;
      }
      s[head2] = i;
      head2 = head2->next;
      i++;
   }
   return head2; // this will only happen if the list is not circular or it is having some end point.
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