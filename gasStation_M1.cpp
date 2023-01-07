//this is a solution with time complexity of O(n*n) and space complexity of O(1);

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
   int totalCoast = 0,totalCoastCpy, gasOverloaded = 0;
   for (int i = 0; i < gas.size(); i++){
      totalCoast += cost[i];
   }
   int i = 0;
   int j = 0;
   totalCoastCpy=totalCoast;
   while (totalCoast != 0 && j < gas.size()){
      gasOverloaded += gas[i];
      if(gasOverloaded >= cost[i]){
         totalCoast -= cost[i];
         gasOverloaded -= cost[i];
         if (i >= gas.size() - 1){
            i = (i + 1) % gas.size();
         }
         else{
            i++;
         }
      }
      else{
         gasOverloaded = 0;
         totalCoast = totalCoastCpy;
         j = j + 1;
         i = j;
      }
   }
   return totalCoast==0?j:-1;
}

int main(){
   vector<int>gas{2,3,4},cost{3,4,3};
   cout<<canCompleteCircuit(gas,cost)<<endl;
}