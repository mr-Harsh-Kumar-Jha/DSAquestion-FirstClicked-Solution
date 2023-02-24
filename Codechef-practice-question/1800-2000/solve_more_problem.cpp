//https://www.codechef.com/problems/SOLVEMORE

#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>&a,vector<int>&b){ // this is a comparision factor based on the (time of solving + time of rest) , so that we can maximize problems to be solved
    if(a[0]+a[1]==b[0]+b[1]) return a[0]<b[0];
    else return a[0]+a[1]<b[0]+b[1];
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>vec(n,0),vec2(n,0);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        for(int i=0;i<n;i++){
            cin>>vec2[i];
        }
        vector<vector<int>>dp;

        for(int i=0;i<n;i++){
            dp.push_back({vec[i],vec2[i]});
        }
        sort(dp.begin(),dp.end(),compare);
        int maxs=0;
        int sum=0;
        int i=0;
        while(i<n){ // all minimum possible ans has been considered here .
            if(dp[i][0]+dp[i][1]+sum<=k){
                sum+=dp[i][0]+dp[i][1];
                maxs=max(maxs,dp[i][1]);
                i++;
            }
            else break;
        }
        vector<int>ans(n); // here we are storing the minimum time required for solving the question as the previous vector is been sorted on the basis of total time taken to pick next question , ans due this sorting all the best possible problems has been taken but now if there is some remaining time so is there any problem which can be taken , but as the sorting id done on the basis of total time taken so it is not necessary that the the next prolem is suitable as the time required can exceed the remaining time but this is not accepted only rest time can exceed , so minimum solving time been considered and the ans array is filled accordingly.

        for(int k=n-1;k>=0;k--){
            if(k==n-1) ans[k]=dp[k][0];
            else ans[k]=min(ans[k+1],dp[k][0]);
        }
        int final=i;
        if(i<n){
            int rem=k-sum;
            if(ans[i]<=rem)final++;
            else if(rem+maxs>=dp[i][0]+dp[i][1]){ // as we can leave any one resting period so we are adding maxs which is storing the maximum resting period so that we can add as many proplems as possible . eg . (4,9); (7,13); (10,10); (5,20); and the total time in hand = 55 units here all four problems can be solved but on sorting (4,9), (10,10), (7,13), (5,20) now order of solving question would be 1st --> 2nd --> 4th --> 3rd
                final++;
            }
        }
        cout<<final<<endl;
	}
	return 0;
}
