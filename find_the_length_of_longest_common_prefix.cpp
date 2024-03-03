#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        int ans = 0;

        for(int i=0;i<arr1.size();i++){
            string strings = to_string(arr1[i]);
            string prefix = "";
            for(auto it:strings){
                prefix+=it;
                st.insert(prefix);
            }

        }

        for(int i=0;i<arr2.size();i++){
            string prefix = "";
            for(auto it:to_string(arr2[i])){
                prefix+=it;
                if(st.count(prefix)){
                    ans = max(ans, (int)prefix.size());
                }
            }
        }
        
        return ans;
    }
};