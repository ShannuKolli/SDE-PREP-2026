/*
LC 167 — Two Sum II - Input Array Is Sorted
Pattern: Two Pointers
Difficulty: Medium
Approach: Since the array is already sorted, use two pointers:
          one at the beginning and one at the end.
          If the sum is too small, move left pointer forward.
          If the sum is too large, move right pointer backward.
          If the sum matches target, return 1-based indices.
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];

            if (sum == target) {
                return {l + 1, r + 1};
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }

        return {};
    }
};