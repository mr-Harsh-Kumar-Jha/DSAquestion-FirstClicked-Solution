#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a > b)? a : b;
}

struct AVLTree{
   int data;
   AVLTree* left = NULL;
   AVLTree* right = NULL;
   int height = 1;
};

int height(AVLTree* node){
   if(node==NULL) return 0;
   return node->height;
}

int balanceFactor(AVLTree* node){
   if(node==NULL){
      return 0;
   }
   return height(node->left) - height(node->right);
}

AVLTree*  leftRotate(AVLTree* node){
   auto temp1 = node->right;
   auto temp2 = temp1->left;

   temp1->left = node;
   node->right = temp2;

   node->height = 1+max(height(node->left), height(node->right));
   temp1->height = 1+max(height(temp1->left), height(temp1->right));

   return temp1;
}

AVLTree* rightRotate(AVLTree* node){
   auto temp1 = node->left;
   auto temp2 = temp1->right;

   temp1->right = node;
   node->left = temp2;

   node->height = 1+max(height(node->left), height(node->right));
   temp1->height = 1+max(height(temp1->left), height(temp1->right));

   return temp1;
}

AVLTree* insertAfterDelete(AVLTree* node, AVLTree* root){
   if(root==NULL){
      root = node;
   }else{
       root->left = insertAfterDelete(node, root->left);
   }

   root->height = 1+max(height(root->left),height(root->right));
   int balance = balanceFactor(root);
   if(balance > 1 && node->data < root->left->data ){
      return rightRotate(root);
   }

   if(balance < -1 && node->data > root->right->data){
      return leftRotate(root);
   }

   if(balance > 1 && node->data > root->left->data){
      root->left = leftRotate(root->left);
      return rightRotate(root);
   }

    if(balance < -1 && node->data < root->right->data){
      root->right = rightRotate(root->right);
      return leftRotate(root);
   }

   return root;
}

AVLTree* deleNode(int data, AVLTree* Head){
   if(Head==NULL) return Head;
   if(data > Head->data){
      Head->right = deleNode(data, Head->right);
   }else if(data<Head->data){
       Head->left = deleNode(data, Head->left);
   }else{
      AVLTree* temp1 = Head->left!=NULL?Head->left->right:NULL;
      AVLTree* temp2 = Head->left!=NULL?Head->right:NULL;
      if(Head->left!=NULL) Head = Head->left;
      else Head = Head->right;
      if(temp2!=NULL) Head->right = temp2;
      if(temp1!=NULL) Head->right = insertAfterDelete(temp1, Head->right);
   }

   if(Head!=NULL){

      Head->height = 1+max(height(Head->left),height(Head->right));
      int balance = balanceFactor(Head);
      if(balance > 1 && balanceFactor(Head->left)>=1){
         return rightRotate(Head);
      }

      if(balance < -1 && balanceFactor(Head->right)<=-1){
         return leftRotate(Head);
      }

      if(balance > 1 && balanceFactor(Head->left)<=-1){
         Head->left = leftRotate(Head->left);
         return rightRotate(Head);
      }

      if(balance < -1 && balanceFactor(Head->right)>=1){
         Head->right = rightRotate(Head->right);
         return leftRotate(Head);
      }
   }

   return Head;
}

AVLTree* insertNode(int data, AVLTree* head){
   if(head==NULL){
      AVLTree* temp = new AVLTree;
      temp->data = data;
      head = temp;
   }
   if(data>head->data){
     head->right =  insertNode(data, head->right);
   }else if(data<head->data){
      head->left = insertNode(data, head->left);
   }else return head;

   head->height = 1+max(height(head->left),height(head->right));

   int balance = balanceFactor(head);

   if(balance > 1 && data < head->left->data){
      return rightRotate(head);
   }

   if(balance < -1 && data >  head->right->data){
      return leftRotate(head);
   }

   if(balance > 1 && data > head->left->data){
      head->left = leftRotate(head->left);
      return leftRotate(head);
   }

   if(balance < -1 && data < head->right->data){
      head->right = rightRotate(head->right);
      return leftRotate(head);
   }

   return head;
}

void preOrder(AVLTree *root){
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    AVLTree *root = NULL;

    /* Constructing tree given in
    the above figure */
    root = insertNode(10, root);
    root = insertNode(20, root);
    root = insertNode(30, root);
    root = insertNode(40, root);
    root = insertNode(50, root);
    root = insertNode(25, root);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
    cout<<endl;

    root = deleNode(40, root);
    preOrder(root);

    return 0;
}