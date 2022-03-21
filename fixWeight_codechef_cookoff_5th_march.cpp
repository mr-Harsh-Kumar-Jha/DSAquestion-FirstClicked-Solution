/*  A permutation of length N is an array of N integers (P1,P2,…,PN) where every integer from 1 to N (inclusive) appears in it exactly once. The weight of a subsegment containing the elements (Pl,Pl+1,…,Pr) is defined as follows:
W(l,r)=(r−l+1)*minl≤i≤r(Pi)
where 1≤l≤r≤N and minl≤i≤r(Pi) denotes the minimum element of the subsegment.

You are given two integers N and X. You need to determine if there exists a permutation of length N such that it contains at least one subsegment having weight X? */

#include<iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
  int N;
  int count=0;
  long long X;
  cin >> N >> X;
  for (int i = 1; i <= N; i++) {
    if (X % i == 0 && (N - i + 1) >= X / i) {
      cout << "YES\n";
      count=1;
      break;
    }
  }
  if(count==0)
    cout << "NO\n";
  }
  return 0;
}

//Note (n-i+1)>=X/i    as given weight=(r-l+1)*min(Pi) 
// here r-l+1 will be length of a subsequence that will be selected
//  therefore formula becomes [ weight=length*min(Pi) ]   
// therefore [ weight/length=min(Pi) ]
// here in order to have min as X/i then their must exist atleast X/i size of subsiquence so that X/i will be at first position of subsiquence and will be minimum