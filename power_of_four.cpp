//https://leetcode.com/problems/power-of-four
// this is a recursive approach and its time complexity is also O(log2(n)).

#include<bits/stdc++.h>
using namespace std;

 bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n==1) return true;

        return isPowerOfFour(n/4);
    }

int main(){
   int n;
   cin>>n;
   cout<<isPowerOfFour(n)<<endl;
}