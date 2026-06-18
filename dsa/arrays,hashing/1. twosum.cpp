
/*
 * LC 1 — Two Sum
 * Pattern: Hash Map complement lookup
 * Difficulty: Easy
 * Approach: Use unordered_map to store value -> index.
 *           For each num, check if (target - num) exists in map.
 *           If yes → return indices. If no → add num to map.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}