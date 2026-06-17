// =============================================
// SLIDING WINDOW TEMPLATE
// Use when: find max/min subarray, substring with condition
// =============================================

// FIXED SIZE WINDOW
int fixedWindow(vector<int>& arr, int k) {
    int sum = 0, maxSum = 0;
    // Build first window
    for (int i = 0; i < k; i++) sum += arr[i];
    maxSum = sum;
    // Slide
    for (int i = k; i < arr.size(); i++) {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// VARIABLE SIZE WINDOW (shrink when condition breaks)
int variableWindow(string& s) {
    unordered_map<char, int> freq;
    int l = 0, maxLen = 0;

    for (int r = 0; r < s.size(); r++) {
        freq[s[r]]++;

        // Shrink window when condition is violated
        while (/* condition violated */) {
            freq[s[l]]--;
            if (freq[s[l]] == 0) freq.erase(s[l]);
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

// PROBLEMS USING THIS:
// - LC 3. Longest Substring Without Repeating Characters (Variable)
// - LC 76. Minimum Window Substring (Variable + hash)
// - LC 239. Sliding Window Maximum (Fixed + deque)
// - LC 424. Longest Repeating Character Replacement (Variable)
// - LC 567. Permutation in String (Fixed + hash)
