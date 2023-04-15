#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

void printPre(vector<int>&pre){
   cout<<"preOrder Travesesal"<<"--- ";
   for(int i=0;i<pre.size();i++){
      cout<<pre[i]<<", ";
   }
   cout<<endl;
}

void printPost(vector<int>&post){
   cout<<"postOrder Travesesal"<<"--- ";
   for(int i=0;i<post.size();i++){
      cout<<post[i]<<", ";
   }
   cout<<endl;
}

void printIn(vector<int>&in){
   cout<<"inOrder Travesesal"<<"--- ";
   for(int i=0;i<in.size();i++){
      cout<<in[i]<<", ";
   }
   cout<<endl;
}

void allinOneTraversal(node* head){
   stack<pair<node*,int>>st;
   vector<int>pre,post,in;
   st.push({head,1});
   while(!st.empty()){
      pair<node*,int>temp = st.top();
      st.pop();
      if(temp.first!=NULL && temp.second==1){
         temp.second+=1;
         pre.push_back(temp.first->data);
         st.push(temp);
         if(temp.first->left!=NULL){
            st.push({temp.first->left,1});
         }
      }
      else if(temp.first!=NULL && temp.second==2){
         temp.second+=1;
         in.push_back(temp.first->data);
         st.push(temp);
         if(temp.first->right!=NULL){
            st.push({temp.first->right,1});
         }
      }
      else{
         post.push_back(temp.first->data);
      }
   }
   printPre(pre);
   printPost(post);
   printIn(in);
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
   cout<<"hiii"<<endl;
  allinOneTraversal(Head);
}