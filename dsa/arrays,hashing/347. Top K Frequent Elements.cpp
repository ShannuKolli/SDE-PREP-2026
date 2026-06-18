/*
LC 347 — Top K Frequent Elements
Pattern: Hash Map + Bucket Sort
Difficulty: Medium
Approach: First count the frequency of each number using a hashmap.
          Then create buckets where index = frequency, and store numbers
          having that frequency at that index.
          Traverse buckets from high frequency to low frequency and collect
          elements until we get k elements.
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto& it : freq) {
            int num = it.first;
            int count = it.second;
            bucket[count].push_back(num);
        }

        vector<int> ans;

        for (int i = n; i >= 1; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};