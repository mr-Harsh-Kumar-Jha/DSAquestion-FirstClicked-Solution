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

class NodeValue{
   public:
      int maxNode, minNode, maxSize;

      NodeValue(int minNode, int maxNode, int maxSize){
         this->maxNode = maxNode;
         this->minNode = minNode;
         this->maxSize = maxSize;
      }
};

class Solution{
   private:
      NodeValue largestBSTSubtreeHelper(Node* root){
         if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
         }

         auto left = largestBSTSubtreeHelper(root->left);
         auto right = largestBSTSubtreeHelper(root->right);

         //currejt node greater than maxNode of left and smaller than minNode of right
         if(left.maxNode < root->data && root->data < right.minNode){
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
         }

         return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
      }
   public:
      int largestBSTSubtree(Node* root){
         return largestBSTSubtreeHelper(root).maxSize;
      }
};

int main(){
    /* Let us construct the following Tree
        60
       /  \
      65  70
     /
    50 */

    struct Node* root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);
    Solution target;
    cout<<"Size of the largest BST is "<< target.largestBSTSubtree(root)<<endl;
    return 0;
}