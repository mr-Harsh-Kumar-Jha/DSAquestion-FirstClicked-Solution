// time complexity is O(N) and space complexity is O(1)
// the greater diffrentiater is space complexity i.e constant

#include <bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   Node *left, *right;
};

Node *newNode(int data){
   Node *node = (Node *)malloc(sizeof(Node));
   node->data = data;
   node->left = node->right = NULL;
   return (node);
}

//----------this is an inorder traversal-------------//
vector<int> morrisTraversalInorder(Node *root){
   vector<int> inOrder;
   Node *curr = root;
   while (curr != NULL){
      if (curr->left == NULL){
         inOrder.push_back(curr->data);
         curr = curr->right;
      }
      else{
         Node *prev = curr->left;
         while (prev->right && prev->right != curr){
            prev = prev->right;
         }
         if (prev->right == NULL){
            prev->right = curr;
            curr = curr->left;
         }
         else{
            inOrder.push_back(curr->data);
            curr = curr->right;
            prev->right = NULL;
         }
      }
   }
   return inOrder;
}

//--------------this is an preorder traversal-----------------//
vector<int> morrisTraversalPreOrder(Node *root){
   vector<int> preOrder;
   Node *curr = root;
   while (curr != NULL){
      if (curr->left == NULL){
         preOrder.push_back(curr->data);
         curr = curr->right;
      }
      else{
         Node *prev = curr->left;
         while (prev->right && prev->right != curr){
            prev = prev->right;
         }
         if (prev->right == NULL){
            prev->right = curr;
            preOrder.push_back(curr->data);
            curr = curr->left;
         }
         else{
            curr = curr->right;
            prev->right = NULL;
         }
      }
   }
   return preOrder;
}

//--------------this is an postorder traversal-----------------//
vector<int> morrisTraversalPostOrder(Node *root){
   vector<int> postOrder;
   Node *curr = root;
   while (curr != NULL){
      if (curr->right == NULL){
         postOrder.push_back(curr->data);
         curr = curr->left;
      }
      else{
         Node *prev = curr->right;
         while (prev->left && prev->left != curr){
            prev = prev->left;
         }
         if (prev->left == NULL){
            prev->left = curr;
            postOrder.push_back(curr->data);
            curr = curr->right;
         }
         else{
            curr = curr->left;
            prev->left = NULL;
         }
      }
   }
   reverse(postOrder.begin(), postOrder.end());
   return postOrder;
}

int main()
{
   Node *root = NULL;

   root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   root->right->left = newNode(6);
   root->right->right = newNode(7);
   root->left->left->left = newNode(8);
   root->left->left->right = newNode(9);
   root->left->right->left = newNode(10);
   root->left->right->right = newNode(11);

   vector<int> ans = morrisTraversalInorder(root);
   for (auto it : ans)
   {
      cout << it << " ";
   }
   cout << endl;

   vector<int> ans2 = morrisTraversalPreOrder(root);
   for (auto it : ans2)
   {
      cout << it << " ";
   }
   cout << endl;
   vector<int> ans3 = morrisTraversalPostOrder(root);
   for (auto it : ans3)
   {
      cout << it << " ";
   }
   cout << endl;
}