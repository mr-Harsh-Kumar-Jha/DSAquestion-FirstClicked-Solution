#include <bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   Node *left;
   Node *right;
   Node(int data){
      this->data = data;
      this->left = this->right = NULL;
   }
};

Node *newNode(int data){
   return new Node(data);
}

class correctNode{
private:
   Node *first;
   Node *last;
   Node *mid;
   Node *prev;

protected:
   void inOrderTraversal(Node *root){
      if (root == NULL){
         return;
      }

      inOrderTraversal(root->left);

      if (prev != NULL && (root->data < prev->data)){
         if (first == NULL){
            first = prev;
            mid = root;
         }else{
            last = root;
         }
      }

      prev = root;
      inOrderTraversal(root->right);
   }



public:
   void correct_BST(Node *root){
      first = last = mid = NULL;
      prev = new Node(INT_MIN);
      inOrderTraversal(root);
      if(first && last) swap(first->data, last->data);
      else if(first && mid) swap(first->data, mid->data);
   }
   void inOrder(Node *head){
      if (head == NULL)
         return;
      stack<Node *> st;
      while (1){
         if (head != NULL){
            st.push(head);
            head = head->left;
         }
         else{
            if (st.empty())
               break;
            head = st.top();
            st.pop();
            cout << head->data << " ";
            head = head->right;
         }
      }
   }
};

int main(){
   struct Node *root = newNode(6);
   root->left = newNode(10);
   root->right = newNode(2);
   root->left->left = newNode(1);
   root->left->right = newNode(3);
   root->right->right = newNode(12);
   root->right->left = newNode(7);

   correctNode node;
   node.inOrder(root);
   cout<<endl;
   node.correct_BST(root);
   node.inOrder(root);
}