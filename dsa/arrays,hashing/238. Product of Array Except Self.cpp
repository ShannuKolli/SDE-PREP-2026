/*
LC 238 — Product of Array Except Self
Pattern: Prefix Product + Suffix Product
Difficulty: Medium
Time: __ min
Approach: Do not use division.
          First pass: store prefix product at each index.
          Second pass: traverse from right and multiply with suffix product.
          This gives product of all elements except self.
Time Complexity: O(n)
Space Complexity: O(1) extra space (excluding output array)
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};