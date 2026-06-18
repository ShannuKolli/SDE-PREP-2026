"""
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
"""
from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0
        curr_sum = 0
        min_len = float("inf")

        for r in range(len(nums)):
            curr_sum += nums[r]

            while curr_sum >= target:
                min_len = min(min_len, r - l + 1)
                curr_sum -= nums[l]
                l += 1

        return 0 if min_len == float("inf") else min_len