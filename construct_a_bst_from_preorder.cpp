#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

// A utility function to create a node
node* newNode(int data){
   node* temp = new node();
   temp->data = data;
   temp->left = temp->right = NULL;
   return temp;
}

void printInorder(node* node){
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

node* solve(int* pre, int& i, int bound, int size){
   if(i==size || pre[i]>bound) return NULL;
   node* root = newNode(pre[i++]);
   root->left = solve(pre, i, root->data, size);
   root->right = solve(pre, i, bound, size);
   return root;
}

node* constructTree(int* pre, int size){
   int i = 0;
   return solve(pre, i, INT_MAX, size);
}

int main(){
   int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);

      // Function call
    node* root = constructTree(pre, size);

    printInorder(root);
}