/*
LC 209 — Minimum Size Subarray Sum
Pattern: Sliding Window
Difficulty: Medium
Approach: Use two pointers l and r to maintain a window.
          Expand the window by moving r to the right and adding to current sum.
          When current sum >= target, try to shrink the window from the left
          to find the minimum valid window.
          Keep tracking the minimum length seen so far.
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int curr_sum = 0;
        int min_len = INT_MAX;

        for (int r = 0; r < nums.size(); r++) {
            curr_sum += nums[r];

            while (curr_sum >= target) {
                min_len = min(min_len, r - l + 1);
                curr_sum -= nums[l];
                l++;
            }
        }

        return min_len == INT_MAX ? 0 : min_len;
    }
};