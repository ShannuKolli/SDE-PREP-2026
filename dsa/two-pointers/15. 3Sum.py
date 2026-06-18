"""
LC 15 — 3Sum
Pattern: Sorting + Two Pointers
Difficulty: Medium
Approach: Sort the array first.
          Fix one number nums[i], then use two pointers left and right
          to find pairs such that nums[i] + nums[left] + nums[right] == 0.
          Skip duplicates for i, left, and right to avoid repeated triplets.
Time Complexity: O(n^2)
Space Complexity: O(1) extra space excluding output
"""
from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        n = len(nums)

        nums.sort()

        for i in range(n):
            # Skip duplicate fixed elements
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1
            right = n - 1

            while left < right:
                total = nums[i] + nums[left] + nums[right]

                if total == 0:
                    ans.append([nums[i], nums[left], nums[right]])

                    left += 1
                    right -= 1

                    # Skip duplicate left values
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1

                    # Skip duplicate right values
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1

                elif total < 0:
                    left += 1
                else:
                    right -= 1

        return ans