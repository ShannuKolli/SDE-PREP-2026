/*
LC 128 — Longest Consecutive Sequence
Pattern: Hash Set + Sequence Start Detection
Difficulty: Medium
Time: __ min
Approach: Insert all numbers into an unordered_set for O(1) lookup.
          A number starts a sequence only if (num - 1) is not present.
          From each valid start, keep extending forward: num + 1, num + 2...
          Track the maximum sequence length.
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            // only start counting if num is the beginning of a sequence
            if (st.find(num - 1) == st.end()) {
                int currNum = num;
                int currLen = 1;

                while (st.find(currNum + 1) != st.end()) {
                    currNum++;
                    currLen++;
                }

                longest = max(longest, currLen);
            }
        }

        return longest;
    }
};