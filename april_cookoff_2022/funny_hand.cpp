//https://www.codechef.com/COOK140C/problems/FUNHAND

/* MoEngage has 3 decks. Each deck consists of N cards, numbered from 1 to N. He draws out 1 card from each deck randomly with each card having an equal probability of being drawn.

MoEngage drew cards numbered A and B from the decks 1 and 2 respectively. Now, he wonders what is the probability that he will end up with a funny hand after drawing the third card.

A funny hand is when 3 consecutive numbered cards are present in your hand.
Help MoEngage calculate the probability of ending up with a funny hand after drawing the third card.

If the final probability of ending up with a funny hand is P, you need to print the value P⋅N. It can be shown that this value is an integer.

Input Format
First line will contain T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input consisting of three space-separated integers N,A, and B denoting the size of each deck, the card drawn from the first deck, and the card drawn from the second deck respectively.
Output Format
For each test case, output a single integer, denoting P⋅N on a separate line.

Sample Input 1
3
4 2 3
6 2 1
5 2 5
Sample Output 1
2
1
0

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int  N,a,b;
	    cin>>N>>a>>b;
	    if(N<=2)
	       cout<<"0"<<endl;
	    else if(abs(a-b)==0){
	        cout<<"0"<<endl;
	    }
	    else if(abs(a-b)>2){
	        cout<<"0"<<endl;
	    }
	    else if((a==1 or a==N) || (b==1 or b==N)){
	        cout<<"1"<<endl;
	    }
	    else{
	        if(abs(a-b)==2){
	            cout<<"1"<<endl;
	        }
	        else{
	            cout<<"2"<<endl;
	        }
	    }
	}
	return 0;
}
