/*
LC 42 — Trapping Rain Water
Pattern: Two Pointers
Difficulty: Hard
Approach: Use two pointers at both ends. Maintain leftMax and rightMax.
          The amount of water at any index is determined by the shorter of the 
          two boundaries. Move the pointer pointing to the smaller maximum height 
          and calculate trapped water for that spot.
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int ans = 0;

        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                ans += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                ans += rightMax - height[r];
            }
        }
        return ans;
    }
};