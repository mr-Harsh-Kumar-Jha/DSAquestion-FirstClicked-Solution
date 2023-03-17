// in this solution the original tree does not change and therefore pe can perform any further operation on the tree and this is considered to be the best solution and the interviewer accepts the same perticular solution .

#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

void preOrder(node* head){
   if(head == NULL) return;
   stack<node*>st;
   st.push(head);
   while(!st.empty()){
      head = st.top();
      st.pop();
      cout<<head->data<<" ";
      if(head->right != NULL) st.push(head->right);
      if(head->left != NULL) st.push(head->left);
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
   preOrder(Head);
}