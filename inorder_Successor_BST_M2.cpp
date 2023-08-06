// this is a iterative approach

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(
            struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return (node);
}

struct node* insert(struct node* node, int data){
    /* 1. If the tree is empty, return a new,
      single node */
    if (node == NULL)
        return (newNode(data));
    else {
        struct node* temp;

        /* 2. Otherwise, recur down the tree */
        if (data <= node->data) {
            temp = insert(node->left, data);
            node->left = temp;
            temp->parent = node;
        }
        else {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }

        /* return the (unchanged) node pointer */
        return node;
    }
}

node* inOrderSuccessor(node* root, node* k){
   node* ans = NULL;
   while(root!=NULL){
      if(k->data >= root->data) root = root->right;
      else{
         ans = root;
         root = root->left;
      }
   }
   return ans;
}

int main(){
   struct node *root = NULL;

    // creating the tree given in the above diagram
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    node* k = root->left->right;
    node* ans = inOrderSuccessor(root, k);
   if (ans != NULL)
		cout << "Inorder Successor of " << k->data<< " is "<< ans->data<<endl;
	else
		cout <<"Inorder Successor doesn't exit"<<endl;
}