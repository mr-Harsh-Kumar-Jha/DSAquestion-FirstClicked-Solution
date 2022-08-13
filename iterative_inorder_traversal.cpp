#include<bits/stdc++.h>

using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

void inorder(node* head){
   stack<node*>st;
   st.push(head);
   while(st.size()){
      node* temp=st.top();
      if(temp->left==NULL){
         cout<<temp->data<<" ";
      }
       if(temp->left!=NULL){
         st.push(temp->left);
         temp->left=NULL;
      }
      else {
         st.pop();
         if(temp->right!=NULL){
            st.push(temp->right);
         }
      }
   }
}

void postorder(node* head){
   stack<node*>st;
   st.push(head);
   node* temp;
   while(st.size()){
      temp=st.top();
      if(temp->left!=NULL){
         st.push(temp->left);
         temp->left=NULL;
      }
      else{
         if(temp->right!=NULL){
            st.push(temp->right);
            temp->right=NULL;
         }
         else{
            st.pop();
            cout<<temp->data<<" ";
         }
      }
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
   postorder(Head);
}