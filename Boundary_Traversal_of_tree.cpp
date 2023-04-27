#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

bool isLeaf(node*curr){
   if(curr->left==NULL && curr->right==NULL) return true;
   return false;
}

void leftBoundry(node*head, vector<int>&res){
   node* curr = head->left;
   while(curr){
      if(!isLeaf(curr)) res.push_back(curr->data);
      if(curr->left) curr = curr->left;
      else curr = curr->right;
   }
}

void leafNode(node* head,vector<int>&res){
      if(isLeaf(head)){
         res.push_back(head->data);
         return;
      }
      if(head->left) leafNode(head->left,res);
      if(head->right) leafNode( head->right,res);
}

void rightBoundry(node* head,vector<int>&res){
   node* curr = head->right;
   vector<int>temp;
   while(curr){
      if(!isLeaf(curr)) temp.push_back(curr->data);
      if(curr->right) curr = curr->right;
      else curr = curr->left;
   }
   for(int i=0;i<temp.size();i++){
      res.push_back(temp[temp.size()-i-1]);
   }
}

vector<int> BoundaryTraversal(node*head){
   vector<int>res;
   if(!head) return res;
   if(!isLeaf(head)) res.push_back(head->data);
   leftBoundry(head,res);
   leafNode(head,res);
   rightBoundry(head,res);
   return res;
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

   vector<int> ans = BoundaryTraversal(Head1);
   for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
   }
   cout<<endl;
}