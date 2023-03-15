#include<bits/stdc++.h>
using namespace std;

int matrixChainManip(int i, int j, vector<int>&vec){
   if(i==j) return 0;
   int mins = 1e9;
   for(int k = i; k < j; k++){
     int score = (vec[i-1]*vec[k]*vec[j])+matrixChainManip(i,k,vec)+matrixChainManip(k+1,j,vec);
      mins = min(mins,score);
   }
   return mins;
}

int main(){
   vector<int>vec{4 ,5 ,3 ,2};
   int n = vec.size();
   cout<<matrixChainManip(1, n-1, vec)<<endl;
}