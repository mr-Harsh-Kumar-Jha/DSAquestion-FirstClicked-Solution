#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
      data = value;
      left = NULL;
      right = NULL;
    }
};

void childNode(Node*root,int distance,vector<Node*>&ans){
   if(distance == 0){
      ans.push_back(root);
      return;
   }
   if(root->left!=NULL) childNode(root->left,distance-1,ans);
   if(root->right!=NULL) childNode(root->right,distance-1,ans);
}

void findNode(Node* root, Node* prevRoot, int dist, vector<Node*>&ans, map<Node*,Node*>&map){
   while(root!=NULL){
      if(root==prevRoot) childNode(root, dist, ans);
      if(root!=prevRoot){
         dist = dist-1;
         if(dist!=0 && root->left == prevRoot) childNode(root->right, dist-1, ans);
         else if(dist!=0 && root->right == prevRoot) childNode(root->left, dist-1, ans);
         else{
            ans.push_back(root);
         }
      }
      prevRoot = root;
      root = map[root];
   }

}

void printkdistanceNode(Node* root, Node*target, int dist){
   map<Node*,Node*>map;
   queue<Node*>queue;
   queue.push(root);
   map[root] = NULL;
   while(!queue.empty()){
      Node* top = queue.front();
      queue.pop();
      if(top->left!=NULL){
         queue.push(top->left);
         map[top->left] = top;
      }
      if(top->right!=NULL){
         queue.push(top->right);
         map[top->right] = top;
      }
   }

   vector<Node*>ans;
   findNode(target, target, dist, ans, map);
   if(ans.size()==0) cout<<"no such element present";
   else{
      for(auto it:ans){
         cout<<it->data<<" ";
      }
   }
   cout<<endl;
}

int main(){
   Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    Node* target = root->left->left;
    printkdistanceNode(root, target, 3);
}