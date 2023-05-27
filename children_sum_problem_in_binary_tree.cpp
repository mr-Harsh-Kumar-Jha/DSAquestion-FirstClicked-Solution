#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

int childrenSumProblem(node*root){
   if(root==NULL) return 0;
   int child = 0;

   if(root->left!=NULL) child+=root->left->data;
   if(root->right!=NULL) child+=root->right->data;

   if(child>root->data) root->data = child;
   else{
      if(root->left) root->left->data = root->data;
      else if(root->right) root->right->data = root->data;
   }

   childrenSumProblem(root->left);
   childrenSumProblem(root->right);

  if(root->left!=NULL && root->right!=NULL) root->data = root->left->data+root->right->data;
   else if(root->left!=NULL && root->right==NULL){
      if(root->left->data < root->data) {
         node*temp1 = new node();
         temp1->data = root->left->data-root->data;
         root->right = temp1;
      }
      else{
         root->data = root->left->data;
      }
   }else if(root->right!=NULL && root->left==NULL){
      if(root->right->data < root->data) {
         node*temp1 = new node();
         temp1->data = root->right->data-root->data;
         root->left = temp1;
      }
      else{
         root->data = root->right->data;
      }
   }
}

int main(){
   struct node* Head1 = new struct node();
   node* second1 = new struct node();
   node* third1 = new struct node();
   node* forth1 = new struct node();
   node * fifth1 = new struct node();
   node* sixth1 = new struct node();
   node* seventh1 = new struct node();
   node* eighth1 = new struct node();
   node* nine1 = new struct node();
   node* ten1 = new struct node();
   node* eleven1 = new struct node();

   Head1->data=44;
   Head1->left=second1;
   Head1->right=third1;
   second1->data=5;
   second1->left=forth1;
   second1->right=nine1;
   third1->data=36;
   third1->right=fifth1;
   third1->left=ten1;
   forth1->data=7;
   forth1->left=seventh1;
   forth1->right=sixth1;
   fifth1->data=16;
   fifth1->left=eleven1;
   fifth1->right=eighth1;
   sixth1->data=9;
   seventh1->data=1;
   eighth1->data=0;
   nine1->data=3;
   ten1->data=1;
   eleven1->data=4;
   childrenSumProblem(Head1);
   stack<node*>st;
   st.push(Head1);
   while(!st.empty()){
      node*temp = st.top();
      st.pop();
      cout<<temp->data<<" ";
      if(temp->right) st.push(temp->right);
      if(temp->left) st.push(temp->left);
   }
}