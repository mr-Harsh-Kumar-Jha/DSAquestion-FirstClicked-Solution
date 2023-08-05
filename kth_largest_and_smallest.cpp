#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;
};

/* Helper function that allocates a new node with the given
key and NULL left and right pointers.*/
node* newNode(int key)
{
    node* Node = new node();
    Node->key = key;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

// int kth_largest(node* head, int k){
//    vector<int>ans;
//    stack<node*>st;
//    while(1){
//       if(head!=NULL ){
//          st.push(head);
//          head = head->left;
//       }
//       else{
//          if(st.empty()) break;
//          head = st.top();
//          st.pop();
//          ans.push_back(head->key);
//          head = head->right;
//       }
//    }
//    return ans[ans.size()-k];
// }

int kth_largest(node* head, int k){
   vector<int>ans;
   stack<node*>st;
   st.push(head);
   while(!st.empty()){
      head = st.top();
      if(head->left!=NULL ){
         st.push(head->left);
         head->left = NULL;
      }
      else{
         ans.push_back(head->key);
         st.pop();
         if(head->right!=NULL) st.push(head->right);
      }
   }

   return ans[ans.size()-k];
}

int main(){
   node* root = newNode(8);

    root->left = newNode(4);
    root->right = newNode(12);

    root->left->left = newNode(2);
    root->left->right = newNode(6);

    root->right->left = newNode(10);
    root->right->right = newNode(24);

   cout<<kth_largest(root, 3)<<endl;
}