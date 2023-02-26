#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   vector<int>prev(2,0) , curr(2,0);
   for(int i=n-1;i>=0;i--){ // loop is ran in opposite fashion because as u can see the dependency of dp array is always i+1th elemnt so we are filling dp array from behind in order to make it accessible
      for(int j=0;j<2;j++){
         int profit = 0;
         if(j){
            profit = max(-price[i]+prev[0], 0+prev[1]);
         }
         else{
            profit =max(price[i] + prev[1], 0 + prev[ 0]); // the first statement means we want to again purchse some another stock after selling the ith stock to increase profit , and the second statement means we dont want to sell on the perticular ith value but we can see further price to make it maximum .
         }
         curr[j] = profit;
      }
      prev = curr;
   }
   cout<<prev[1]<<endl;
}