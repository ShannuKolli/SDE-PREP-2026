"""
LC 238 — Product of Array Except Self
Pattern: Prefix Product + Suffix Product
Difficulty: Medium
Approach: Do not use division.
          First pass: store prefix product at each index.
          Second pass: traverse from right and multiply with suffix product.
          This gives product of all elements except self.
Time Complexity: O(n)
Space Complexity: O(1) extra space (excluding output array)
"""
from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n

        prefix = 1
        for i in range(n):
            ans[i] = prefix
            prefix *= nums[i]

        suffix = 1
        for i in range(n - 1, -1, -1):
            ans[i] *= suffix
            suffix *= nums[i]

        return ans