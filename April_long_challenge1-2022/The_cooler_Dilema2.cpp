/*
The summer is at its peak in Chefland. Chef is planning to purchase a water cooler to keep his room cool. He has two options available:

Rent a cooler at the cost of X coins per month.
Purchase a cooler for Y coins.
Chef wonders what is the maximum number of months for which he can rent the cooler such that the cost of renting is strictly less than the cost of purchasing it.

B.] Input Format
The first line of input will contain an integer T — the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two integers X and Y, as described in the problem statement.

C.] Output Format
For each test case, output the maximum number of months for which he can rent the cooler such that the cost of renting is strictly less than the cost of purchasing it.

If Chef should not rent a cooler at all, output 0.

Constraints
1≤T≤1000
1≤X,Y≤109

Sample Input 1
2
5 12
5 5
Sample Output 1
2
0

*/
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long X,Y;
	    cin>>X>>Y;
	    if(Y<=X){
	        cout<<"0"<<endl;
	    }
	    else if(Y>X){
	        if(Y%X>0){
	            cout<<Y/X<<endl;
	        }
	        else{
	            cout<<(Y-1)/X<<endl;
	        }
	    }
	}
	return 0;
}
