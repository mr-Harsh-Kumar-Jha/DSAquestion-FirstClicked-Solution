// this is a simple recurssion based approach as its time complexity is exponential and space complexity is O(n+2) which is an auxilliary space . 

#include<bits/stdc++.h>
using namespace std;

long long buySellstock(int i , int buy , vector<int>&price , int n){
   if(i==n) return 0;
   int profit = 0;
   if(buy){
       profit = max(-price[i]+buySellstock(i+1,0,price, n), 0+buySellstock(i+1,1,price,n));
   }
   else{
      profit =max(price[i] + buySellstock(i+1,1,price, n), 0 + buySellstock(i+1 , 0 , price , n));
   }
   return profit;
}

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   cout<<buySellstock(0 , 1 , price, n)<<endl;
}