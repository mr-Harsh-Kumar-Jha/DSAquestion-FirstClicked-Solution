#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;
};

/* Helper function that allocates a new node with the given
key and NULL left and right pointers.*/
node* newNode(int key)
{
    node* Node = new node();
    Node->key = key;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

bool checkForBSTorBT(node* root, int i, int j){
   if(root==NULL) return true;
   bool left = false;
   bool right = false;
   if(root->key >=i && root->key<=j){
      left = checkForBSTorBT(root->left, i, root->key);
      right = checkForBSTorBT(root->right, root->key, j);
   }
   return left && right;
}

int main(){
   node* root = newNode(8);

    root->left = newNode(4);
    root->right = newNode(12);

    root->left->left = newNode(2);
    root->left->right = newNode(5);

    root->right->left = newNode(10);
    root->right->right = newNode(13);

    bool ans = checkForBSTorBT(root, INT_MIN, INT_MAX);
   if(ans){
      cout<<"it is a BST"<<endl;
   }else{
      cout<<"it is a BT"<<endl;
   }
}