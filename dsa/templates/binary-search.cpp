// =============================================
// BINARY SEARCH TEMPLATE
// Use when: sorted array, search space, min/max optimization
// =============================================

// STANDARD BINARY SEARCH (find exact target)
int binarySearch(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;  // avoid overflow
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// LOWER BOUND (first position where arr[i] >= target)
int lowerBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// BINARY SEARCH ON ANSWER (minimize/maximize something)
// Pattern: "find minimum X such that condition(X) is true"
int bsOnAnswer(vector<int>& arr, int target) {
    int lo = MIN_POSSIBLE, hi = MAX_POSSIBLE;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (condition(mid)) {
            ans = mid;       // mid works, try smaller
            hi = mid - 1;
        } else {
            lo = mid + 1;    // mid doesn't work, need bigger
        }
    }
    return ans;
}

// PROBLEMS USING THIS:
// - LC 704. Binary Search (Standard)
// - LC 33. Search in Rotated Sorted Array (Modified standard)
// - LC 153. Find Min in Rotated Sorted Array (Modified)
// - LC 875. Koko Eating Bananas (BS on Answer)
// - LC 1011. Capacity to Ship Packages (BS on Answer)
// - LC 4. Median of Two Sorted Arrays (BS on partition)
