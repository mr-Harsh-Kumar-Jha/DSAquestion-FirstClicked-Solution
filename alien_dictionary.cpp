#include<bits/stdc++.h>
using namespace std;

class Solution{

    private:
    vector<int> topoSort(vector<int>adj[], int k){
        vector<int>ans, topoSort(k,0);
        for(int i=0;i<k;i++){
            for(auto it:adj[i]){
                topoSort[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<k;i++){
            if(topoSort[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                topoSort[it]--;
                if(topoSort[it]==0){
                    q.push(it);
                }
            }
        }

        return ans;
    }

    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];

            int length = min(s1.size(), s2.size());
            for(int j=0;j<length;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }

        vector<int>vec = topoSort(adj,K);
        string ans = "";
        for(auto it :vec){
            ans=ans+char(it + 'a');
        }
        return ans;
    }
};