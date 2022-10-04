// you are present at point A which is the top-left cell of an M*N matrix , your destination is point 'B' , which is the bottom-right cell of the same matrix . your task is to find the total no of unique paths from point 'A' to the point 'B'  . In other words you will be given the dimension of the matrix as integers M and N , your task is to find the total no of unique paths from the cell Matix[i][j] to Matrix[m-1][n-1] .

// to traverse in the matrix , you can either mmove right or down at each step . for eg. in a give point Matrix[i][j] you can either move to matrix[i+1][j] or matrix[i][j+1] .

//-----------------------------------------------------------------------------

//this is a recursive approiach and the time complexity for this solution is exponential and space complexity is O(n*m)+auxilliary space

#include<bits/stdc++.h>
using namespace std;

int totalUniquePath(int n,int m){
   if(n==0 && m==0) return 1;
   if(n<0 || m<0) return 0;
   int left = totalUniquePath(n-1,m);
   int up = totalUniquePath(n,m-1);
   return left+up;
}

int main(){
   int n,m;
   cin>>n>>m;
   cout<<totalUniquePath(n-1,m-1)<<endl;
}