#include<bits/stdc++.h>
using namespace std;

struct node{  // declared in order to construct tree using linkedlist .
  int data;
  node* right=NULL;
  node* left=NULL;
};

vector<int> topViewTraversal(node*root){
   map<int, map<int,multiset<int>>>map;
   queue<pair<node*,pair<int,int>>>queue;
   vector<int>ans;
   if(root==NULL) return ans;
   ans.push_back(root->data);
   queue.push({root,{0,0}});
   while(!queue.empty()){
      auto temp = queue.front();
      queue.pop();
      int x = temp.second.first;
      int y = temp.second.second;
      map[x][y].insert(temp.first->data);
      if(temp.first->left) queue.push({temp.first->left,{x-1,y+1}});
      if(temp.first->right) queue.push({temp.first->right,{x+1,y+1}});
   }

   for(auto it:map){
      for(auto itt:it.second){
         ans.push_back(*itt.second.begin());
         break;
      }
   }
   return ans;
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
  vector<int>ans= topViewTraversal(Head1);
  for(int i=0;i<ans.size();i++){
   cout<<ans[i]<<" ";
  }
  cout<<endl;
}