//this is a space optimization technique on oned array but repetation is not allowed (i.e we cannot choose any element more than once)

#include <bits/stdc++.h>
using namespace std;

int main(){
   vector<int> val{160, 350, 220};
   vector<int> wt{2, 3, 1};
   int w = 5;
   int n = val.size();
   vector<int>prev(w+1,0);
   for(int i=wt[0];i<=w;i++) prev[i]=val[0];
   for(int i=1;i<n;i++){
       for(int j=w;j>=1;j--){
         int noTake = 0+prev[j];
         int take = INT_MIN;
         if(j>=wt[i]) take=val[i]+prev[j-wt[i]];
         prev[j] = max(take,noTake);
       }
   }
   cout<<prev[w]<<endl;
}