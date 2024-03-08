#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X){
        map<int,int>m;
        for(int i=0;i<N;i++){
            m[A[i]]=INT_MAX;
        }

        for(int i=0;i<M;i++){
            int diff = X-B[i];
            if(m.find(diff)!= m.end() && m[diff]==INT_MAX){
                m[diff] = B[i];
            }
        }
        vector<pair<int,int>>ans;
        for(auto it:m){
            if(it.second!=INT_MAX){
                ans.push_back(make_pair(it.first, it.second));
            }
        }

        return ans;
    }
};