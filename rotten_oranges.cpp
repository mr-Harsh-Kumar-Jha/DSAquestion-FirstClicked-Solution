// Time Complexity = O((n*m)*4) eq to O(n*m)
//  Space Complexity = O(n*m) as i have used another matrix to store the ans

#include<bits/stdc++.h>
using namespace std;

class Solution{
   public:
      int solve(vector<vector<int>>& image){
         int n = image.size();
         int m = image[0].size();
         queue<pair<pair<int,int>,int>>q;
         int visited[n][m];
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(image[i][j]==2){
                  q.push({{i,j},0});
                  visited[i][j]=2;
               }else{
                  visited[i][j]=0;
               }
            }
         }

         int deltaRow[] = {-1,0,1,0};
         int deltaCol[] = {0,1,0,-1};
         int tm = 0;
         while(!q.empty()){
            int iniRow =q.front().first.first;
            int iniCol =q.front().first.second;
            int time = q.front().second;
            tm = max(tm, time);
            q.pop();
            for(int i=0;i<4;i++){
               int nrow = iniRow + deltaRow[i];
               int ncol = iniCol + deltaCol[i];

               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==1 && visited[nrow][ncol]==0){
                  q.push({{nrow, ncol},time+1});
                  visited[nrow][ncol] = 2;
               }
            }
         }

         // this condition is used to check whether all fruits preset is riped
         for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
               if(visited[i][j]!=2 && image[i][j]==1) return -1;
            }
         }

         return tm;
      }
};

int main(){
   vector<vector<int>> image = {
      {0, 1, 2},
      {0, 1, 0},
      {2, 0, 1}
   };
   Solution s;
   cout<<s.solve(image)<<endl;
}