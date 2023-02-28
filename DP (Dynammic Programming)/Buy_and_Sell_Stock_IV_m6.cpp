#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{3,2,6,5,0,3};
   int n = price.size();
   int k =2;
   int transaction = 2*k;
   vector<int>prev(transaction+1,0) , curr(transaction+1,0);
   for(int i=n-1;i>=0;i--){
         for(int m=transaction-1;m>=0;m--){
            if(m%2==0){
               curr[m] = max((-price[i]+prev[m+1]), prev[m]);
            }
            else curr[m] = max((price[i]+prev[m+1]), prev[m]);
         }
         prev = curr;
   }
   cout<<prev[0]<<endl;
}