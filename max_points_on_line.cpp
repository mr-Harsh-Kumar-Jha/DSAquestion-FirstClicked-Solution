#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>> &points){
   int n = points.size();
   int max = 1;
   for (int i = 0; i < n - 1; i++){
      map<double, int> m;
      for (int j = i + 1; j < n; j++){
         double slope = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
         if (points[j][1] - points[i][1] < 0 && points[j][0] - points[i][0] == 0) //this is to control '-infinity' wala condition
            m[abs(slope)]++;
         else
            m[slope]++;
      }
      for (auto it : m){
         if (it.second + 1 > max)
            max = it.second + 1;
      }
   }
   return max;
}

int main(){
  vector<vector<int>> vec={{1,1},{2,2},{3,3}};
  cout<<maxPoints(vec)<<endl;
}