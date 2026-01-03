/*
931. Minimum Falling Path Sum
Link: https://leetcode.com/problems/minimum-falling-path-sum/

------------------------------------------------------
Problem Summary:
You are given an `n x n` integer matrix.

A **falling path** starts at any element in the first row, and chooses one element
from each row such that the next element is:

- directly below (i+1, j)
- down-left diagonal (i+1, j−1)
- down-right diagonal (i+1, j+1)

Your task is to find the **minimum possible sum** among all falling paths.

------------------------------------------------------
Example:
Input:
[
  [2,1,3],
  [6,5,4],
  [7,8,9]
]

Output:
13

Explanation:
Path: 1 → 5 → 7 → sum = 13 (minimum)

------------------------------------------------------
Brute Force Approach (Recursion/DFS on all paths):
1. From each element in first row, try all valid downward moves.
2. Track path sums.
3. Return minimum.

- Time Complexity: O(3ⁿ)
- Space Complexity: O(n)

Too slow for constraints.

------------------------------------------------------
Optimal Approach (Dynamic Programming — Space Optimized):
Idea:
Let dp[i][j] = minimum sum to reach cell (i, j) from row 0.

Transition:
    dp[i][j] = matrix[i][j] +
               min( dp[i-1][j],
                    dp[i-1][j-1],
                    dp[i-1][j+1])

We optimize to 1D because each row depends only on the previous row.

Steps:
1. Initialize dp with first row values.
2. For each subsequent row:
   - Compute new row from previous dp values.
3. Answer = minimum value in last dp row.

- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n);

        // Initialize dp for first row
        for (int j = 0; j < n; j++) {
            dp[j] = matrix[0][j];
        }

        // Process subsequent rows
        for (int i = 1; i < n; i++) {
            vector<int> prev(n);

            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[j];

                int leftDiag = INT_MAX, rightDiag = INT_MAX;
                if (j - 1 >= 0) leftDiag = matrix[i][j] + dp[j - 1];
                if (j + 1 < n)  rightDiag = matrix[i][j] + dp[j + 1];

                prev[j] = min(up, min(leftDiag, rightDiag));
            }

            dp = prev;
        }

        // Minimum in last row
        int minPathSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minPathSum = min(minPathSum, dp[j]);
        }

        return minPathSum;
    }
};

/*
Usage:
Solution obj;
int result = obj.minFallingPathSum(matrix);
*/
