// you are present at point A which is the top-left cell of an M*N matrix , your destination is point 'B' , which is the bottom-right cell of the same matrix . your task is to find the total no of unique paths from point 'A' to the point 'B'  . In other words you will be given the dimension of the matrix as integers M and N , your task is to find the total no of unique paths from the cell Matix[i][j] to Matrix[m-1][n-1] .

// to traverse in the matrix , you can either mmove right or down at each step . for eg. in a give point Matrix[i][j] you can either move to matrix[i+1][j] or matrix[i][j+1] .

//-----------------------------------------------------------------------------

//this is a top down approach and the time complexity of the solution is O(m*n) and space complexity is O(m*n)+O(n) .

#include<bits/stdc++.h>
using namespace std;

int totalUniquePath(int n,int m,vector<vector<int>>&dp){
   if(n==0 && m==0) return 1;
   if(n<0 || m<0) return 0;
   if(dp[n][m]!=-1) return dp[n][m];
   int left= totalUniquePath(n,m-1,dp);
   int up = totalUniquePath(n-1,m,dp);
   return dp[n][m]=left+up;
}

int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<int>>dp(n,vector<int>(m,-1));
   cout<<dp.size()<<endl;
   cout<<totalUniquePath(n-1,m-1,dp)<<endl;
}