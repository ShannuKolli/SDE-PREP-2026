"""
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
"""
from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1

        while l < r:
            total = numbers[l] + numbers[r]

            if total == target:
                return [l + 1, r + 1]
            elif total < target:
                l += 1
            else:
                r -= 1

        return []