// time complexity of the solution is O(n) and space complexity is O(n) auxilliary space.

#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

int checkBalancedBTree(node* head){
   if(head==NULL) return 0;
   int lh = checkBalancedBTree(head->left);
   if(lh==-1) return -1;
   int rh = checkBalancedBTree(head->right);
   if(rh==-1) return -1;

   if(abs(lh-rh)>1) return -1;
   return 1+max(lh,rh);
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
   // node* ninth = new struct node();

   Head->data=4;
   Head->left=second;
   Head->right=third;
   second->data=5;
   second->right= eighth;
   second->left=forth;
   third->data=6;
   third->right=fifth;
   forth->data=7;
   forth->left=seventh;
   forth->right=sixth;
   fifth->data=8;
   sixth->data=9;
   seventh->data=1;
   eighth->data=0;
   // ninth->data = 2;
   if(checkBalancedBTree(Head)==-1){
      cout<<"No the tree is not a balanced Binary Tree"<<endl;
   }else cout<<"Yes the tree is a balanced Binary Tree"<<endl;
}