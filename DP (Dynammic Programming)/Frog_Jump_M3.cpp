// this is a space optimization technique with time complexity O(N) and space complexity O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>pow{10,30,20,60,40};
   int ans=0,prev=0,prev2=0;
   int temp;
   for(int i=2;i<pow.size();i++){
      int left = prev+abs(pow[i-1]-pow[i-2]);
      int right = prev2+abs(pow[i]-pow[i-2]);
      ans = min(left,right);
      prev2=prev;
      prev = ans;
   }
   cout<<ans<<endl;
}