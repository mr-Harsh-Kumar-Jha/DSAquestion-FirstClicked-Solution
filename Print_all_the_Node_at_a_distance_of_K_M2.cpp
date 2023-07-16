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

void findNode(Node* root, Node* prevRoot, int dist, vector<Node*>&ans, unordered_map<Node*,Node*>&map){
   unordered_map<Node*, bool> visited;
   queue<Node*> ansQueue;
   ansQueue.push(root);
   visited[root] = true;
   int current_level = 0;
   while(!ansQueue.empty()){
      int size = ansQueue.size();
      if(current_level++==dist){
         break;
      }
      for(int i=0;i<size;i++){
         Node* current = ansQueue.front();
         ansQueue.pop();
         if(current->left && !visited[current->left]){
            ansQueue.push(current->left);
            visited[current->left] = true;
         }
         if(current->right && !visited[current->right]){
            ansQueue.push(current->right);
            visited[current->right] = true;
         }
         if(map[current] && !visited[map[current]]){
            ansQueue.push(map[current]);
            visited[map[current]] = true;
         }
      }
   }

   while(!ansQueue.empty()){
      Node* current = ansQueue.front();
      ansQueue.pop();
      ans.push_back(current);
   }
}

void printkdistanceNode(Node* root, Node*target, int dist){
   unordered_map<Node*,Node*>map;
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
    Node* target = root->left->right;
    printkdistanceNode(root, target, 2);
}