#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{10,9,2,5,3,7,101,18};
   int n = vec.size();
   vector<int>next(n+1,0), curr(n+1,0);
   for(int i = n-1;i>=0;i--){
      for(int j=i-1;j>=-1;j--){
         int take = 0;
         if(j==-1 || vec[j]<vec[i]){
            take = 1+next[i+1];
         }
        int notake = 0 + next[j+1];
        curr[j+1] = max(take,notake);
      }
      next = curr;
   }
   cout<<next[0]<<endl;
}