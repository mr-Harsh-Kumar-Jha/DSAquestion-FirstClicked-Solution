// this is a postOrder traversal using two stack
// Here method is very simple as the stack 1 is used to find the left and right child of the node and when these chlids are passed in stack 1 where as parents are transfered in stack 2 . this results in the reverse order of traversal to make it straight we have to print stack 2 in reverse order

#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

void postOrder(node* head){
   if(head==NULL) return;
   stack<node*>st1,st2;
   st1.push(head);
   while(!st1.empty()){
      head = st1.top();
      st2.push(head);
      st1.pop();
      if(head->left!=NULL) st1.push(head->left);
      if(head->right!=NULL) st1.push(head->right);
   }
   while(!st2.empty()){
      cout<<st2.top()->data<<" ";
      st2.pop();
   }
}

int main(){
   struct node* Head = new struct node();
   node* second = new struct node();
   node* third = new struct node();
   node* forth = new struct node();
   node * fifth = new struct node();
   node* sixth = new struct node();
   node* seventh = new struct node();
   node* eighth = new struct node();

   Head->data=4;
   Head->left=second;
   Head->right=third;
   second->data=5;
   second->left=forth;
   third->data=6;
   third->right=fifth;
   forth->data=7;
   forth->left=seventh;
   forth->right=sixth;
   fifth->data=8;
   fifth->right=eighth;
   sixth->data=9;
   seventh->data=1;
   eighth->data=0;
   postOrder(Head);
}