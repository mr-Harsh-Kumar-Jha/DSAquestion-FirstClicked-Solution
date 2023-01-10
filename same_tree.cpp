#include<bits/stdc++.h>
using namespace std;

struct TreeNode{ // declared in order to construct tree using linkedlist .
   int val;
   TreeNode *right = NULL;
   TreeNode *left = NULL;
};

bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p!=NULL && q!=NULL && p->val!=q->val) return false;
      if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) return false;
      if(p==NULL && q==NULL) return true;
      bool ans = isSameTree(p->left , q->left);
      if(ans==false) return false;
      bool ans2 = isSameTree(p->right , q->right);
      if(ans2==false) return false;
      return true;
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

   TreeNode *q = new TreeNode();
   TreeNode *second2 = new TreeNode();
   TreeNode *third2 = new TreeNode();
   TreeNode *forth2 = new TreeNode();
   TreeNode *fifth2 = new TreeNode();
   TreeNode *sixth2 = new TreeNode();
   TreeNode *seventh2 = new TreeNode();
   TreeNode *eighth2 = new TreeNode();

   q->val = 4;
   q->left = second2;
   q->right = third2;
   second2->val = 5;
   second2->left = forth2;
   third2->val = 6;
   third2->right = fifth2;
   forth2->val = 7;
   forth2->left = seventh2;
   forth2->right = sixth2;
   fifth2->val = 1;
   fifth2->right = eighth2;
   sixth2->val = 9;
   seventh2->val = 1;
   eighth2->val = 0;

   cout<<isSameTree(Head , q)<<endl;
}