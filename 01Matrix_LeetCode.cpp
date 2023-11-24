// time-Complexity = O(N+E) for bfs algo
//  space complexity = O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(queue<pair<pair<int,int>,int>>&q, vector<vector<int>>&ans, vector<vector<int>>&mat, vector<vector<int>>visited){
        int x[] = {-1,0,1,0};
        int y[] = {0,1,0,-1};
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int l = 0;l<4;l++){
                int nrow = i+x[l];
                int ncol = j+y[l];
                if(nrow>=0 && nrow<mat.size() && ncol>=0 && ncol<mat[0].size() && visited[nrow][ncol]!=1 && mat[nrow][ncol]==0){
                    q.push({{nrow,ncol},0});
                    visited[nrow][ncol] = 1;
                    ans[nrow][ncol] = 0;
                }else if(nrow>=0 && nrow<mat.size() && ncol>=0 && ncol<mat[0].size() && visited[nrow][ncol]!=1 && mat[nrow][ncol]==1){
                    q.push({{nrow,ncol},dist+1});
                    visited[nrow][ncol] = 1;
                    ans[nrow][ncol] = dist+1;
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0)), ans(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    ans[i][j] = 0;
                    q.push({{i, j},0});
                }
            }
        }
        bfs(q, ans, mat, vis);
        return ans;
    }
};