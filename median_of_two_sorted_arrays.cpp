// this is the brute force approach
// Time complexity:- O(nlog(n)+mlog(m))
// Space Complexity:- m+n

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> collection_of_numbers;
        for(auto it: nums1){
            collection_of_numbers.insert(it);
        }
        for(auto it: nums2){
            collection_of_numbers.insert(it);
        }
        int mid = collection_of_numbers.size()/2;
        auto it = collection_of_numbers.begin();
        if(collection_of_numbers.size()%2 == 0){
            auto prev_id = it;
            for(int i=0;i<mid;i++){
                it++;
                if(i==(mid-2)){
                    prev_id = it;
                }
            }
            return double(double((*it) + (*prev_id))/2);
        }

        for(int i=0;i<mid;i++){
            it++;
        }

        return double(*it);
    }
};