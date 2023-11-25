#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    void bfs(queue<pair<int,int>>&q, vector<vector<int>>& vis, vector<vector<int>>& grid, int delrow[], int delcol[]){
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int l=0;l<4;l++){
                int nrow = i+delrow[l];
                int ncol = j+delcol[l];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && grid[nrow][ncol]==1){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 0, 1,0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                vis[i][0] = 1;
                q.push({i,0});
                bfs(q,vis, grid, delrow, delcol);
            }
            if(grid[i][m-1]==1){
                vis[i][m-1] = 1;
                q.push({i,m-1});
                bfs(q,vis, grid, delrow, delcol);
            }
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                vis[0][j] = 1;
                q.push({0,j});
                bfs(q,vis, grid, delrow, delcol);
            }
            if(grid[n-1][j]==1){
                vis[n-1][j] = 1;
                q.push({n-1,j});
                bfs(q,vis, grid, delrow, delcol);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    count++;
                }
            }
        }

        return count;
    }
};