//  this is a space optimized solution as space complexity is reduced to O(n);

#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust){
   vector<int> ans(n + 1);
   for (int i = 0; i < trust.size(); i++){
      ans[trust[i][0]] --;   // here only instead of storing the pointing element we are substracting it from the pointed element so that any poined part  should not point to any element asper givrn condition.
      ans[trust[i][1]]+= 1;
   }
   for (int i = 1; i <= n; i++){
      if (ans[i] == n - 1){
         return i;
      }
   }
   return -1;
}

int main(){
    vector<vector<int>>trust{{1,3},
                                                 {2,3}};
  cout<<findJudge(3,trust)<<endl;
}