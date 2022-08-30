//https://leetcode.com/problems/rotate-image
// this a program to rotate matrix by 90 degree using a stack here space is compromised therefore not much optimmised  solution than M2 .

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
   int N = matrix.size();
   vector<stack<int>> mp(matrix[0].size());
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < N; j++)
      {
         mp[i].push(matrix[j][i]);
      }
   }
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < N; j++)
      {
         matrix[i][j] = mp[i].top();
         mp[i].pop();
      }
   }
}

int main(){
   vector<vector<int>>vec{
      {1,2,3},
      {4,5,6},
      {7,8,9},
   };
   rotate(vec);
   for(int i=0;i<vec.size();i++){
      for(int j=0;j<vec[0].size();j++){
         cout<<vec[i][j]<<" ";
      }
      cout<<endl;
   }
}