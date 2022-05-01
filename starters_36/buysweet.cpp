// https://www.codechef.com/problems/BUYSWEET

/*
 There are N sweets in the store. The cost of the ith sweet is Ai rupees. Chef is a regular customer, so after buying the ith sweet, he gets a cashback of Bi rupees.

Chef has R rupees. He is fond of all the sweets, so he wants you to calculate the maximum number of sweets he can buy. Note that he can buy the same type of sweet multiple times, as long as he has the money to do so.

Input Format
The first line of input will contain T, the number of test cases.
Each test case consists of three lines of input.
The first line of each test case contains two space-separated integers N and R — the number of sweets in the shop and the amount of money Chef has.
The second line of each test case contains N space-separated integers A1,A2,…,AN.
The third line of each test case contains N space-separated integers B1,B2,…,BN.
Output Format
For each query, print on a new line the maximum number of sweets Chef can buy.

Constraints
1≤T≤2⋅105
1≤N≤2⋅105
1≤Bi<Ai≤109
1≤R≤109
It is guaranteed that the sum of N over all test cases does not exceed 2⋅105

Sample Input 1
3
3 3
2 3 4
1 1 1
2 4
5 4
1 2
4 10
4 4 5 5
1 2 4 2
Sample Output 1
2
1
7

*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,r;
    cin>>n>>r;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<pair<int,int>>p;
    for(int i=0;i<n;i++) p.push_back({a[i]-b[i],a[i]});
    sort(p.begin(),p.end());
    int ans=0;
    for(auto x:p){
        if(r>=x.second){
            int temp=r-x.second;
            ans += temp/x.first +1;
            r -= x.first*(temp/x.first + 1);
        }
    }
    cout<<ans<<endl;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
