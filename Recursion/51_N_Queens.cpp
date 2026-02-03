/*
51. N-Queens
Link: https://leetcode.com/problems/n-queens/

------------------------------------------------------
Problem Summary:
The **N-Queens problem** asks you to place `n` queens on an `n x n` chessboard
such that **no two queens attack each other**.

A queen can attack:
- Horizontally
- Vertically
- Diagonally (both left and right)

Return **all distinct solutions**, where each solution is represented as
a list of strings:
- `'Q'` represents a queen
- `'.'` represents an empty cell

------------------------------------------------------
Example:
Input:
n = 4

Output:
[
 [".Q..",
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",
  "Q...",
  "...Q",
  ".Q.."]
]

------------------------------------------------------
Brute Force Approach:
1. Try placing queens in all possible cells.
2. Check every configuration for validity.

- Total configurations: (n² choose n)
- Validity check per configuration: O(n²)

- Time Complexity: Exponential (very large)
- Space Complexity: O(n²)

Not feasible.

------------------------------------------------------
Optimal Approach (Backtracking + Safety Check):
Idea:
- Place **one queen per row**.
- At each row, try all columns.
- Before placing a queen, check if it is safe:
  - No queen in same column above
  - No queen in upper-left diagonal
  - No queen in upper-right diagonal

If safe:
- Place queen
- Move to next row
- Backtrack after exploring

This prunes invalid branches early.

Steps:
1. Start from row 0.
2. For each column in the row:
   - Check if queen can be placed.
   - Place queen and recurse to next row.
3. If row == n → valid configuration found.
4. Backtrack to explore other possibilities.

- Time Complexity: O(n!)
- Space Complexity: O(n²) for board + recursion stack

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ways;

    bool canPlaceQueen(int row, int col, vector<string> &board) {
        int tempRow, tempCol;

        // Check upper-left diagonal
        tempRow = row; tempCol = col;
        while (tempRow >= 0 && tempCol >= 0) {
            if (board[tempRow][tempCol] == 'Q') return false;
            tempRow--; tempCol--;
        }

        // Check upper-right diagonal
        tempRow = row; tempCol = col;
        while (tempRow >= 0 && tempCol < board.size()) {
            if (board[tempRow][tempCol] == 'Q') return false;
            tempRow--; tempCol++;
        }

        // Check column above
        tempRow = row;
        while (tempRow >= 0) {
            if (board[tempRow][col] == 'Q') return false;
            tempRow--;
        }

        return true;
    }

    void backtrack(int row, int n, vector<string> &board) {
        if (row == n) {
            ways.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (canPlaceQueen(row, col, board)) {
                board[row][col] = 'Q';
                backtrack(row + 1, n, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return ways;
    }
};

/*
Usage:
Solution obj;
vector<vector<string>> result = obj.solveNQueens(n);
*/
