// you are present at point A which is the top-left cell of an M*N matrix , your destination is point 'B' , which is the bottom-right cell of the same matrix . your task is to find the total no of unique paths from point 'A' to the point 'B'  . In other words you will be given the dimension of the matrix as integers M and N , your task is to find the total no of unique paths from the cell Matix[i][j] to Matrix[m-1][n-1] .

// to traverse in the matrix , you can either mmove right or down at each step . for eg. in a give point Matrix[i][j] you can either move to matrix[i+1][j] or matrix[i][j+1] .

//-----------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<int>>dp(n,vector<int>(m,-1));
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(i==0&&j==0) dp[i][j]=1;
         else{
            int up =0;
            if(i>0) up= dp[i-1][j];
            int left =0;
           if(j>0) left = dp[i][j-1];
            dp[i][j]=up+left;
         }
      }
   }
  cout<<dp[n-1][m-1]<<endl;
}