// =============================================
// BACKTRACKING TEMPLATE
// Use when: generate all combinations/permutations/subsets, constraint satisfaction
// =============================================

// --- GENERIC BACKTRACKING TEMPLATE ---
// 1. Make a choice
// 2. Recurse
// 3. Undo the choice (backtrack)

void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, int start) {
    // Base case: add valid result
    result.push_back(current);

    for (int i = start; i < nums.size(); i++) {
        // Skip duplicates (if nums is sorted and has duplicates)
        // if (i > start && nums[i] == nums[i-1]) continue;

        current.push_back(nums[i]);       // 1. Choose
        backtrack(nums, current, result, i + 1);  // 2. Explore (i+1 for subsets, i for reuse)
        current.pop_back();                // 3. Un-choose
    }
}

// --- SUBSETS ---
// start = i + 1 (don't reuse elements)
// Add to result at every call (every subset is valid)

// --- PERMUTATIONS ---
// No start index. Use visited[] array instead.
// Add to result only when current.size() == nums.size()

void permute(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, vector<bool>& used) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        // Skip duplicates: if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        used[i] = true;
        current.push_back(nums[i]);
        permute(nums, current, result, used);
        current.pop_back();
        used[i] = false;
    }
}

// --- COMBINATION SUM (with reuse) ---
// start = i (CAN reuse same element)
// Add to result when target == 0

// PROBLEMS USING THIS:
// - LC 78. Subsets
// - LC 90. Subsets II (with duplicates skip)
// - LC 46. Permutations
// - LC 47. Permutations II (with duplicates skip)
// - LC 39. Combination Sum (reuse allowed)
// - LC 40. Combination Sum II (no reuse + duplicates skip)
// - LC 51. N-Queens
// - LC 37. Sudoku Solver
// - LC 79. Word Search (grid backtracking)
// - LC 131. Palindrome Partitioning
