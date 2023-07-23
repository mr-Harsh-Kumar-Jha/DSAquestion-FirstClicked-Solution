#include <bits/stdc++.h>
using namespace std;

int k = 0;

class node{
public:
   char data;
   node *left;
   node *right;
};

// A utility function to create a node
node *newNode(int data){
   node *temp = new node();

   temp->data = data;
   temp->left = temp->right = NULL;

   return temp;
}

int findNodeLocation(char *in, char *pre, int i, int j){
   for (int l = i; l <= j; l++){
      if (in[l] == pre[k]){
         return l;
      }
   }
   return -1;
}

node *solve(char *in, char *pre, int i, int j){
   int location = findNodeLocation(in, pre, i, j); // why i have wrriten findlocation function at top is because i as while creating temp we are also modifying value of k which is global variable and this variable is used in find location function also therefore there is need to modify the value of k after finding the location of that perticular element from the inorder array .
   node *temp = newNode(pre[k++]);

   if (j - i <= 0){
      if (j - i == 0)
         return temp;
      return NULL;
   }

   temp->left = solve(in, pre, i, location - 1);
   temp->right = solve(in, pre, location + 1, j);

   return temp;
}

node *constructTree(char *in, char *pre, int size){
   int location = findNodeLocation(in, pre, 0, size - 1);
   node *root = newNode(pre[k++]);
   root->left = solve(in, pre, 0, location - 1);
   root->right = solve(in, pre, location + 1, size - 1);

   return root;
}

void print(node *temp){
   if (temp == NULL)
      return;

   print(temp->left);
   cout << temp->data << " ";
   print(temp->right);
}

int main(){
   char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
   char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
   int size = sizeof(pre) / sizeof(pre[0]);

   node *root = constructTree(in, pre, size);

   node *temp = root;
   print(temp);
}