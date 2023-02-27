#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   vector<vector<int>>prev(2,vector<int>(3,0)), curr(2,vector<int>(3,0));
   for(int i=n-1;i>=0;i--){
      for(int j=0;j<=1;j++){
         for(int k=1;k<=2;k++){
            int profit = 0;
            if(j){
               curr[j][k] = max((-price[i]+prev[0][k]), (0+prev[1][k]));
             }
            else{
               curr[j][k]= max((price[i]+prev[1][k-1]), (0+prev[0][k]));
            }
         }
      }
            prev = curr;
   }
    cout<<prev[1][2]<<endl;
}