/*
LC 53 — Maximum Subarray
Pattern: Kadane's Algorithm
Difficulty: Medium
Approach: Traverse the array while maintaining the current subarray sum.
          At each index, either extend the previous subarray or start a new one
          from the current element.
          Keep track of the maximum sum seen so far.
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};