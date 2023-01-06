// this is a time optimised solution where the time complexity of the solution is O(n+m) and space complexity is O(m);

#include <bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int> &costs, int coins){
   int max = *max_element(costs.begin(), costs.end());
   vector<int> freq(max + 1, 0);
   int count = 0;
   for (int i = 0; i < costs.size(); i++){
      freq[costs[i]] += 1;
   }
   for (int i = 1; i <= max; i++){
      if (freq[i] == 0)
         continue;
      if (i > coins)
         break;
      else{
         int reqCoins = min(coins / i, freq[i]);
         count += reqCoins;
         coins -= reqCoins * i;
      }
   }
   return count;
}

int main(){
     vector<int>vec{1,3,2,1,4};
     int coins = 7;
    cout<<maxIceCream(vec,coins);
}