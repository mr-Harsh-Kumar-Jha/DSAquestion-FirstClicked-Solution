#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust){
   vector<vector<int>> ans(n + 1, vector<int>(2, 0));
   for (int i = 0; i < trust.size(); i++){
      ans[trust[i][0]][0] += 1;
      ans[trust[i][1]][1] += 1;
   }
   for (int i = 1; i <= n; i++){
      if (ans[i][0] == 0 && ans[i][1] == n - 1){
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