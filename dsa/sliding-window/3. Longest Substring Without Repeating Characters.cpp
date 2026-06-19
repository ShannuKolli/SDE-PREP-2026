/*
LC 3 — Longest Substring Without Repeating Characters
Pattern: Variable Size Sliding Window + Hash Map
Difficulty: Medium

Approach:
- Use two pointers (left, right) to maintain a window.
- Expand right pointer and add character to hashmap.
- If a character is seen before AND is inside current window:
    move left pointer past the previous occurrence.
- At each step track maximum window size.
- Hashmap stores last seen index of each character.

Time Complexity: O(n)
Space Complexity: O(min(n, 128)) → at most 128 ASCII characters
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // If character was seen and is inside current window
            if (last_seen.count(c) && last_seen[c] >= left) {
                left = last_seen[c] + 1;
            }

            last_seen[c] = right;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};