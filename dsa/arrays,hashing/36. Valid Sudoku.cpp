/*
LC 36 — Valid Sudoku
Pattern: Hash Set / Bitmasking
Difficulty: Medium
Approach: Use three sets of hash sets (or arrays) to track numbers seen so far 
          in each row, each column, and each 3x3 box. 
          The box index can be calculated as (r/3) * 3 + (c/3).
          If a number is already in the corresponding row, column, or box set, return false.
Time Complexity: O(1) - since the board size is fixed at 81 cells.
Space Complexity: O(1) - since we store a fixed amount of data.
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use arrays to track counts for rows, columns, and 9 boxes
        // board[r][c] is '1'-'9', so index 1-9
        int rowCheck[9][10] = {0};
        int colCheck[9][10] = {0};
        int boxCheck[9][10] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                int num = board[r][c] - '0';
                int boxIdx = (r / 3) * 3 + (c / 3);

                // If number already exists in current row, col, or 3x3 box
                if (rowCheck[r][num] || colCheck[c][num] || boxCheck[boxIdx][num]) {
                    return false;
                }

                // Mark number as seen
                rowCheck[r][num] = 1;
                colCheck[c][num] = 1;
                boxCheck[boxIdx][num] = 1;
            }
        }
        return true;
    }
};