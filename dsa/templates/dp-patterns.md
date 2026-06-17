# DP Patterns Cheatsheet

## How to identify a DP problem
1. **Optimal substructure** — optimal solution uses optimal solutions of subproblems
2. **Overlapping subproblems** — same subproblem solved multiple times
3. Question asks: "minimum/maximum", "count ways", "is it possible"

## Pattern 1: 1D DP (Linear)
**State:** `dp[i]` = answer considering first i elements
**Transition:** `dp[i] = f(dp[i-1], dp[i-2], ...)`

| Problem | State | Transition |
|---------|-------|------------|
| Climbing Stairs | dp[i] = ways to reach step i | dp[i] = dp[i-1] + dp[i-2] |
| House Robber | dp[i] = max money from first i houses | dp[i] = max(dp[i-1], dp[i-2] + nums[i]) |
| Coin Change | dp[i] = min coins for amount i | dp[i] = min(dp[i - coin] + 1) for each coin |
| Word Break | dp[i] = can we segment s[0..i-1] | dp[i] = dp[j] && s[j..i] in dict |
| Jump Game | dp[i] = can we reach index i | dp[i] = any dp[j] where j + nums[j] >= i |
| Decode Ways | dp[i] = ways to decode s[0..i-1] | dp[i] = dp[i-1] (if valid 1-digit) + dp[i-2] (if valid 2-digit) |

## Pattern 2: 2D DP (Grid / Two Sequences)
**State:** `dp[i][j]` = answer considering s1[0..i-1] and s2[0..j-1], or grid position (i,j)

| Problem | State | Transition |
|---------|-------|------------|
| Unique Paths | dp[i][j] = paths to (i,j) | dp[i][j] = dp[i-1][j] + dp[i][j-1] |
| LCS | dp[i][j] = LCS of s1[0..i-1], s2[0..j-1] | match: dp[i-1][j-1]+1, else: max(dp[i-1][j], dp[i][j-1]) |
| Edit Distance | dp[i][j] = min ops to convert s1[0..i-1] to s2[0..j-1] | match: dp[i-1][j-1], else: 1 + min(insert, delete, replace) |
| Min Path Sum | dp[i][j] = min sum path to (i,j) | dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]) |

## Pattern 3: 0/1 Knapsack
**State:** `dp[i][w]` = max value using first i items with capacity w
**Decision:** take item i or skip it

| Problem | Mapping |
|---------|---------|
| Partition Equal Subset Sum | items = nums, target = totalSum/2 |
| Target Sum | items = nums, find ways to reach target |
| Last Stone Weight II | minimize remaining = totalSum - 2*subset |
| Coin Change (unbounded) | items = coins, unlimited use |

## Pattern 4: LIS (Longest Increasing Subsequence)
**State:** `dp[i]` = length of LIS ending at index i
**Transition:** `dp[i] = max(dp[j] + 1)` for all j < i where nums[j] < nums[i]
**Optimization:** O(n log n) with binary search on patience sorting

## Pattern 5: Interval DP
**State:** `dp[i][j]` = answer for subarray/substring from index i to j
**Transition:** try all split points k between i and j

| Problem | Key Idea |
|---------|----------|
| Burst Balloons | dp[i][j] = max coins from bursting balloons i..j |
| Palindrome Partitioning II | dp[i][j] = is s[i..j] a palindrome |
| Matrix Chain Multiplication | dp[i][j] = min multiplications for matrices i..j |

## The DP Recipe (Interview)
1. **Define state** — what does dp[i] or dp[i][j] represent?
2. **Base case** — what's the simplest subproblem?
3. **Transition** — how does dp[i] relate to smaller subproblems?
4. **Answer** — where in the dp table is the final answer?
5. **Optimize** — can you reduce space? (2D → 1D, rolling array)
