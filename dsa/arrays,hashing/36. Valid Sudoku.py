"""
LC 36 — Valid Sudoku
Pattern: Hash Set / One-Pass
Difficulty: Medium
Approach: Use three collections of sets to track numbers in each row, 
          column, and 3x3 box. For boxes, the coordinate (r//3, c//3) 
          uniquely identifies one of the nine boxes.
          Iterate through every cell exactly once.
Time Complexity: O(1)
Space Complexity: O(1)
"""
from typing import List
from collections import defaultdict

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(set)
        cols = defaultdict(set)
        boxes = defaultdict(set)

        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == ".":
                    continue
                
                # Formula to identify which 3x3 box we are in
                box_idx = (r // 3, c // 3)

                if (val in rows[r] or 
                    val in cols[c] or 
                    val in boxes[box_idx]):
                    return False
                
                rows[r].add(val)
                cols[c].add(val)
                boxes[box_idx].add(val)

        return True