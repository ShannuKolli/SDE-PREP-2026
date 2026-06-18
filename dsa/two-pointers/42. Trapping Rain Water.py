"""
LC 42 — Trapping Rain Water
Pattern: Two Pointers
Difficulty: Hard
Approach: Use two pointers at both ends. Maintain left_max and right_max.
          Water trapped is limited by the shorter boundary. 
          If left_max is smaller, we know the bottleneck for the current left index
          is left_max, so we calculate water and move left. Otherwise, move right.
Time Complexity: O(n)
Space Complexity: O(1)
"""
from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
            
        l, r = 0, len(height) - 1
        left_max, right_max = height[l], height[r]
        ans = 0
        
        while l < r:
            if left_max < right_max:
                l += 1
                left_max = max(left_max, height[l])
                ans += left_max - height[l]
            else:
                r -= 1
                right_max = max(right_max, height[r])
                ans += right_max - height[r]
                
        return ans