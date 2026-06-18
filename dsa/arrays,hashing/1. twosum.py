"""
LC 1 — Two Sum
Pattern: Hash Map complement lookup
Difficulty: Easy
Time: __ min
Approach: Use dict to store value -> index.
          For each num, check if (target - num) exists in map.
          If yes -> return indices. If no -> add num to map.
Time Complexity: O(n)
Space Complexity: O(n)
"""
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        n = len(nums)
        for i in range(n):
            val = target - nums[i]
            if val in mp:
                return [i, mp[val]]
            mp[nums[i]] = i
        return []