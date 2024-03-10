#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> ans[n];
        for(int j=0;j<n;j++){
            ans[j].push_back(1);
            for(int i=1;i<j;i++){
                ans[j].push_back((ans[j-1][i-1]+ans[j-1][i])%1000000007);
            }
            if(j!=0)
                ans[j].push_back(1);
        }

        return ans[n-1];
    }
};