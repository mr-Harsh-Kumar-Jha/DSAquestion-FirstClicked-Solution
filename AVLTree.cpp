#include<bits/stdc++.h>
using namespace std;

struct AVLTree{
   int data;
   AVLTree* left = NULL;
   AVLTree* right = NULL;
   int height = 0;
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

void deleNode(int data, AVLTree* Head){
   if(Head == NULL){
      cout<<"The Tree is empty"<<endl;
      return;
   }

   while(Head!=NULL){
      if( data>Head->data){
         Head = Head->right;
      }else if( data<Head->data){
         Head = Head->left;
      }else{
         AVLTree* temp1 = Head->left;
         AVLTree* temp2 = Head->left->right;

         temp1->right = Head->right;
         Head = temp1;
         if(temp2!=NULL){
            temp1 = Head->right;
            temp1->height += temp2->height;
            while(temp1->left!=NULL){
               temp1 = temp1->left;
               temp1->height += temp2->height;
            }
            temp1->left = temp2;
            Head->height = 1+temp2->height;
            break;
         }
      }
   }
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
   }else return;

   head->height = 1+max(height(head->left),height(head->right));

   int balance = balanceFactor(head);

   if(balance > 1 && data < head->left->data){
      return rightRotate(head);
   }
   if(balance > 1 && data > head->left->data){
      head->right = leftRotate(head->left);
      return leftRotate(head);
   }
    if(balance < -1 && data >  head->right->data){
      return leftRotate(head);
   }
   if(balance < -1 && data < head->right->data){
      head = rightRotate(head);
      return leftRotate(head);
   }

   return head;
}