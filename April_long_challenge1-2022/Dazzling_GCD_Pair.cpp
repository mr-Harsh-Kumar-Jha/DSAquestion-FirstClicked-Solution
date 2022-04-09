// https://www.codechef.com/APRIL221C/problems/NOTUNIT

/*
Dazzler has a task for you.

Given two positive integers A and B, find two positive integers i and j such that:

gcd(i,j)>1;
A≤i<j≤B;
The value (i+j) is minimum possible.
If there are multiple solutions, you may print any of them. If no such pair exists, print −1.

B.] Input Format
First line will contain T, number of test cases. Then the test cases follow.
Each test case contains of a single line of input, two integers A and B.

C.] Output Format
For each test case, output in a single line two space-separated integers i and j satisfying all the conditions. If no such pair exists, print −1.

Constraints
1≤T≤105
1≤A<B≤109

Sample Input 1
2
2 3
2 10
Sample Output 1
-1
2 4

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
	    long long a,b;
	    cin>>a>>b;
	    if(a%2==0){
	        if(b-a>=2){
	            cout<<a<<" "<<a+2<<endl;
	        }
	        else{
	            cout<<"-1"<<endl;
	        }
	    }
	    else{
	        if(b-a>=3){
	            if(a%3==0){
	                cout<<a<<" "<<a+3<<endl;
	            }
	            else{
	                 cout<<a+1<<" "<<a+3<<endl;
	            }
	        }
	        else{
	            cout<<"-1"<<endl;
	        }
	    }

	}
	return 0;
}
