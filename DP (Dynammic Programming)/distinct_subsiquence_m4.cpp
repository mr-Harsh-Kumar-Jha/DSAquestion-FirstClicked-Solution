// the time complexity of the above solution is O(n*m) and space complexity is O(m) one of the most optimized solution

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "babgbag";
   string s2 = "bag";
   int n = s1.length();
   int m = s2.length();
   vector<double>prev(m+1, 0);
   prev[0]=1;
   for(int i=1;i<=n;i++){
      for(int j=m;j>=1;j--){ // i am not running loop from 1 to n because as u can see dependency of jth element is j-1th elem and jth elem if we try to replace jth element next time j-1th element is changed and we are not have the actual element
         if(s1[i-1]==s2[j-1]){
            prev[j] = prev[j-1] + prev[j];
         }
         else prev[j] = prev[j];
      }
   }
   cout<<(int)prev[m]<<endl;
}