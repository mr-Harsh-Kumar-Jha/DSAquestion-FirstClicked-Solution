#include<bits/stdc++.h>
using namespace std ;

bool dfs(int i, int col, int v, vector<int>adj[], vector<int>&ans){
        ans[i]=col;
        for(auto it:adj[i]){
            if(ans[it]==-1){
                if(dfs(it,!col, v, adj, ans)==false) return false;
            }else if(ans[it]==col){
                return false;
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>ans(V,-1);
	    for(int i=0;i<V;i++){
	         if(ans[i]==-1){
	            if(dfs(i, 0, V, adj, ans)==false) return false;
	        }
	    }
	    return true;
	}