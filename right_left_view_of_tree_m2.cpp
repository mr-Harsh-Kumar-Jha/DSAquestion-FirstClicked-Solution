#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

void rightViewTraversal(node*root,int level,vector<int>&ans){
   if(root==NULL) return;
   if(level==ans.size()) ans.push_back(root->data);
   rightViewTraversal(root->right,level+1,ans);
   rightViewTraversal(root->left,level+1,ans);
}

void leftViewTraversal(node*root,int level, vector<int>&ans){
   if(root==NULL) return;
   if(level==ans.size()) ans.push_back(root->data);
   leftViewTraversal(root->left,level+1,ans);
   leftViewTraversal(root->right,level+1,ans);
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
   vector<int>ans;
   leftViewTraversal(Head1,0,ans);
  for(int i=0;i<ans.size();i++){
   cout<<ans[i]<<" ";
  }
  cout<<endl;
}