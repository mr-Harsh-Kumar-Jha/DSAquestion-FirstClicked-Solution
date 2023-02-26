//the intution for this solution is very simple as every thing is decided on two variables the prevBuy amount and the previous notBuy amount . So in the previous approach we were running a lop from i=0 to i<2 these were the 2 condition when i==0 then not buy would take place and when i==1 then buying of a stock would take place . If we remove the loop and calculate buy and notbuy condition simultaneously we can see that it is possible because both are independent cases and they are not dependent on each other execution .

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,2,3,4,5};
   int buy = 0 , notBuy = 0 , currBuy , currNotBuy;
   int n = price.size();
   for(int i=n-1;i>=0;i--){
      currBuy = max(-price[i]+notBuy, 0+buy);

      currNotBuy = max(price[i] + buy, 0 + notBuy);

      buy = currBuy;

      notBuy = currNotBuy;
   }
   cout<<buy<<endl;
}