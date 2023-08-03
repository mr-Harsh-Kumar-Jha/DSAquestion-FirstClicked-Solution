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

int ceil(node* root, int i){
   int ceil = -1;
   while(root!=NULL){
      if(root->key==i){
         ceil = root->key;
         return ceil;
      }else{
         if(root->key>i){
           ceil = root->key;
           root = root->left;
         }else{
            root = root->right;
         }
      }
   }
   return ceil;
}

int main(){

    node* root = newNode(8);

    root->left = newNode(4);
    root->right = newNode(12);

    root->left->left = newNode(2);
    root->left->right = newNode(6);

    root->right->left = newNode(10);
    root->right->right = newNode(14);

    for (int i = 0; i < 16; i++)
        cout << i << " " << ceil(root, i)<< endl;
}