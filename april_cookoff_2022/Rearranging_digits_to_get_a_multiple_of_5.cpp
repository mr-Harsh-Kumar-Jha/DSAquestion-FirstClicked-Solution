// https://www.codechef.com/COOK140C/problems/DIGARR

/* Given a positive integer N, MoEngage wants you to determine if it is possible to rearrange the digits of N (in decimal representation) and obtain a multiple of 5.

For example, when N=108, we can rearrange its digits to construct 180=36⋅5 which is a multiple of 5.

b.] Input Format
The first line contains an integer T, the number of test cases. The description of the T test cases follow.
Each test case consists of two lines
The first line contains a single integer D, the number of digits in N.
The second line consists of a string of length D, the number N (in decimal representation). It is guaranteed that the string does not contain leading zeroes and consists only of the characters 0,1,…9.

c.] Output Format
For each test case, print 𝚈𝚎𝚜 if it is possible to rearrange the digits of N so that it becomes a multiple 5. Otherwise, print 𝙽𝚘.
You may print each character of the string in uppercase or lowercase (for example, the strings 𝚈𝚎𝚂, 𝚢𝙴𝚜, 𝚢𝚎𝚜 and 𝚈𝙴𝚂 will all be treated as identical).

Sample Input 1
3
3
115
3
103
3
119
Sample Output 1
Yes
Yes
No

*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int N;
	    cin>>N;
	    string s;
	    cin>>s;
	    int count=0;
	    for(int i=0;i<N;i++){
	        if(s[i]=='0' || s[i]=='5'){
	            count=count+1;
	            break;
	        }
	    }
	    if(count>0){
	        cout<<"yes"<<endl;
	    }
	    else
	      cout<<"no"<<endl;
	}
	return 0;
}
