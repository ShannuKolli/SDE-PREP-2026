/*
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
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int left = 0;
        int max_freq = 0;
        int max_len = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            max_freq = max(max_freq, freq[s[right] - 'A']);

            // Characters to replace = window_size - max_freq
            int window_size = right - left + 1;

            if (window_size - max_freq > k) {
                // Shrink window from left
                freq[s[left] - 'A']--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};