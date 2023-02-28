#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,3,7,5,10,3};
   int n = price.size();
   int fee = 3;
   vector<int>prev(2,0), curr(2,0);
   for(int i=n-1;i>=0;i--){
      for(int j=0;j<=1;j++){
         if(j) curr[j] = max((-price[i]+prev[0]),(0+prev[1]));
         else curr[j] = max((price[i]-fee+prev[1]),(0+prev[0]));
      }
      prev = curr;
   }
   cout<<prev[1];
}