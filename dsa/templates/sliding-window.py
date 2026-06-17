# =============================================
# SLIDING WINDOW TEMPLATE
# Use when: find max/min subarray, substring with condition
# =============================================

# FIXED SIZE WINDOW
def fixed_window(arr, k):
    window_sum = sum(arr[:k])
    max_sum = window_sum

    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)

    return max_sum


# VARIABLE SIZE WINDOW (shrink when condition breaks)
def variable_window(s):
    freq = {}
    l = 0
    max_len = 0

    for r in range(len(s)):
        freq[s[r]] = freq.get(s[r], 0) + 1

        # Shrink window when condition is violated
        while False:  # <-- replace with your condition
            freq[s[l]] -= 1
            if freq[s[l]] == 0:
                del freq[s[l]]
            l += 1

        max_len = max(max_len, r - l + 1)

    return max_len


# PROBLEMS USING THIS:
# - LC 3. Longest Substring Without Repeating Characters (Variable)
# - LC 76. Minimum Window Substring (Variable + hash)
# - LC 239. Sliding Window Maximum (Fixed + deque)
# - LC 424. Longest Repeating Character Replacement (Variable)
# - LC 567. Permutation in String (Fixed + hash)
