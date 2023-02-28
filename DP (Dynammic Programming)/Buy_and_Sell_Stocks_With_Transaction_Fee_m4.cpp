#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,3,7,5,10,3};
   int n = price.size();
   int fee = 3;
   int prev0=0 , prev1=0 , curr0, curr1;
   for(int i=n-1;i>=0;i--){
      curr1 = max((-price[i]+prev0),(0+prev1));
      curr0 = max((price[i]-fee+prev1),(0+prev0));
      prev0 = curr0;
      prev1 = curr1;
   }
   cout<<prev1<<endl;
}