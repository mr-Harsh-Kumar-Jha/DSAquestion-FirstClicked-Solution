#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void leftRotate(int arr[], int n, int d) {
        d = d%n;
        reverse(arr, arr+d);
        reverse(arr+d, arr+n);
        reverse(arr, arr+n);
    }
};