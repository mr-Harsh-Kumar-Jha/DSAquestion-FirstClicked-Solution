// Time complexity is O(n)

#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

bool check(node* head1, node* head2){
   if(head1==head2){  // this is possible only when both are pointing to NULL
      return true;
   }
   else if(head1==NULL || head2==NULL){
      return false;
   }
   bool lh = check(head1->left,head2->left) ;
   bool rh =check(head1->right,head2->right);
   if((head1->data==head2->data) && lh && rh) {
      return true;
   }
   else{
      return false;
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

   struct node* Head2 = new struct node();
   node* second2 = new struct node();
   node* third2 = new struct node();
   node* forth2 = new struct node();
   node * fifth2 = new struct node();
   node* sixth2 = new struct node();
   node* seventh2 = new struct node();
   node* eighth2 = new struct node();

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

   Head2->data=4;
   Head2->left=second2;
   Head2->right=third2;
   second2->data=5;
   second2->left=forth2;
   third2->data=6;
   third2->right=fifth2;
   forth2->data=7;
   forth2->left=seventh2;
   forth2->right=sixth2;
   fifth2->data=8;
   fifth2->right=eighth2;
   sixth2->data=9;
   seventh2->data=1;
   eighth2->data=0;

   if(check(Head1,Head2)==1) cout<<"they are identical"<<endl;
   else cout<<"they are not identical"<<endl;

}