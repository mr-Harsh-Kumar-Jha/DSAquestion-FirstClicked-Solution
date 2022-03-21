//https://www.codechef.com/MARCH221C/problems/CHFCLASS

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int N;
	    cin>>N;
	    if(N%7==6){
	        cout<<(N/7)+1<<endl;
	    }
	    else
	       cout<<N/7<<endl;
	}
	return 0;
}