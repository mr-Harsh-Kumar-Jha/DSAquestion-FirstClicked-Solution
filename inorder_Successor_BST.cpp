//this is a recursive approach

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

node* inOrderSuccessor(node* succ, node* k, node* &ans){
   if(succ==NULL) return NULL;
   if(k->data == succ->data){
      if(succ->right==NULL) return ans;
      else{
         succ = succ->right;
         while(succ->left!=NULL){
            succ = succ->left;
         }
         ans = succ;
      }
   }else if(k->data > succ->data) inOrderSuccessor(succ->right, k, ans);
   else{
      ans = succ;
      inOrderSuccessor(succ->left, k, ans);
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
    node* ans = NULL;
    ans = inOrderSuccessor(root, k, ans);
   if (ans != NULL)
		cout << "Inorder Successor of " << k->data<< " is "<< ans->data<<endl;
	else
		cout <<"Inorder Successor doesn't exit"<<endl;
}