"""
LC 53 — Maximum Subarray
Pattern: Kadane's Algorithm
Difficulty: Medium
Approach: Traverse the array while maintaining the current subarray sum.
          At each index, either extend the previous subarray or start a new one
          from the current element.
          Keep track of the maximum sum seen so far.
Time Complexity: O(n)
Space Complexity: O(1)
"""
from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr_sum = nums[0]
        max_sum = nums[0]

        for i in range(1, len(nums)):
            curr_sum = max(nums[i], curr_sum + nums[i])
            max_sum = max(max_sum, curr_sum)

        return max_sum