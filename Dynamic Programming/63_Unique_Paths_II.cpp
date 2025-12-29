/*
63. Unique Paths II
Link: https://leetcode.com/problems/unique-paths-ii/

------------------------------------------------------
Problem Summary:
You are given an m x n grid `obstacleGrid` where:
- `0` represents an empty cell
- `1` represents an obstacle

A robot starts at the **top-left corner** and wants to reach the **bottom-right corner**.
It can move only:
- Right
- Down

Return the **number of unique paths** from start to finish such that the robot
does not step on any obstacles.

If the start or end cell is blocked, the answer is 0.

------------------------------------------------------
Example:
Input:
obstacleGrid =
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

Output:
2

Explanation:
Two valid paths:
1. Right → Right → Down → Down  
2. Down → Down → Right → Right  

------------------------------------------------------
Brute Force Approach (Recursion / Backtracking):
1. From each cell, recursively move right or down.
2. Stop when hitting borders or obstacles.
3. Count paths reaching bottom-right.

- Time Complexity: O(2^(m+n))
- Space Complexity: O(m+n)

Will TLE due to exponential branching.

------------------------------------------------------
Optimal Approach (Dynamic Programming — Space Optimized):
Idea:
Same recurrence as Unique Paths, but:
- If a cell has an obstacle → paths = 0
- Otherwise:
      paths(i,j) = paths(i-1,j) + paths(i,j-1)

Optimization:
Use two 1D arrays (previous and current row).

Steps:
1. Initialize 1D dp of size n.
2. Iterate each cell:
   - If obstacle → 0 paths.
   - If start cell → 1 path.
   - Otherwise compute from top and left values.
3. Answer is bottom-right dp cell.

- Time Complexity: O(m*n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<int> dp(m);

        for (int i = 0; i < n; i++) {
            vector<int> prev(m);

            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    prev[j] = 0; // obstacle blocks path
                } else if (i == 0 && j == 0) {
                    prev[j] = 1; // start cell
                } else {
                    int top = 0, left = 0;
                    if (i > 0) top = dp[j];
                    if (j > 0) left = prev[j - 1];
                    prev[j] = top + left;
                }
            }

            dp = prev;
        }

        return dp[m - 1];
    }
};

/*
Usage:
Solution obj;
int result = obj.uniquePathsWithObstacles(obstacleGrid);
*/
