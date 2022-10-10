#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<vector<int>> A{{2},
                                           {3, 4},
                                           {1, 0, 3}};
   vector<int>prev(A[A.size()-1].size(),0);
   for(int i=0;i<A[A.size()-1].size();i++){
      prev[i]=A[A.size()-1][i];
   }
   for(int i=A.size()-2;i>=0;i--){
      vector<int>curr(A[A.size()-1].size(),0);
      for(int j=i ; j>=0 ; j--){
         int down = A[i][j]+prev[j];
         int dig = A[i][j]+prev[j+1];
         curr[j]=min(down,dig);
      }
      prev=curr;
   }
   cout<<prev[0]<<endl;
}