"""
LC 3 — Longest Substring Without Repeating Characters
Pattern: Variable Size Sliding Window + Hash Map
Difficulty: Medium

Approach:
- Use two pointers (left, right) to maintain a window.
- Expand right pointer and add character to hashmap.
- If character was seen before AND is inside current window:
    move left pointer past the previous occurrence.
- At each step track maximum window size.
- Hashmap stores last seen index of each character.

Time Complexity: O(n)
Space Complexity: O(min(n, 128))
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen = {}
        max_len = 0
        left = 0

        for right, c in enumerate(s):

            # If character was seen and is inside current window
            if c in last_seen and last_seen[c] >= left:
                left = last_seen[c] + 1

            last_seen[c] = right
            max_len = max(max_len, right - left + 1)

        return max_len