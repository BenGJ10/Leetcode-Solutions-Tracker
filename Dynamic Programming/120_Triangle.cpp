/*
120. Triangle
Link: https://leetcode.com/problems/triangle/

------------------------------------------------------
Problem Summary:
You are given a triangular array `triangle` where:

triangle[i][j] is the value at row i and column j,
with:
- 0 ≤ j ≤ i
- Total rows = n

You start at the **top element** (triangle[0][0]) and may move to:
- directly below (i+1, j)
- down-right diagonal (i+1, j+1)

Your task is to find the **minimum path sum** from top to bottom.

------------------------------------------------------
Example:
Input:
[
  [2],
  [3,4],
  [6,5,7],
  [4,1,8,3]
]

Output:
11

Explanation:
Minimum path:
2 → 3 → 5 → 1 = 11

------------------------------------------------------
Brute Force Approach (Recursive DFS):
1. From every element, try both valid downward moves.
2. Track sum along each path.
3. Return minimum.

- Time Complexity: O(2ⁿ)
- Space Complexity: O(n)

Leads to exponential blowup.

------------------------------------------------------
Optimal Approach (Bottom-Up Dynamic Programming — Space Optimized):
Idea:
- Start from the **second last row** and move upward.
- Each cell takes:
      value + min(below, below-right)
- Last row acts as base case.

We maintain a single 1D dp array representing best sums from the row below.

Steps:
1. Initialize dp as the last row of triangle.
2. Iterate rows from n−2 down to 0:
   - For each position j in that row:
        dp[j] = triangle[i][j] + min(dp[j], dp[j+1])
3. Answer is dp[0].

- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // dp holds minimum path sums from current row to bottom
        vector<int> dp(n, 0);

        // Initialize dp with last row
        for (int j = 0; j < n; j++) {
            dp[j] = triangle[n - 1][j];
        }

        // Process from second last row up to top
        for (int i = n - 2; i >= 0; i--) {
            vector<int> prev(n, 0);

            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + dp[j];
                int diagonal = triangle[i][j] + dp[j + 1];
                prev[j] = min(down, diagonal);
            }

            dp = prev;
        }

        return dp[0];
    }
};

/*
Usage:
Solution obj;
int result = obj.minimumTotal(triangle);
*/
