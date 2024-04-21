// time Complexity:- O(N)
//  Question :- Given an array Arr, with indexes running from 0 to N, select any two indexes, i and j such that i<=j-1. From subarray Arr[i...j], find the two smallest numbers and add them, you will get score for that subarray. Your task is to return maximum score possible in the given array Arr.
//  Test Cases:-
// Input : arr[] = [4, 3, 1, 5, 6]
// Output : 11
// Subarrays with smallest and
// second smallest are,
// [4, 3]
// smallest = 3    second smallest = 4
// [4, 3, 1]
// smallest = 1    second smallest = 3
// [4, 3, 1, 5]
// smallest = 1    second smallest = 3
// [4, 3, 1, 5, 6]
// smallest = 1    second smallest = 3
// [3, 1]
// smallest = 1    second smallest = 3
// [3, 1, 5]
// smallest = 1    second smallest = 3
// [3, 1, 5, 6]
// smallest = 1    second smallest = 3
// [1, 5]
// smallest = 1    second smallest = 5
// [1, 5, 6]
// smallest = 1    second smallest = 5
// [5, 6]
// smallest = 5    second smallest = 6
// Maximum sum among all
// above choices is, 5 + 6 = 11

// Example 2:
// Input : arr[] = {5, 4, 3, 1, 6}
// Output : 9

// Approach:- As they have asked for pairs with max sum in subarray of array so we just need to always take a sum of i and i+1th element;

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N){
            long long sum = 0, maxSum = 0;
            for(int i=0;i<N-1;i++){
                sum = arr[i]+arr[i+1];
                maxSum = max(sum, maxSum);
            }
            return maxSum;
        }
};

