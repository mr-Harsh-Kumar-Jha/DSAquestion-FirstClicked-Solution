//https://www.codechef.com/COOK140C/problems/RECSTI

/*  MoEngage has a bundle of N sticks. The ith stick has a length Li meters.
Find the minimum number of sticks (of any length) you need to add to the bundle such that you can construct some rectangles where each stick of the bundle belongs to exactly one rectangle and each side of a rectangle should be formed with exactly one stick.

b.] Input Format
 -->The first line of the input contains a single integer T denoting the number of test cases. -->The description of T test cases follows.
 -->The first line of each test case contains a single integer N, denoting the number of given sticks.
 -->The second line of each test case contains N space-separated integers L1,L2,…,LN, denoting -->the length of the sticks.


 c.] Output Format
 For each test case, output in a single line, the minimum number of sticks you need to add to the bundle to satisfy the given conditions.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int N;
	    cin>>N;
	    int arr[N];
	    int count=0;
	    map<int , int> m;
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	        m[arr[i]]++;
	    }

	      for(auto &x:m){

	        if((x.second)%2!=0){
	            count=count+1;
	        }
	      }
	      int count2=0;
	      if((N+count)%4!=0){
	        count2=4-((N+count)%4);
	        count=count+count2;
	      }
	    cout<<count<<endl;
	}
	return 0;
}
