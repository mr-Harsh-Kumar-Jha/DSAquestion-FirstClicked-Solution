// Ninja has a grid of size 'R' X 'C' . Each cell of the grid contains some chocolates . Ninja has two frnds Alice and Bob , and he wants to collect as many chocolates as possible with the help of the friends . Initially Allice , is in the top Left i.e (o,o) and his frnd is at (o,c-1) on the grid . Each one can move from their current cell to the cell just below them . When anyone passes from any cell, he will pick all chocolates in it , and the no of chocolates in that cell will become zero . If both stay in the same cell , only one of them will pick the chocolates in it .

// if Alice or bob is at (i,j) then they can move to (i+1,j) , (i+1,j-1) , (i+1 , j+1) They will always stay in grid . Ypur task is to find the maximum no of chocolates that ninja can colllect with the help of his friend by following the above rules .

//-------------------------------------------------------------------------------

// this is a space optimization approach and time complexity is O(n*m*m)*9 and space complexity is O(n*m)

#include <bits/stdc++.h>
using namespace std;

int main()
{
   vector<vector<int>> vec{
       {1, 2, 3, 4},
       {10, 32, 21, 22},
       {11, 1, 44, 2},
       {100, 200, 300, 100},
   };
   int n = vec.size();
  int m = vec[0].size();
   vector<vector<int>> prev(vec.size(), vector<int>(m, 0));
   vector<vector<int>> curr(vec.size(), vector<int>(m, 0));

   for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        prev[j1][j2] = vec[n - 1][j1];
      else
        prev[j1][j2] = vec[n - 1][j1] + vec[n - 1][j2];
    }
  }
   for (int i = n - 2; i >= 0; i--)
   {
      for (int j = 0; j < m; j++)
      {
         for (int k = 0 ; k <m ; k++)
         {
             int maxi = INT_MIN;
            for (int i1 = -1; i1 <= 1; i1++)
            {
               for (int j1 = -1; j1 <= 1; j1++)
               {
                  int value ;
                  if (j == k)
                     value =  vec[i][j];
                  else
                     value = vec[i][j] + vec[i][k];
                  if((j+i1>=0 &&  j+i1<m) && ( k+j1>=0 &&  k+j1<m))
                     value += prev[j + i1][k + j1];
                  else
                     value += -1e8;
                  maxi = max(maxi, value);
               }
            }
            curr[j][k]=maxi;
         }
      }
      prev=curr;
   }
   cout<<prev[0][m-1]<<endl;
}