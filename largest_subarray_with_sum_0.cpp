#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n){
        int sum = 0;
        int count = 0;
        unordered_map<int, int>map;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(sum==0){
                count = max(count, (i-0+1));
            }else{
                if(map.find(sum)==map.end()){
                    map[sum]=i;
                }else{
                    count = max(count, (i-map[sum]));
                }
            }
        }
        return count;
    }
};