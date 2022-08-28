//https://leetcode.com/problems/sort-the-matrix-diagonally
// this a problem ssolved using priority queue
#include <bits/stdc++.h>
using namespace std;
void diagonalSorter(int i, int j, vector<vector<int>> &mat)
{
   int m = mat.size(), n = mat[0].size();
   priority_queue<int> arr;

   for (; i < m && j < n; i++, j++)
   {
      // cout<<i<<" "<<j<<endl;
      arr.push(mat[i][j]);
   }
   i--, j--;
   for (; i >= 0 && j >= 0; i--, j--)
   {
      mat[i][j] = arr.top();
      arr.pop();
   }
}
vector<vector<int>> diagonalSort(vector<vector<int>> mat)
{
   int m = mat.size(), n = mat[0].size();

   for (int i = m - 1, j = 0; i >= 0 && j < n; i == 0 ? j++ : i--)
   {
      diagonalSorter(i, j, mat);
   }

   return mat;
}

int main()
{
   vector<vector<int>> mat {
       {10, 20, 50, 40},
       {15, 56, 35, 45},
       {27, 2, 37, 48},
   };
 mat= diagonalSort(mat);
 for(int i=0;i<3;i++){
   for(int j=0;j<4;j++){
      cout<<mat[i][j]<<" ";
   }
   cout<<endl;
 }

   return 0;
}
