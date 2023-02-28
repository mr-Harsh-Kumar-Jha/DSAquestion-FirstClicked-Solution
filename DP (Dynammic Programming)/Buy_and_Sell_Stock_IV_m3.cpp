#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   int k =3;
   vector<vector<int>>prev(2+1, vector<int>(k+1,0)) , curr(2, vector<int>(k+1,0));
   for(int i=n-1;i>=0;i--){
      for(int j=0;j<=1;j++){
         for(int m=1;m<k+1;m++){
            if(j){
               curr[j][m] = max((-price[i]+prev[0][m]), (0+prev[1][m]));
            }
            else curr[j][m] = max((price[i]+prev[1][m-1]), (0+prev[0][m]));
         }
      }
      prev = curr;
   }
   cout<<prev[1][k]<<endl;
}