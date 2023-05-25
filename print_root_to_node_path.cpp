#include<bits/stdc++.h>
using namespace std;

vector<int>vec;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

bool printPath(node* root, int data){
   if(root!=NULL && root->data==data){
      vec.push_back(root->data);
      return true;
   }
   if(root==NULL) return false;

   vec.push_back(root->data);

   bool left=printPath(root->left,data);
   bool right=printPath(root->right,data);
   if(!left && !right){
      vec.pop_back();
      return false;
   }

   return right || left;
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
   if(printPath(Head1,8)){
      for(int i=0;i<vec.size();i++){
         std::cout<<vec[i]<<" ";
      }
      std::cout<<endl;
   }
}