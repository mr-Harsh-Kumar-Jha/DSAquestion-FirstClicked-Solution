#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

node* lowestCommonAncestor(node*head, int a,int b){
   if(head==NULL || head->data==a || head->data==b) return head;

   node* left = lowestCommonAncestor(head->left,a,b);
   node* right = lowestCommonAncestor(head->right,a,b);

   if(left!=NULL&& right!=NULL){
      return head;
   }
   else if(left!=NULL){
      return left;
   }
   else return right;
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

   Head1->data=4;
   Head1->left=second1;
   Head1->right=third1;
   second1->data=5;
   second1->left=forth1;
   third1->data=6;
   third1->right=fifth1;
   forth1->data=7;
   forth1->left=seventh1;
   forth1->right=sixth1;
   fifth1->data=8;
   fifth1->right=eighth1;
   sixth1->data=9;
   seventh1->data=1;
   eighth1->data=0;
   node* ans = lowestCommonAncestor(Head1,8,1);
   cout<<ans->data<<endl;
}