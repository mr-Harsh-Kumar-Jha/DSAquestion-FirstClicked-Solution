#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree {

    // Root of BST
public:
    Node* root;

    // Constructor
    BinarySearchTree() { root = NULL; }
    /* A recursive function to insert a new key in BST */
    Node* insertRec(Node* root, int data)
    {

        /* If the tree is empty, return a new node */
        if (root == NULL) {
            root = new Node(data);
            return root;
        }

        /* Otherwise, recur down the tree */
        if (data < root->data)
            root->left = insertRec(root->left, data);
        else if (data > root->data)
            root->right = insertRec(root->right, data);

        return root;
    }

    // This method mainly calls insertRec()
    void insert(int key) { root = insertRec(root, key); }
};

class BSTIterator{
  stack<Node*> myStack;
  // reverse-> true -> before
  // reverse-> false -> next
   bool reverse = true;
   public:
      BSTIterator(Node* root, bool isReverse){
         reverse = isReverse;
         pushAll(root);
      }

      /** @return whether we Have a next smallest number **/
      bool hasNext(){
         return !myStack.empty();
      }

      /** @return the next smallest no **/
      int next(){
         Node *tmpNode = myStack.top();
         myStack.pop();
         if(!reverse) pushAll(tmpNode->right);
         else pushAll(tmpNode->left);
         return tmpNode->data;
      }

      private:
         void pushAll(Node* root){
            for(;root!=NULL; ){
               myStack.push(root);
               if(reverse == true){
                  root = root->right;
               }else{
                  root = root->left;
               }
            }
         }
};

class Solution{
   public:
      bool findTarget(Node* root, int k){
         if(!root) return false;
         BSTIterator l(root, false);
         BSTIterator r(root, true);

         int i = l.next();
         int j = r.next();

         while(i<j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
         }
         return false;
      }
};

int main(){
    BinarySearchTree* tree = new BinarySearchTree();
    /*
            15
            /     \
        10     20
        / \     / \
        8 12 16 25 */
    tree->insert(15);
    tree->insert(10);
    tree->insert(20);
    tree->insert(8);
    tree->insert(12);
    tree->insert(16);
    tree->insert(25);

   Solution ans;
   cout<<ans.findTarget(tree->root,40)<<endl;
}