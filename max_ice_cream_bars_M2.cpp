// this is a space optimised solution where the time complexity of the solution is O(nlogn) and space complexity is O(1);

#include <bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int> &costs, int coins){

   sort(costs.begin() , costs.end());
   int count =0;
   for(int i=0;i<costs.size();i++){
      if(costs[i]<=coins){
         count++;
         coins-=costs[i];
      }
   }
   return count;
}

int main(){
     vector<int>vec{1,3,2,1,4};
     int coins = 11;
    cout<<maxIceCream(vec,coins);
}