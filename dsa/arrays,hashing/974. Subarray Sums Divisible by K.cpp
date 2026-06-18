/*
LC 974 — Subarray Sums Divisible by K
Pattern: Prefix Sum + Modulo + Hash Map
Difficulty: Medium
Approach: Compute running prefix sum.
          If two prefix sums have the same remainder when divided by k,
          then the subarray between them has sum divisible by k.
          Store frequency of each remainder in a hashmap.
          For each prefix sum, add the count of the same remainder seen before.
          Normalize modulo in C++ to handle negative numbers properly.
Time Complexity: O(n)
Space Complexity: O(min(n, k))
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefix_sum = 0;
        int count = 0;

        for (int num : nums) {
            prefix_sum += num;

            int rem = ((prefix_sum % k) + k) % k;

            if (mp.count(rem)) {
                count += mp[rem];
            }

            mp[rem]++;
        }

        return count;
    }
};