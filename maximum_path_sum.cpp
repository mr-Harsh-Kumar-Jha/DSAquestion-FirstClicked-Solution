// time complexity is O(n) and space complexity is O(n) 

#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

int maximumPathSum(node* head, int& maxi){
   if(head==NULL) return 0;
   int lh = maximumPathSum(head->left,maxi);
   int rh = maximumPathSum(head->right,maxi);

   maxi = max(maxi,(lh+rh+head->data));
   return head->data+max(lh,rh);
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
   maximumPathSum(Head,maxi);
   cout<<maxi<<endl;
}