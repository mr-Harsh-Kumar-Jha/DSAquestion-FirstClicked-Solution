#include<bits/stdc++.h>
using namespace std;

int buySell(int ind ,int buy ,vector<int>&price ,int n, int fee){
   if(ind==n) return 0;
   int profit = 0;
   if(buy){
      profit = max((-price[ind]+buySell(ind+1,buy-1,price,n,fee)), (0+buySell(ind+1,buy,price,n,fee)));
   }
   else profit = max((price[ind]-fee+buySell(ind+1,buy+1,price,n,fee)), (0+buySell(ind+1,buy,price,n,fee)));

   return profit;
}

int main(){
   vector<int>price{1,3,2,8,4,9};
   int n = price.size();
   int fee = 2;
   cout<<buySell(0 , 1 ,price , n, fee);
}