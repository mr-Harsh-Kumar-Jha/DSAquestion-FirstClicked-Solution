#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

string serialize(Node* root){
   if(!root) return "";
   string s = "";
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
      Node* temp = q.front();
      q.pop();
      if(temp==NULL) s.append("#,");
      else s.append(to_string(temp->key)+",");
      if(temp!=NULL){
         q.push(temp->left);
         q.push(temp->right);
      }
   }
   return s;
}

Node* deSerialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        Node *root = newNode(stoi(str));
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {

            Node *node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL;
            }
            else {
                Node* leftNode = newNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL;
            }
            else {
                Node* rightNode = newNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }

void morrisPreOrderTraversal(Node* root){
   Node* curr = root;
   while(curr!=NULL){
      if(curr->left==NULL){
         cout<<curr->key<<" ";
         curr = curr->right;
      }else{
         Node* prev = curr->left;
         while(prev->right && prev->right!=curr){
            prev = prev->right;
         }
         if(prev->right==NULL){
            prev->right = curr;
            cout<<curr->key<<" ";
            curr = curr->left;

         }else{
            curr = curr->right;
            prev->right = NULL;
         }
      }
   }
}

int main(){
   struct Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

   string s = serialize(root);
   Node* root2 = deSerialize(s);
   morrisPreOrderTraversal(root2);
}