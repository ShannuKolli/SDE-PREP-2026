/*
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
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> need;
        for (char ch : t) {
            need[ch]++;
        }

        unordered_map<char, int> window;
        int have = 0;
        int needCount = need.size();

        int minLen = INT_MAX;
        int startIdx = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char ch = s[r];
            window[ch]++;

            if (need.count(ch) && window[ch] == need[ch]) {
                have++;
            }

            while (have == needCount) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    have--;
                }

                l++;
            }
        }

        if (minLen == INT_MAX) return "";
        return s.substr(startIdx, minLen);
    }
};