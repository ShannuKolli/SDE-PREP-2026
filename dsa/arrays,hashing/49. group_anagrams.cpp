/*
LC 49 — Group Anagrams
Pattern: Hash Map + Frequency Count (Counting Sort Key)
Difficulty: Medium
Time: __ min
Approach: Avoid O(k log k) sorting by counting character frequencies. 
          Create a string key like "1#0#2..." where each number represents 
          the count of 'a' through 'z'. Use this unique key in a hash map.
Time Complexity: O(n * k) — where n is number of strings, k is max string length.
Space Complexity: O(n * k)
*/

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (const string& s : strs) {
            // Step 1: Count character frequencies (a-z)
            int count[26] = {0};
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // Step 2: Build a unique key based on counts
            // Using '#' ensures counts like (1, 11) don't collide with (11, 1)
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(count[i]);
            }
            
            // Step 3: Group by key
            mp[key].push_back(s);
        }
        
        // Step 4: Extract groups from map
        vector<vector<string>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};