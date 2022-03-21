// https://www.codechef.com/MARCH221C/problems/SUB_XOR

//the trick is very simple as 1st position of binary string will always remain same and  if first position is 1 than then in order to find other position we will run for loop for 1 index and by observation second will definately be 1 so inorder to give ' 1 ' as value on 2nd position there must exist some odd integer whose module 2 would be '1'  therefore we will create a if condition which will work only if ith position will coonsist of '1' and not '0' as '0' means false sor it copies previous value

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll M=998244353;

int main() {
	int t;
	cin>>t;
	while(t--){
	    ll len;
	    cin>>len;
	    string str;
	    cin>>str;
	    long long  var=0;
	    long long  arr[len];
        if(str[0]=='1'){
            var=1;
        }
	   arr[0]=var;
	   for(int i=1;i<len;i++){
	       if(str[i]=='1'){
	           var+=(i+1);
	       }
	       arr[i]=var%2;
	   }

	   int dec_value = 0;
       int base = 1;
       for (int i = len - 1; i >= 0; i--) {
            if (arr[i] == 1)
              dec_value=(dec_value+ base)%M;
            base = (base * 2)%M;
        }
        cout<<dec_value<<endl;

	}

	return 0;
}
