// this is a simple solution where the time complexity is exponential and spce complexity is O(n+2);

#include<bits/stdc++.h>
using namespace std;

int buySellStock(int ind , int buy, int chance, vector<int>&price , int n){
   if(chance==0) return 0;
   if(ind==n) return 0;
   int profit = 0;
   if(buy){
      profit = max((-price[ind]+buySellStock(ind+1 , buy-1, chance, price,n)), (0+buySellStock(ind+1,buy, chance,price,n)));
   }
   else{
      profit = max((price[ind]+buySellStock(ind+1,buy+1,chance-1,price, n)), (0+buySellStock(ind+1,buy,chance,price,n)));
   }
   return profit;
}

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   cout<<buySellStock(0 , 1 , 2, price, n)<<endl;
}