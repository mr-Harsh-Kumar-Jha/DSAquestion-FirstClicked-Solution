//Time complexity :- O(no. of digits in a number given )

#include <bits/stdc++.h>

using namespace std;

long long int reversDigits(int num){
    long long int rev_num = 0;
    while (num != 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
void reverse(int x) {
    long long int rev = reversDigits(x);
    if(rev > INT_MAX || rev<INT_MIN) cout<< 0;
    else cout<<rev;
}

int main(){
    int x;
    cin>>x;
    reverse(x);
}
//2147483647
