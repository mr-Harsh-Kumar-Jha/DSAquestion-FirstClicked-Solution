// time complexity is O(n*n) .

#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

int maxi = INT_MIN;

int findHeight(node*head){
   if(head==NULL) return 0;
   int lh = findHeight(head->left);
   int rh = findHeight(head->right);

   return 1+max(lh,rh);
}

void check(node* head, int& maxi){
   if(head==NULL){
      return;
   }
   int lh = findHeight(head->left);
   int rh = findHeight(head->right);

   maxi = max((lh+rh),maxi);

   check(head->left,maxi);
   check(head->right,maxi);
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

   int maxi = INT_MIN;
   check(Head,maxi);
   cout<<maxi<<endl;
}