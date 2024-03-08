#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
};