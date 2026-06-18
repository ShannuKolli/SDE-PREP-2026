/*
LC 56 — Merge Intervals
Pattern: Sorting + Interval Merging
Difficulty: Medium
Approach: Sort intervals by starting time.
          Start with the first interval in the answer.
          For each next interval:
          - if it overlaps with the last merged interval, merge them
          - otherwise, add it as a new interval
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};