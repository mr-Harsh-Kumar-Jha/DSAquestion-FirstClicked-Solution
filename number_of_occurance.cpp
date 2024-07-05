#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	void solve(int arr[], int left, int right, int x, int& higher_end, int& lower_end){
	    if(left>right) return;
	    int mid = (left+right+1)/2;
        if(x==arr[mid]){
            if(mid > higher_end){
                higher_end = mid;
                solve(arr ,mid+1 ,right ,x , higher_end, lower_end);
            }
            if (mid < lower_end){
                lower_end = mid;
                solve(arr ,left ,mid-1 ,x , higher_end, lower_end);
            }
        }else if(x<arr[mid]){
            solve(arr ,left ,mid-1 ,x , higher_end, lower_end);
        }else{
            solve(arr ,mid+1 ,right ,x , higher_end, lower_end);
        }
	}
	int count(int arr[], int n, int x) {
	    int left = 0;
	    int right = n;
	    int lower_end = INT_MAX, higher_end = INT_MIN;
	    solve(arr, 0, n, x, higher_end, lower_end);
	    if(higher_end==INT_MIN && lower_end==INT_MAX){
	        return 0;
	    }

	    return higher_end-lower_end+1;

	}
};