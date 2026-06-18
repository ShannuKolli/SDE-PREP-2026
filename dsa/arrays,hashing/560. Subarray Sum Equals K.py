"""
LC 560 — Subarray Sum Equals K
Pattern: Prefix Sum + Hash Map
Difficulty: Medium
Approach: Maintain a running prefix sum as we traverse the array.
          At each index, check if (prefix_sum - k) exists in the hashmap.
          If it does, it means there is a subarray ending at current index
          whose sum equals k. Add its frequency to the answer.
          Store each prefix sum and its frequency in the hashmap.
          Initialize map with {0:1} to handle subarrays starting from index 0.
Time Complexity: O(n)
Space Complexity: O(n)
"""
from typing import List
from collections import defaultdict

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        mp[0] = 1

        prefix_sum = 0
        count = 0

        for num in nums:
            prefix_sum += num

            if prefix_sum - k in mp:
                count += mp[prefix_sum - k]

            mp[prefix_sum] += 1

        return count