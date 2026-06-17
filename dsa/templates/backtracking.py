# =============================================
# BACKTRACKING TEMPLATE
# Use when: generate all combinations/permutations/subsets, constraint satisfaction
# =============================================

# --- SUBSETS ---
def subsets(nums):
    result = []

    def backtrack(start, current):
        result.append(current[:])  # add copy of current subset

        for i in range(start, len(nums)):
            # Skip duplicates (if nums is sorted and has duplicates):
            # if i > start and nums[i] == nums[i-1]: continue

            current.append(nums[i])        # 1. Choose
            backtrack(i + 1, current)       # 2. Explore (i+1 = don't reuse)
            current.pop()                   # 3. Un-choose

    backtrack(0, [])
    return result


# --- PERMUTATIONS ---
def permutations(nums):
    result = []

    def backtrack(current, used):
        if len(current) == len(nums):
            result.append(current[:])
            return

        for i in range(len(nums)):
            if used[i]:
                continue
            # Skip duplicates: if i > 0 and nums[i] == nums[i-1] and not used[i-1]: continue

            used[i] = True
            current.append(nums[i])
            backtrack(current, used)
            current.pop()
            used[i] = False

    backtrack([], [False] * len(nums))
    return result


# --- COMBINATION SUM (with reuse) ---
def combination_sum(candidates, target):
    result = []

    def backtrack(start, current, remaining):
        if remaining == 0:
            result.append(current[:])
            return
        if remaining < 0:
            return

        for i in range(start, len(candidates)):
            current.append(candidates[i])
            backtrack(i, current, remaining - candidates[i])  # i = CAN reuse
            current.pop()

    backtrack(0, [], target)
    return result


# PROBLEMS USING THIS:
# - LC 78. Subsets
# - LC 90. Subsets II (with duplicates skip)
# - LC 46. Permutations
# - LC 47. Permutations II (with duplicates skip)
# - LC 39. Combination Sum (reuse allowed)
# - LC 40. Combination Sum II (no reuse + duplicates skip)
# - LC 51. N-Queens
# - LC 37. Sudoku Solver
# - LC 79. Word Search (grid backtracking)
# - LC 131. Palindrome Partitioning
