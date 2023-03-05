#include<bits/stdc++.h>
using namespace std;

int largestDivisibleSubset(int ind , int prev ,  int n , vector<int>&vec){
   if(ind==n) return 0;
   int take = 0;
   if(vec[ind]%vec[prev]==0) take = 1 + largestDivisibleSubset(ind+1 , ind , n,vec);
   int notake = 0 + largestDivisibleSubset(ind+1, prev , n , vec);
   return max(take,notake);
}

int main(){
   vector<int>vec{4,1,16,7,8};
   int n = vec.size();
   sort(vec.begin(),vec.end());
   cout<<largestDivisibleSubset(1,0,n,vec)<<endl;
}