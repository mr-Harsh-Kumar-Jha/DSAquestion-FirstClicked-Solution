// Chef has an array A of length N. He defines the alternating sum of the array as:

// S=|A1|−|A2|+|A3|−|A4|+…(−1)N−1⋅|AN|
// Chef is allowed to perform the following operation on the array at most once:

// Choose two indices i and j (1≤i<j≤N) and swap the elements Ai and Aj.
// Find the maximum alternating sum Chef can achieve by performing the operation at most once.

// Note: |X| denotes the absolute value of X. For example, |−4|=4 and |7|=7.

//  # sample input
// 2
// 2
// 10 -10
// 7
// -3 -2 -1 0 1 2 3


#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    ll n,s=0;
	    cin>>n;
	    vector<long long> arr(n),k,m;
	    for(auto &X:arr) cin>>X;
	    for(int i=0;i<n;i++){
	        if(i&1)k.push_back(abs(arr[i]));
	        else m.push_back(abs(arr[i]));
	    }
	    sort(k.begin(), k.end());
	    sort(m.begin(), m.end());
	    if(k[k.size()-1]>m[0])
	       swap(k[k.size()-1],m[0]);
	    for(auto X:m) s+=X;
	    for(auto X:k) s-=X;
	    cout<<s<<endl;
	}
	return 0;
}
