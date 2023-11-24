#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board, int delrow[], int delcol[]){
        vis[i][j]=1;
        int n = board.size();
        int m = board[0].size();
        for(int l=0;l<4;l++){
            int nrow = i+delrow[l];
            int ncol = j+delcol[l];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && board[nrow][ncol]=='O'){
                dfs(nrow,ncol, vis, board, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(0,j,vis,board, delrow, delcol);
            if(board[n-1][j]=='O') dfs(n-1,j,vis,board, delrow, delcol);
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(i,0,vis,board, delrow, delcol);
            if(board[i][m-1]=='O') dfs(i,m-1,vis,board, delrow, delcol);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
    }
};