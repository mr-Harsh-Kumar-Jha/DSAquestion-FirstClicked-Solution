#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void BFS(int i, int j, int n, int m, vector<vector<char>>&grid, vector<vector<int>>&vis){
        vis[i][j] = 1;
        queue<pair<int,int>>queue;
        queue.push({i,j});
        while(!queue.empty()){
            int row = queue.front().first;
            int col = queue.front().second;
            queue.pop();

            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    if((k==-1 && l==0) || (k ==1 && l ==0) || (k==0 && l==-1) || (k==0 && l==1)){
                        int nrow=row+k;
                        int ncol=col+l;

                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                            queue.push({nrow,ncol});
                            vis[nrow][ncol] = 1;
                        }
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]!='0'){
                    count++;
                    BFS(i, j, n, m, grid, vis);
                }
            }
        }
        return count;
    }
};

int main(){
    Solution soln ;
    vector<vector<char>>adj ;
    adj = {{'0','1','1','1','0','0','0'},{'0','0','1','1','0','1','0'}};
    cout<<soln.numIslands(adj)<<endl;
}