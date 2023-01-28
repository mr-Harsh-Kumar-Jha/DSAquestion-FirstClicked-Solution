#include <bits/stdc++.h>

using namespace std;

int nearPowerOftwo(int n){
    int i=0;
    while((int)(pow(2,i)) <= n){
        i+=1;
    }
    return i-1;
}

int countSetBits(int n) {
   if(n<=0) return 0;
   int k = nearPowerOftwo(n);
   int totBefK = k * (1 << (k-1));
   int totAfterK = n - (1 << k)+1;
   int rem= n - (1 << k);
   int ans = totBefK + totAfterK + countSetBits(rem);
   return ans;
}

int main()
{
    int n =10;
    cout<<countSetBits(n)<<endl;
    return 0;
}