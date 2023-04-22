#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

vector<vector<int>> zigZagTraversal(node*head){
   vector<vector<int>>result;
   if(head==NULL) return result;
   queue<node*>st;
   st.push(head);
   bool leftToRight = true;
   while(!st.empty()){
      int size = st.size();
      vector<int>vec(size);
      for(int i = 0;i<size;i++){
         node* temp = st.front();
         st.pop();
         if(leftToRight == true){
            vec[i] = temp->data;
         }
         else vec[size-i-1] = temp->data;

         if(temp->left) st.push(temp->left);
         if(temp->right) st.push(temp->right);
      }
      leftToRight = !leftToRight;
      result.push_back(vec);
   }

   return result;
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

   vector<vector<int>> result = zigZagTraversal(Head1);
   for(int i=0;i<result.size();i++){
      for(int j = 0;j<result[i].size();j++){
         cout<<result[i][j]<<" ";
      }
      cout<<endl;
   }
}