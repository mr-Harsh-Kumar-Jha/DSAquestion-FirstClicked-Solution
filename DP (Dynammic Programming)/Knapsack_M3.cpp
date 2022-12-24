//this is a space optimization solution

#include <bits/stdc++.h>
using namespace std;

int main(){
   vector<int> val{160, 350, 120};
   vector<int> wt{2, 3, 1};
   int w = 5;
   int n = val.size();
   vector<int>prev(w+1,0);
   for(int i=1;i<=w;i++) if(i>=wt[0]) prev[i]=prev[i-wt[0]]+val[0];
   for(int i=1;i<n;i++){
      vector<int>curr(w+1,0);
       for(int j=1;j<=w;j++){
         int noTake = 0+prev[j];
         int take = INT_MIN;
         if(j>=wt[i]) take=val[i]+curr[j-wt[i]];
         curr[j] = max(take,noTake);
       }
       prev=curr;
   }
   cout<<prev[w]<<endl;
}