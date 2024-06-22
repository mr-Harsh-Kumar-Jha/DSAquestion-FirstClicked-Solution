#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool compare(vector<int>&a, vector<int>&b){
        if (a[0] < b[0])
            return true;
        else if(a[0]==b[0] && a[1]<b[1]){
            return true;
        }else{
            return false;
        }
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end(), compare);
        ans.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= ans[j][1]){
                if(ans[j][1]<intervals[i][1]){
                    ans[j][1] = intervals[i][1];
                }
                if(ans[j][0] > intervals[i][1]){
                    ans[j][0] = intervals[i][0];
                }
            }else{
                ans.push_back(intervals[i]);
                j++;
            }
        }

        return ans;
    }
};