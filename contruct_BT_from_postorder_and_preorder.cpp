#include<bits/stdc++.h>
using namespace std;

int k;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int find(int* in, int i, int j, int target){
   for(int l = 0; l<=j; l++){
      if(in[l] == target){
         return l;
      }
   }
   return -1;
}

Node* calculation(int* in, int* post, int i, int j){
   Node* temp = newNode(post[k]);
   int elemLocation = find(in, i, j, post[k]);
   k-=1;
   if(j-i<=0){
      if(j-i == 0){
         return temp;
      }
      return NULL;
   }

   temp->right = calculation(in, post, elemLocation+1, j);
   temp->left = calculation(in, post, i, elemLocation-1);
   return temp;
}

Node* buildTree(int* in, int* post, int& n){
   Node* temp = newNode(post[k]);
   int elemLocation = find(in, 0 , n-1, post[k]);
   k-=1;
   temp->right = calculation(in, post ,elemLocation+1, n-1);
   temp->left = calculation(in, post, 0, elemLocation-1);
   return temp;
}

void preOrder(Node* node){
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node* node){
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<" ";
}

int main(){
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(in) / sizeof(in[0]);
   k = n-1;
    Node* root = buildTree(in, post, n);
    postOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
}