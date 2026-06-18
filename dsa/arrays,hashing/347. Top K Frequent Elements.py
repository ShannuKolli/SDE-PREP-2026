"""
LC 347 — Top K Frequent Elements
Pattern: Hash Map + Bucket Sort
Difficulty: Medium
Approach: First count the frequency of each number using a hashmap.
          Then create buckets where index = frequency, and store numbers
          having that frequency at that index.
          Traverse buckets from high frequency to low frequency and collect
          elements until we get k elements.
Time Complexity: O(n)
Space Complexity: O(n)
"""
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1

        n = len(nums)
        bucket = [[] for _ in range(n + 1)]

        for num, count in freq.items():
            bucket[count].append(num)

        ans = []

        for i in range(n, 0, -1):
            for num in bucket[i]:
                ans.append(num)
                if len(ans) == k:
                    return ans

        return ans