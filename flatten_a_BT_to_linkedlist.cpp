// time complexity O(n)
//space complexity O(n)

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
   if(root->right==NULL || root->left==NULL){
      return;
   }
   flatten(root->right);
   flatten(root->left);
   Node* temp = root->right;
   root->right = root->left;
   root->left = NULL;
   Node* temp2 = root->right;
   while(temp2->right!=NULL){
      temp2 = temp2->right;
   }
   temp2->right = temp;
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