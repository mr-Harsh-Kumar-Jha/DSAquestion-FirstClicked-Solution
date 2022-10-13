// u are given a n*m matrix filled with integer no's. find the maximum sum that can be obtained from the path starting from any cell in the first row of any cell in the last row .

// from the cell in a row , you can move to another cell directly below the row , or diagonally below left or right . So from a perticular cell , we can move in three directions , Down, Down left diagonal, Down right diagonal .

//----------------------------------------------------------------------------------

//This is a space optimization approach and time complexity is O(n*m) and space complexity is  O(n)

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<vector<int>> vec{
       {1, 2, 10, 4},
       {100, 3, 2, 1},
       {1, 1, 20, 2},
       {1, 2, 2, 1},
   };
   int n = vec.size();
   int m = vec[0].size();
   vector<int>prev(m,0);
   for (int i = 0; i < m; i++)
   {
      prev[i] = vec[0][i];
   }
   for(int i=1;i<n;i++){
      vector<int>curr(m,0);
      for(int j=0;j<m;j++){
         int up = vec[i][j] + prev[j];
         int upldig = vec[i][j];
         if(j-1>=0) upldig=upldig + prev[j - 1];
         else upldig+= -1e8;
         int uprdig = vec[i][j] ;
         if( j+1<m) uprdig=uprdig+ prev[j + 1];
         else upldig+= -1e8;
         curr[j]=max(up,max(upldig,uprdig));
      }
      prev=curr;
   }
   int maxi = -1e9;
   for(int i=0;i<m;i++){
       maxi = max(maxi,prev[i]);
   }
   cout<<maxi<<endl;
}