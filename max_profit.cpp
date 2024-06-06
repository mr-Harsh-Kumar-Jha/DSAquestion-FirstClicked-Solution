#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max1 = 0;
        int i=0,j=1;
        while(i < (prices.size()-1) && j<prices.size()){
            if(prices[j]<prices[i]){
                 i++;
                 j=i+1;
            }
            else{
                max1 = max(max1,prices[j]-prices[i]);
                j+=1;
            }

        }
        return max1;
    }
};