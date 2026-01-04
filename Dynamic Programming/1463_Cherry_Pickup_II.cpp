/*
1463. Cherry Pickup II
Link: https://leetcode.com/problems/cherry-pickup-ii/

------------------------------------------------------
Problem Summary:
You are given an n x m grid where each cell contains some cherries.

Two robots start at:
- Robot 1: (0, 0)
- Robot 2: (0, m − 1)

Both robots move simultaneously from row 0 to row n−1.
In each step, a robot may move:
- down-left  (row+1, col−1)
- down       (row+1, col)
- down-right (row+1, col+1)

Rules:
- If both robots land on the same cell, cherries are counted only once.
- Otherwise, add cherries from both cells.

Goal:
Return the **maximum total cherries** both robots can collect.

------------------------------------------------------
Example:
Input:
grid =
[
  [3,1,1],
  [2,5,1],
  [1,5,5],
  [2,1,1]
]

Output:
24

Explanation:
Best collection path yields 24 cherries total.

------------------------------------------------------
Brute Force Approach:
Try all paths for both robots using recursion.

- Each robot has 3 choices per row
- Total states ≈ 3^(2n)

- Time Complexity: Exponential
- Space Complexity: O(n)

Not feasible.

------------------------------------------------------
Optimal Approach (3D Dynamic Programming — Bottom-Up):
State Definition:
dp[row][c1][c2] =
maximum cherries collectable from row..end when:
- robot1 is at column c1
- robot2 is at column c2

Transition:
From (row, c1, c2), both robots move to next row with offsets −1, 0, +1.

Cherry Collection:
- If c1 == c2: count once
- Else: add cherries from both positions

Base Case:
Last row values are directly the cherries in grid.

Recurrence:
dp[i][j1][j2] =
  max over all next moves:
    value(i,j1,j2) + dp[i+1][nj1][nj2]

Answer:
dp[0][0][m−1]

- Time Complexity: O(n * m² * 9)
- Space Complexity: O(n * m²)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j1][j2] = max cherries from row i to bottom with robots at j1 and j2
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        // Base Case: last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // Fill DP bottom-up
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    int maximum = 0;

                    // Robot movement combinations
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {

                            int value = 0;

                            // cherries at current row
                            if (j1 == j2) value += grid[i][j1];
                            else value += grid[i][j1] + grid[i][j2];

                            // check boundaries for next step
                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                value += dp[i + 1][nj1][nj2];
                            }

                            maximum = max(maximum, value);
                        }
                    }

                    dp[i][j1][j2] = maximum;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};

/*
Usage:
Solution obj;
int result = obj.cherryPickup(grid);
*/
