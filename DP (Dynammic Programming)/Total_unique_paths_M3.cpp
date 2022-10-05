// you are present at point A which is the top-left cell of an M*N matrix , your destination is point 'B' , which is the bottom-right cell of the same matrix . your task is to find the total no of unique paths from point 'A' to the point 'B'  . In other words you will be given the dimension of the matrix as integers M and N , your task is to find the total no of unique paths from the cell Matix[i][j] to Matrix[m-1][n-1] .

// to traverse in the matrix , you can either mmove right or down at each step . for eg. in a give point Matrix[i][j] you can either move to matrix[i+1][j] or matrix[i][j+1] .

//-----------------------------------------------------------------------------

// this is a space optimization approach and time complexity of this solution is O(n*m) and space complexity is O(n).

#include<bits/stdc++.h>
using namespace std;

int main(){
     int n,m;
     cin>>n>>m;
     vector<int>prev(m,0);
     for(int i=0;i<n;i++){
      vector<int>curr(m,0);
      for(int j=0;j<m;j++){
         if(i==0 && j==0) curr[j]=1;
         else{
            int up=0,left=0;
            if(i>0) up = prev[j];
            if(j>0) left = curr[j-1];
            curr[j]=up+left;
         }
      }
      prev=curr;
     }
     cout<<prev[m-1];
}