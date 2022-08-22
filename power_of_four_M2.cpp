// https://leetcode.com/problems/power-of-four/
// one of the fastest solution time complexity : O(log4(n))

#include<bits/stdc++.h>
using namespace std;

 bool isPowerOfFour(int n) {
        if(n!=0 && floor(log(n)/log(4))==ceil(log(n)/log(4))) return true;
        return false;
    }

int main(){
   int n;
   cin>>n;
   cout<<isPowerOfFour(n)<<endl;

}