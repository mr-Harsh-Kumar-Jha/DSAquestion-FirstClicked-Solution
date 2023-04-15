#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

void postOrder(node* Head){
   stack<node*>st;
   queue<int>ans;
   node* curr = Head;
   while(!st.empty() || curr!=NULL){
      if(curr!=NULL){
         st.push(curr);
         curr = curr->left;
      }
      else{
         node* temp = st.top()->right;
         if(temp==NULL){
            temp = st.top();
            st.pop();
            ans.push(temp->data);
            while(!st.empty() && temp==st.top()->right){
               temp = st.top();
               st.pop();
               ans.push(temp->data);
            }
         }
         else curr = temp;
      }
   }
   while(!ans.empty()){
      cout<<ans.front()<<" ";
      ans.pop();
   }
   cout<<endl;
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