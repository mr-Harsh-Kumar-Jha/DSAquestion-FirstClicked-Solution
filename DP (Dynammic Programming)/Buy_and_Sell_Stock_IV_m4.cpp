//there is a simple observation as we can see we are always performing 2*k transaction only so we said that we can directly create a tranction list in which transaction made is even then  we can perform buy operation and if it is odd we will perform sell operation simple .

#include<bits/stdc++.h>
using namespace std;

int buySellStock(int ind , int transaction , vector<int>&price , int n , vector<vector<int>>&dp,int k){
   if(transaction==2*k) return 0;
   if(ind == n ) return 0;
   int total = 0;
   if(transaction%2==0){
      total = max((-price[ind]+buySellStock(ind+1,transaction+1, price, n,dp,k)), (0+buySellStock(ind+1,transaction, price, n,dp,k)));
   }
   else total = max((price[ind]+buySellStock(ind+1, transaction+1, price,n,dp,k)), (0+buySellStock(ind+1, transaction, price, n ,dp,k)));

   return total;
}

int main(){
   vector<int>price{3,2,6,5,0,3};
   int n = price.size();
   int k =2;
   int transaction = k*2;
   vector<vector<int>>dp(n,vector<int>(transaction+1,-1));
    cout<<buySellStock(0 , 0, price, n,dp,k)<<endl;
}