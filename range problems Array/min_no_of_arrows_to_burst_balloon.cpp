#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points){
   int count = 1;
   sort(points.begin(), points.end());
   int prevPointer = points[0][1];
   int currPointer;
   for (int i = 1; i < points.size(); i++){
      currPointer = points[i][0];
      if (currPointer > prevPointer){
         count++;
         prevPointer = points[i][1];
      }
      else{
         prevPointer = min(prevPointer, points[i][1]);
      }
   }
   return count;
}

int main(){
   vector<vector<int>>vec{{10,16},{2,8},{1,6},{7,12}};
  cout<< findMinArrowShots(vec)<<endl;
}