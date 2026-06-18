"""
LC 128 — Longest Consecutive Sequence
Pattern: Hash Set + Sequence Start Detection
Difficulty: Medium
Time: __ min
Approach: Insert all numbers into a set for O(1) lookup.
          A number starts a sequence only if (num - 1) is not present.
          From each valid start, keep extending forward: num + 1, num + 2...
          Track the maximum sequence length.
Time Complexity: O(n)
Space Complexity: O(n)
"""
from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set(nums)
        longest = 0

        for num in st:
            # only start counting if num is the beginning of a sequence
            if num - 1 not in st:
                curr_num = num
                curr_len = 1

                while curr_num + 1 in st:
                    curr_num += 1
                    curr_len += 1

                longest = max(longest, curr_len)

        return longest