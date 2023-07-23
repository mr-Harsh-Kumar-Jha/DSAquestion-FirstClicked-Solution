#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

int findLeftHeight(node* root){
   int count = 0;
   while(root){
      count++;
      root = root->left;
   }
   return count;
}

int findRightHeight(node* root){
   int count = 0;
   while(root){
      count++;
      root = root->right;
   }
   return count;
}

int TotalNodes(node* root){
   if(root==NULL){
      return 1;
   }

   int lh = findLeftHeight(root);
   int rh = findRightHeight(root);

   if(lh==rh) return (1<<lh)-1;

   return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}

int main(){
   node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(9);
    root->right->right = newNode(8);
    root->left->left->left = newNode(6);
    root->left->left->right = newNode(7);
    cout << TotalNodes(root)<<endl;
}

            //           1
            //       2      3
            //    4   5 9   8
            // 6   7

