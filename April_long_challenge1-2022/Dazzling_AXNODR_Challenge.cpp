// https://www.codechef.com/APRIL221C/problems/AXNODR

/*
 Dazzler has a blank canvas and (N−1) colours numbered from 2 to N.
Let B denote the beauty of the canvas. The beauty of a blank canvas is 1.

Dazzler paints the canvas by using all the (N−1) colours exactly once. On applying the ith colour (2≤i≤N):

If i is odd, B=B & i.
If i is even, B=B⊕i.
Find the beauty of the canvas after applying all (N−1) colours.

Note: The colours are applied in ascending order. Colour number 2 is applied first. The ith numbered colour is applied after (i−1)th numbered colour for all i>2.

Here & and ⊕ denote the bitwise AND and bitwise XOR operations respectively.

b.] Input Format
First line will contain T, the number of test cases. Then the test cases follow.
Each test case contains of a single line of input, a single integer N.

c.] Output Format
For each test case, output a single integer, the beauty of the canvas after applying all (N−1) colours.

Constraints
1≤T≤105
2≤N≤1016

Sample Input 1
2
4
10
Sample Output 1
7
3

*/

#include <iostream>
#define ll long long int
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    ll N;
	    cin>>N;
	    if(N%4==1){
	        cout<<N<<endl;
	    }
	    else if(N%4==0){
	        cout<<N+3<<endl;
	    }
	    else if(N%4>1){
	        cout<<"3"<<endl;
	    }
	}
	return 0;
}
