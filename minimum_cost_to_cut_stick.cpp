#include<bits/stdc++.h>
using namespace std;

int minCost(int i , int j, vector<int>&vec){
   if(i>j) return 0;
   int mini = INT_MAX;
   for(int k = i;k<=j;k++){
      int ans =vec[j+1]-vec[i-1]+minCost(i,k-1,vec)+minCost(k+1,j,vec);
      mini = min(mini,ans);
   }
   return mini;
}

int main(){
   vector<int>vec{5,6,1,4,2};
    int size = vec.size();
   int n = 9;
   vec.insert(vec.begin(),0);
   vec.push_back(n);
   sort(vec.begin(),vec.end());
   cout<<minCost(1,size,vec)<<endl;
}