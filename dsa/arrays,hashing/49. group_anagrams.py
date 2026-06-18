"""
LC 49 — Group Anagrams
Pattern: Hash Map + Frequency Count (Tuple Key)
Difficulty: Medium
Time: __ min
Approach: Use an immutable tuple of 26 character counts as a dictionary key.
          Anagrams have identical counts for every character, so they
          will map to the same tuple key.
Time Complexity: O(n * k) — where n is number of strings, k is max string length.
Space Complexity: O(n * k)
"""
from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # defaultdict(list) handles missing keys by creating an empty list
        mp = defaultdict(list)

        for s in strs:
            # Step 1: Initialize list of 26 zeros
            count = [0] * 26
            for char in s:
                count[ord(char) - ord('a')] += 1
            
            # Step 2: Convert list to tuple to use as hashable dict key
            # Step 3: Append original string to the group
            mp[tuple(count)].append(s)

        # Step 4: Convert map values view to a final nested list
        return list(mp.values())