#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return (node);
}

class Solution{
  private:
   int  count = 0;
   int count2 = 0;
   bool solve(Node* root){
      if(!root) return true;
      bool left = solve(root->left);
      if(left){
          if(root->left && root->data < root->left->data){
            left = false;
            count2 = 0;
         }else{
            left = true;
         }
      }
      bool right = solve(root->right);
       if(right){
          if(root->right && root->data > root->right->data){
            right = false;
            count2 = 0;
         }else{
            right = true;
         }
      }
      if(left && right){
         count2++;
         count = max(count2, count);
         return true;
      }
      count2 = 0;
      return false;
   }

   public:
      int largestBSTSubtree(Node* root){
         solve(root);
         return count;
      }

};

int main(){
    /* Let us construct the following Tree
        60
       /  \
   65  70
        /
      65   */

    struct Node* root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);
    Solution target;
    cout<<"Size of the largest BST is "<< target.largestBSTSubtree(root)<<endl;
    return 0;
}