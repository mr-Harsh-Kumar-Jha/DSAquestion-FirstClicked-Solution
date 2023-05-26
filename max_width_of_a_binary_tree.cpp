#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

int maxWidthBinaryTree(node* head){
   queue<pair<node*,int>>queue;
   queue.push({head,1});
   int level2 = 0;
   int maxi = 1;
   while(!queue.empty()){
      pair<node*,int>temp = queue.front();
      if(temp.second==1) {
         level2++;
         maxi = max(maxi,queue.back().second-temp.second+1);
      }
      queue.pop();
      if(temp.first->left!=NULL){
         queue.push({temp.first->left,(2*(temp.second-1))+1});
      }
      if(temp.first->right!=NULL){
         queue.push({temp.first->right,(2*(temp.second-1))+2});
      }
   }
   return maxi;
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
   cout<< maxWidthBinaryTree(Head1)<<endl;
}