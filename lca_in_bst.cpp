#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* newNode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return (Node);
}

node* findLCA(node* root, node* p, node* q){
   if(root==NULL) return NULL;
   if(root->data > p->data && root->data > q->data) root =  findLCA(root->left, p, q);
   if(root->data < p->data && root->data < q->data) root =  findLCA(root->right, p, q);
   return root;
}

int main(){
   node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    node* ans = findLCA(root, root->left->right->left, root->left->right->right);
    cout<<ans->data<<endl;
}