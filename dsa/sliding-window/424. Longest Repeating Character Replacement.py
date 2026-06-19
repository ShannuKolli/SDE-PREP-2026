"""
LC 424 — Longest Repeating Character Replacement
Pattern: Variable Size Sliding Window + Frequency Array
Difficulty: Medium

Approach:
- Use two pointers (left, right) to maintain a window.
- Track frequency of each character in current window.
- Track the max frequency character in window (max_freq).
- Key Insight:
    If (window_size - max_freq) <= k
    then we can replace all other characters to make window uniform.
    → window is valid
- If condition violated, shrink from left.
- Track maximum valid window size.

Time Complexity: O(n)
Space Complexity: O(1) → only 26 letters
"""

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = {}
        left = 0
        max_freq = 0
        max_len = 0

        for right in range(len(s)):
            c = s[right]
            freq[c] = freq.get(c, 0) + 1
            max_freq = max(max_freq, freq[c])

            # Characters to replace = window_size - max_freq
            window_size = right - left + 1

            if window_size - max_freq > k:
                # Shrink window from left
                freq[s[left]] -= 1
                left += 1

            max_len = max(max_len, right - left + 1)

        return max_len