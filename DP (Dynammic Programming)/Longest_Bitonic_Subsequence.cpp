// here any of the possibility is possible  either whole increasing or decreasing  sequence or  mountain like structure means increaing and decreasing is possible .

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{9,8,1,7,6,5,4,3,2,1};
   int n  = vec.size();
   vector<int>fronDP(n,1), endDP(n,1), ans(n,0);
   for(int i=0;i<n;i++){
      for(int j=0;j<i;j++){
         if(vec[i]>vec[j] && 1+fronDP[j]>fronDP[i]) fronDP[i] = 1+fronDP[j];
      }
   }
   for(int i = n-1;i>=0;i--){
      for(int j=n-1; j>i; j--){
          if(vec[i]>vec[j] && 1+endDP[j]>endDP[i]) endDP[i] = 1+endDP[j];
      }
   }
   for(int i = 0;i<n;i++){
      ans[i] = fronDP[i]+endDP[i]-1;
   }

   cout<<*max_element(ans.begin(),ans.end())<<endl;
}