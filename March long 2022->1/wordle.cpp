//https://www.codechef.com/MARCH221C/problems/WORDLE

#include <iostream>
using namespace std;

int main() {
	int t;
	int N=5;
	cin>>t;
	while(t--){
	    string hidden;
	    string guess;
	    cin>>hidden>>guess;
	    for(int i=0;i<N;i++){
	        if(hidden[i]==guess[i])
	             cout<<"G";
	        else
	             cout<<"B";
	    }
	    cout<<endl;
	}
	return 0;
}
