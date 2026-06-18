"""
LC 11 — Container With Most Water
Pattern: Two Pointers
Difficulty: Medium
Approach: Use two pointers at the extreme ends of the array.
          Calculate the area between them: min(height[l], height[r]) * width.
          To potentially find a larger area, move the pointer pointing to the 
          shorter line, as the height is the limiting factor.
Time Complexity: O(n)
Space Complexity: O(1)
"""
from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_water = 0
        l = 0
        r = len(height) - 1

        while l < r:
            # Area = height of shorter bar * distance between bars
            h = min(height[l], height[r])
            w = r - l
            max_water = max(max_water, h * w)

            # Greedily move the pointer that is shorter
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
                
        return max_water