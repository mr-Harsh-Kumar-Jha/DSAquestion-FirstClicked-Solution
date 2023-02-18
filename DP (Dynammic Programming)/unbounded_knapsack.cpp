// this is the most optimized solution where the time complexity is O(n*w) and space complexity is O(w) where i have used only one extra array .

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int> val{160, 350, 340};
   vector<int> wt{2, 3, 4};
   int w = 5;
   int n = val.size();
   vector<int>prev(w+1,0);
   for(int i=0;i<=w;i++){
       prev[i] = (i/wt[0])*val[0];  // base condition
   }

   for(int i=1;i<n;i++){
      for(int j=0;j<=w;j++){
         int notake = 0+prev[j];
         int take = 0;
         if(wt[i]<=j) take = val[i]+prev[j-wt[i]];
         prev[j]=max(take,notake);
      }
   }
   cout<<prev[w]<<endl;
}