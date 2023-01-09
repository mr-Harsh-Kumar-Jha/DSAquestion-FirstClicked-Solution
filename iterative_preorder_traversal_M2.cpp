#include <bits/stdc++.h>
using namespace std;

struct TreeNode{ // declared in order to construct tree using linkedlist .
   int val;
   TreeNode *right = NULL;
   TreeNode *left = NULL;
};

stack<TreeNode *> store;
vector<int> preorderTraversal(TreeNode *root){
   vector<int> ans;
   TreeNode *temp = NULL; //this is created to keep track of visited node so that again that node is not traverced .
   if (root != NULL){
      ans.push_back(root->val);
      store.push(root);
      while (store.size() != 0){
         while (root->left != NULL && root != temp){
            temp = root;
            root = root->left;
            ans.push_back(root->val);
            store.push(root);
         }
         root = store.top();
         temp = root;
         store.pop();
         if (root->right != NULL){
            root = root->right;
            ans.push_back(root->val);
            store.push(root);
         }
      }
   }
   return ans;
}

int main(){
   TreeNode *Head = new TreeNode();
   TreeNode *second = new TreeNode();
   TreeNode *third = new TreeNode();
   TreeNode *forth = new TreeNode();
   TreeNode *fifth = new TreeNode();
   TreeNode *sixth = new TreeNode();
   TreeNode *seventh = new TreeNode();
   TreeNode *eighth = new TreeNode();

   Head->val = 4;
   Head->left = second;
   Head->right = third;
   second->val = 5;
   second->left = forth;
   third->val = 6;
   third->right = fifth;
   forth->val = 7;
   forth->left = seventh;
   forth->right = sixth;
   fifth->val = 8;
   fifth->right = eighth;
   sixth->val = 9;
   seventh->val = 1;
   eighth->val = 0;
   vector<int> vec = preorderTraversal(Head);
   for (int i = 0; i < vec.size(); i++){
      cout << vec[i] << " ";
   }
   cout << endl;
}