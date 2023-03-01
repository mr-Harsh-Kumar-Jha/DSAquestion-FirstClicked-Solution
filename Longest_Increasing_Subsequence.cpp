#include<bits/stdc++.h>
using namespace std;

int longestIncreasing(int ind , int prev , vector<int>&vec, int n){
   if(ind==n) return 0;
   int total = 0;
   total = 0+longestIncreasing(ind+1,prev,vec,n);
   if(prev==-1 || vec[prev]<vec[ind]) total =max(total, 1+longestIncreasing(ind+1,ind,vec,n));
   return total;
}

int main(){
   vector<int>vec{10,9,2,5,3,7,101,18};
   int n = vec.size();
   cout<<longestIncreasing(0,-1,vec,n)<<endl;
}