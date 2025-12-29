/*
64. Minimum Path Sum
Link: https://leetcode.com/problems/minimum-path-sum/

------------------------------------------------------
Problem Summary:
You are given an m x n grid filled with non-negative integers.

A path starts at the **top-left cell** and ends at the **bottom-right cell**.
You may move only:
- Right
- Down

Your task is to return the **minimum path sum** of all such paths.

------------------------------------------------------
Example:
Input:
grid =
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]

Output:
7

Explanation:
Path: 1 → 3 → 1 → 1 → 1  
Path sum = 7 (minimum possible)

------------------------------------------------------
Brute Force Approach (Recursion / DFS):
1. From each cell, move either right or down recursively.
2. Add grid values along the path.
3. Track the minimum sum.

- Time Complexity: O(2^(m+n))
- Space Complexity: O(m+n)

Too slow for constraints.

------------------------------------------------------
Optimal Approach (Dynamic Programming):
Idea:
- To reach cell (i, j), you could come from:
    - top  (i−1, j)
    - left (i, j−1)
- Minimum path sum recurrence:
      dp[i][j] = grid[i][j] + min(dp[i−1][j], dp[i][j−1])

Base case:
- Start cell (0,0) takes its own value.
- First row can only come from the left.
- First column can only come from above.

Steps:
1. Create dp table same size as grid.
2. Fill dp using transitions above.
3. Answer is dp[n−1][m−1].

- Time Complexity: O(m*n)
- Space Complexity: O(m*n)
  (can be optimized to O(n) if desired)

------------------------------------------------------
*/

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    int up = INT_MAX, left = INT_MAX;

                    if (i > 0) up = grid[i][j] + dp[i - 1][j];
                    if (j > 0) left = grid[i][j] + dp[i][j - 1];

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};

/*
Usage:
Solution obj;
int result = obj.minPathSum(grid);
*/
