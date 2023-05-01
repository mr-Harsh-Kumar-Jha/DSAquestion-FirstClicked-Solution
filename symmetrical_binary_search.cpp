#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

bool symmetricTraversal(node*root1 , node*root2){
   if(root1==NULL || root2==NULL) return root1==root2;
   if(root1->data != root2->data ) return false;
   return (symmetricTraversal(root1->left,root2->right) && symmetricTraversal(root1->right, root2->left));
}

bool checkSymmetrical(node*root){
   return root==NULL || symmetricTraversal(root->left,root->right);
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
   node* ninth1 = new struct node();

   Head1->data=4;
   Head1->left=second1;
   Head1->right=third1;
   second1->data=5;
   second1->left=forth1;
   third1->data=5;
   third1->right=fifth1;
   forth1->data=7;
   forth1->left=seventh1;
   forth1->right=sixth1;
   fifth1->data=7;
   fifth1->right=eighth1;
   fifth1->left = ninth1;
   sixth1->data=9;
   seventh1->data=1;
   eighth1->data=1;
   ninth1->data = 9;

   cout<<checkSymmetrical(Head1)<<endl;
}