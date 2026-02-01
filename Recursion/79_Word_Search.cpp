/*
79. Word Search
Link: https://leetcode.com/problems/word-search/

------------------------------------------------------
Problem Summary:
You are given an `m x n` grid of characters `board` and a string `word`.

The word can be constructed from letters of **sequentially adjacent cells**,
where adjacent cells are horizontally or vertically neighboring.
The same cell **may not be used more than once**.

Return `true` if the word exists in the grid, otherwise return `false`.

------------------------------------------------------
Example 1:
Input:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED"

Output:
true

------------------------------------------------------
Example 2:
Input:
word = "SEE"

Output:
true

------------------------------------------------------
Example 3:
Input:
word = "ABCB"

Output:
false

------------------------------------------------------
Brute Force Approach:
1. Start DFS from every cell.
2. Try to match the word character-by-character.
3. Track visited cells to avoid reuse.

- Time Complexity: O(m * n * 4^L)
  where L = length of the word
- Space Complexity: O(L) recursion stack

------------------------------------------------------
Optimal Approach (Backtracking / DFS on Grid):
Idea:
- Try to match the word starting from every cell.
- Use DFS with backtracking:
  - Match current character.
  - Mark cell as visited (temporarily).
  - Explore 4 directions.
  - Restore cell after recursion.

Key Points:
- Boundary checks are crucial.
- Early stopping if character mismatch occurs.
- Once all characters are matched → return true.

Steps:
1. Iterate through all cells in the grid.
2. For each cell, start backtracking.
3. If backtracking succeeds from any cell → word exists.

- Time Complexity: O(m * n * 4^L)
- Space Complexity: O(L)

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int n, m;

public:
    bool backtrack(int index, int row, int col, string word, vector<vector<char>> &board) {
        if (index == word.length()) return true;

        if (row < 0 || row >= n || col < 0 || col >= m) return false;
        if (board[row][col] != word[index]) return false;

        char ch = board[row][col];
        board[row][col] = '#'; // mark visited

        bool isPossible =
            backtrack(index + 1, row + 1, col, word, board) ||
            backtrack(index + 1, row - 1, col, word, board) ||
            backtrack(index + 1, row, col + 1, word, board) ||
            backtrack(index + 1, row, col - 1, word, board);

        board[row][col] = ch; // restore cell
        return isPossible;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (backtrack(0, i, j, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Usage:
Solution obj;
bool result = obj.exist(board, word);
*/
