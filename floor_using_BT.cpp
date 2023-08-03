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

int floor(node* root, int i){
   int floor = -1;
   while(root!=NULL){
      if(i==root->key){
         floor = root->key;
         return floor;
      }
      else if(i > root->key){
         floor = root->key;
         root = root->right;
      }else{
         root = root->left;
      }
   }
   return floor;
}

int main(){

    node* root = newNode(8);

    root->left = newNode(4);
    root->right = newNode(12);

    root->left->left = newNode(2);
    root->left->right = newNode(16);

    root->right->left = newNode(10);
    root->right->right = newNode(24);

    for (int i = 0; i < 18; i++)
        cout << i << " " << floor(root, i)<< endl;
}