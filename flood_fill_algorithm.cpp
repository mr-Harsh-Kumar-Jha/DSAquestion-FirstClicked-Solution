// Time Complexity = O((n*m)*4) eq to O(n*m)
//  Space Complexity = O(n*m) as i have used another matrix to store the ans

#include<bits/stdc++.h>
using namespace std;

class Solution{
   private:
      void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int srow, int scol, int newColor, int deltaCol[], int deltaRow[], int intiColor){
         ans[srow][scol]  = newColor;
         int n = image.size();
         int m = image[0].size();
         for(int i=0;i<4;i++){
            int nrow = srow+deltaRow[i];
            int ncol = scol+deltaCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && image[nrow][ncol] == intiColor && ans[nrow][ncol]!=newColor){
               dfs(image,ans,nrow,ncol,newColor,deltaCol, deltaRow,intiColor);
            }
         }
      }
   public:
      vector<vector<int>> solve(vector<vector<int>>& image, int srow, int scol, int newColor){
            int initiColor = image[srow][scol];
            vector<vector<int>>ans = image;
            int deltaRow[] = {-1,0,1,0};
            int deltaCol[] = {0, 1, 0, -1};
            dfs(image, ans, srow,scol, newColor, deltaCol, deltaRow, initiColor);
            return ans;
      }
};

int main(){
   vector<vector<int>> image = {
      {1, 1, 0, 1},
      {0, 0, 1, 1},
      {1, 0, 1, 0},
      {0, 0, 0, 0}
   };
   int newColor = 2;
   int srow = 1;
   int scol = 1;
   Solution s;
   vector<vector<int>>ans = s.solve(image,srow,scol,newColor);
   for(int i=0;i<ans.size();i++){
      for(int j=0;j<ans[0].size();j++){
         cout<<ans[i][j]<<" ";
      }
      cout<<endl;
   }
}