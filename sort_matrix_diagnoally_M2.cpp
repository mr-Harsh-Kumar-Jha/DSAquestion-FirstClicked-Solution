#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
   for (int i = 0; i < mat[0].size() - 1; i++)
   {
      vector<int> x;
      for (int p1 = 0, p2 = 0; (p1 < mat.size()) && (p2 + i < mat[0].size()); p1++, p2++)
      {
         x.push_back(mat[p1][p2 + i]);
      }
      sort(x.begin(), x.end());
      for (int p1 = 0, p2 = 0; (p1 < mat.size()) && (p2 + i < mat[0].size()); p1++, p2++)
      {
         mat[p1][p2 + i] = x[p1];
      }
   }
   for (int i = 1; i < mat.size() - 1; i++)
   {
      vector<int> x;
      for (int p1 = 0, p2 = 0; (p1 + i < mat.size()) && (p2 < mat[0].size()); p1++, p2++)
      {
         x.push_back(mat[p1 + i][p2]);
      }
      sort(x.begin(), x.end());
      for (int p1 = 0, p2 = 0; (p1 + i < mat.size()) && (p2 < mat[0].size()); p1++, p2++)
      {
         mat[p1 + i][p2] = x[p1];
      }
   }
   return mat;
}

int main()
{
   vector<vector<int>> arr{
       {10, 30, 45, 40},
       {29, 37, 20, 45},
       {27, 15, 25, 1},
   };

   vector<vector<int>>ans = diagonalSort(arr);

   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         cout << ans[i][j]<<" ";
      }
      cout << endl;
   }
}