//https://www.codechef.com/COOK140C/problems/DIGSMPAR

/* For a positive integer M, MoEngage defines 𝚍𝚒𝚐𝚒𝚝𝚂𝚞𝚖(𝙼) as the sum of digits of the number M (when written in decimal).

For example, 𝚍𝚒𝚐𝚒𝚝𝚂𝚞𝚖(𝟷𝟶𝟸𝟹)=1+0+2+3=6.

Given a positive integer N, find the smallest integer X strictly greater than N such that:

𝚍𝚒𝚐𝚒𝚝𝚂𝚞𝚖(𝙽) and 𝚍𝚒𝚐𝚒𝚝𝚂𝚞𝚖(𝚇) have different parity, i.e. one of them is odd and the other is even.

b.] Input Format
The first line contains an integer T, the number of test cases. The description of the T test cases follow.
Each test case consists of a single line of input with a single integer, the number N.

c.] Output Format
For each test case, print in a single line, an integer, the answer to the problem.

Sample Input 1
3
123
19
509
Sample Output 1
124
21
511


*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long N;
	    cin>>N;
	    int x=N;
	    int count=0;
	    int count2=0;
	    while(x){
	        count=count+(x%10);
	        x=x/10;
	    }
	    x=N+1;
	    while(x){
	        count2=count2+(x%10);
	        x=x/10;
	    }
	    if(count%2==0){
	        if(count2%2!=0){
	            cout<<N+1<<endl;
	        }
	        else{
	           cout<<N+2<<endl;
	        }
	   }
	   else{
	        if(count2%2!=1){
	            cout<<N+1<<endl;
	        }
	        else{
	           cout<<N+2<<endl;
	        }
	   }
	}
	return 0;
}
