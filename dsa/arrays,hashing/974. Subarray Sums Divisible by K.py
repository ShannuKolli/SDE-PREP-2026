"""
LC 974 — Subarray Sums Divisible by K
Pattern: Prefix Sum + Modulo + Hash Map
Difficulty: Medium
Approach: Compute running prefix sum.
          If two prefix sums have the same remainder when divided by k,
          then the subarray between them has sum divisible by k.
          Store frequency of each remainder in a hashmap.
          For each prefix sum, add the count of the same remainder seen before.
Time Complexity: O(n)
Space Complexity: O(min(n, k))
"""
from typing import List
from collections import defaultdict

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        mp[0] = 1

        prefix_sum = 0
        count = 0

        for num in nums:
            prefix_sum += num
            rem = prefix_sum % k

            count += mp[rem]
            mp[rem] += 1

        return count