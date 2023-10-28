#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void DFS(int node, vector<int>&visited, vector<int>array[]){
        visited[node] = 1;
        for(auto it:array[node]){
            if(!visited[it])
                DFS(it, visited, array);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int>listConnect[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    listConnect[i].push_back(j);
                    listConnect[j].push_back(i);
                }
            }
        }
        vector<int>visited(v,0);
        int countProvience = 0;
        for(int i = 0;i<v;i++){
            if(visited[i]!=1){
                countProvience++;
                DFS(i, visited, listConnect);
            }
        }

        return countProvience;
    }
};

int main(){
    Solution soln ;
    vector<vector<int>>adj ;
    adj = {{1,1,0},
       {1,1,0},
       {0,0,1}};
    cout<<soln.findCircleNum(adj)<<endl;
}