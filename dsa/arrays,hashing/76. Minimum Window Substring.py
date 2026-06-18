"""
LC 76 — Minimum Window Substring
Pattern: Sliding Window + Hash Map
Difficulty: Hard
Approach: Store frequency of characters needed from string t.
          Expand the right pointer to include characters into the window.
          When the window satisfies all required characters, try shrinking
          from the left to get the minimum valid window.
          Track the smallest valid window seen so far.
Time Complexity: O(m + n)
Space Complexity: O(1)
"""
from typing import List

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s):
            return ""

        need = {}
        for ch in t:
            need[ch] = need.get(ch, 0) + 1

        window = {}
        have = 0
        need_count = len(need)

        min_len = float("inf")
        start_idx = 0

        l = 0
        for r in range(len(s)):
            ch = s[r]
            window[ch] = window.get(ch, 0) + 1

            if ch in need and window[ch] == need[ch]:
                have += 1

            while have == need_count:
                if r - l + 1 < min_len:
                    min_len = r - l + 1
                    start_idx = l

                left_char = s[l]
                window[left_char] -= 1

                if left_char in need and window[left_char] < need[left_char]:
                    have -= 1

                l += 1

        if min_len == float("inf"):
            return ""

        return s[start_idx:start_idx + min_len]