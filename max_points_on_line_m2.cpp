//this is space optimal solution here time has comprimised but space used is of the order O(1);

#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>> &points){
   int n = points.size();
   if(n<=2)
            return n;
   int maxi = 2;
   int count ;
   for (int i = 0; i < n - 1; i++){
      for (int j = i + 1; j < n; j++){
         count = 2;
         int dy = points[j][1] - points[i][1];
         int dx = points[j][0] - points[i][0];
         for (int k = 0; k < n; k++){
            if (k != i && k != j){
               int dy1 = points[k][1]-points[i][1];
               int dx1 = points[k][0]-points[i][0];
               if(dy1*dx==dy*dx1) {
                  count++;
               }
            }
         }
         maxi = max(maxi,count);
      }
   }
   return maxi;
}

int main()
{
   vector<vector<int>> vec = {{1, 1}, {2, 2}, {3, 3}};
   cout << maxPoints(vec) << endl;
}