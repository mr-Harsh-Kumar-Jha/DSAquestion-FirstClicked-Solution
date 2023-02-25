#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{7,1,5,3,6,4};
   int n = price.size();
   vector<vector<int>>dp(n+1, vector<int>(2,0));
   for(int i=n-1;i>=0;i--){ // loop is ran in opposite fashion because as u can see the dependency of dp array is always i+1th elemnt so we are filling dp array from behind in order to make it accessible 
      for(int j=0;j<2;j++){
         int profit = 0;
         if(j){
            profit = max(-price[i]+dp[i+1][0], 0+dp[i+1][1]);
         }
         else{
            profit =max(price[i] + dp[i+1][1], 0 + dp[i+1] [ 0]); // the first statement means we want to again purchse some another stock after selling the ith stock to increase profit , and the second statement means we dont want to sell on the perticular ith value but we can see further price to make it maximum .
         }
         dp[i][j] = profit;
      }

   }
   cout<<dp[0][1]<<endl;
}