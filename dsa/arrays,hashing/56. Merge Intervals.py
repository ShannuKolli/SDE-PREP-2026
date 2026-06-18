"""
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
"""
from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        ans = [intervals[0]]

        for i in range(1, len(intervals)):
            if intervals[i][0] <= ans[-1][1]:
                ans[-1][1] = max(ans[-1][1], intervals[i][1])
            else:
                ans.append(intervals[i])

        return ans