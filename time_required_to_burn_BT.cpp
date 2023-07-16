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

void findNode(Node* root, int& time, unordered_map<Node*,Node*>&map){
   unordered_map<Node*,bool> visited;
   queue<Node*> ans;
   ans.push(root);
   visited[root] = true;
   while(!ans.empty()){
      int size = ans.size();
       int fl = 0;
      for(int i = 0;i<size;i++){
         Node* current = ans.front();
         ans.pop();
         if(current->left && !visited[current->left]){
            fl = 1;
            visited[current->left] = true;
            ans.push(current->left);
         }

         if(current->right && !visited[current->right]){
            fl = 1;
            visited[current->right] = true;
            ans.push(current->right);
         }

         if(map[current] && !visited[map[current]]){
            fl = 1;
            visited[map[current]] = true;
            ans.push(map[current]);
         }
      }
      if(fl) time++;
   }
}

void findParentNode(Node* root, Node*target){
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

   int time = 0;
   findNode(target, time, map);

   cout<<"time required to burn the tree will be -> "<<time<<endl;
}

int main(){
   Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    Node* target = root->left;
    findParentNode(root, target);
}