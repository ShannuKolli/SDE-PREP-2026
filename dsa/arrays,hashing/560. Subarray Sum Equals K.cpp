/*
LC 560 — Subarray Sum Equals K
Pattern: Prefix Sum + Hash Map
Difficulty: Medium
Approach: Maintain a running prefix sum as we traverse the array.
          At each index, check if (prefix_sum - k) exists in the hashmap.
          If it does, it means there is a subarray ending at current index
          whose sum equals k. Add its frequency to the answer.
          Store each prefix sum and its frequency in the hashmap.
          Initialize map with {0:1} to handle subarrays starting from index 0.
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefix_sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];

            if (mp.count(prefix_sum - k)) {
                count += mp[prefix_sum - k];
            }

            mp[prefix_sum]++;
        }

        return count;
    }
};