//time complexity of the solution is 2^n and space complexity of the solution is auxilliary stck space .

#include<bits/stdc++.h>
using namespace std;

int knapSack(int w , vector<int>&wt , vector<int>&val , int n ){
   if(w==0) return 0;
   if(n==0){
      if(wt[0]<=w) return val[0];
      return 0;
   }
   int noTake = 0 + knapSack(w,wt,val,n-1);
   int take = INT_MIN;
   if(wt[n]<=w) take=val[n]+knapSack(w-wt[n],wt,val,n);
   return max(noTake,take);
}

int main(){
   vector<int>val{60,100,120};
   vector<int>wt{10,20,30};
   int w = 50;
   int n = val.size();
   cout<<knapSack(w,wt,val,n-1)<<endl;
}