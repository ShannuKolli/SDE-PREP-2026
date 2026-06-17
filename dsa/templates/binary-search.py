# =============================================
# BINARY SEARCH TEMPLATE
# Use when: sorted array, search space, min/max optimization
# =============================================

# STANDARD BINARY SEARCH (find exact target)
def binary_search(arr, target):
    lo, hi = 0, len(arr) - 1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1


# LOWER BOUND (first position where arr[i] >= target)
# Python shortcut: bisect.bisect_left(arr, target)
def lower_bound(arr, target):
    lo, hi = 0, len(arr)
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if arr[mid] < target:
            lo = mid + 1
        else:
            hi = mid
    return lo


# BINARY SEARCH ON ANSWER
# Pattern: "find minimum X such that condition(X) is true"
def bs_on_answer(condition, lo, hi):
    ans = -1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if condition(mid):
            ans = mid       # mid works, try smaller
            hi = mid - 1
        else:
            lo = mid + 1    # mid doesn't work, need bigger
    return ans


# PROBLEMS USING THIS:
# - LC 704. Binary Search (Standard)
# - LC 33. Search in Rotated Sorted Array (Modified standard)
# - LC 153. Find Min in Rotated Sorted Array (Modified)
# - LC 875. Koko Eating Bananas (BS on Answer)
# - LC 1011. Capacity to Ship Packages (BS on Answer)
# - LC 4. Median of Two Sorted Arrays (BS on partition)
