/*
62. Unique Paths
Link: https://leetcode.com/problems/unique-paths/

------------------------------------------------------
Problem Summary:
A robot is located at the top-left corner of an m x n grid.

The robot can move only:
- Down
- Right

The robot is trying to reach the bottom-right corner of the grid.

Return the **number of possible unique paths** from start to finish.

------------------------------------------------------
Example:
Input:
m = 3, n = 7

Output:
28

Explanation:
There are 28 different ways to move from (0,0) to (2,6)
while only moving right or down.

------------------------------------------------------
Brute Force Approach (Recursion / Backtracking):
1. From each cell, try going right and down recursively.
2. Count paths that reach bottom-right.

- Time Complexity: O(2^(m+n))
- Space Complexity: O(m+n) recursion depth

This leads to exponential time and TLE.

------------------------------------------------------
Optimal Approach (Dynamic Programming — Space Optimized):
Idea:
- Number of ways to reach cell (i,j):
      ways(i,j) = ways(i-1,j) + ways(i,j-1)
- First row and first column each have exactly 1 way.

Optimization:
- Instead of full 2D DP table, use two 1D rows:
  previous row and current row.

Steps:
1. Maintain a 1D dp array for previous row.
2. Build each new row using:
   - up = dp[j]
   - left = currentRow[j-1]
3. Answer is last cell (bottom-right).

- Time Complexity: O(m*n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> prev(n, 0);

            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    prev[j] = 1;
                } else {
                    int up = 0, left = 0;
                    if (i > 0) up = dp[j];
                    if (j > 0) left = prev[j - 1];
                    prev[j] = up + left;
                }
            }
            dp = prev;
        }

        return dp[n - 1];
    }
};

/*
Usage:
Solution obj;
int result = obj.uniquePaths(m, n);
*/

