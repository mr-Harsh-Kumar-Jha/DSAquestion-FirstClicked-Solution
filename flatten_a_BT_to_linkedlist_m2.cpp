// time complexity O(n)
//space complexity O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

// utility that allocates a new Node with the given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

void flatten(Node* root){
   Node* curr = root;
   while(curr!=NULL){
      if(curr->left==NULL){
         curr = curr->right;
      }else{
         Node*prev = curr->left;
         while(prev->right!=NULL && prev->right != curr){
            prev = prev->right;
         }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            curr = curr->right;
      }
   }
}

int main(){
   Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);
    flatten(root);
    while(root!=NULL){
      cout<<root->key<<" ";
      root = root->right;
    }
}