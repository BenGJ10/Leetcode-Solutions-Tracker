/*
1458. Max Dot Product of Two Subsequences
Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/

------------------------------------------------------
Problem Summary:
You are given two integer arrays `nums1` and `nums2`.

You must choose **non-empty subsequences** from both arrays (not necessarily contiguous),
such that the **dot product** of the two subsequences is maximized.

Dot Product:
If A = [a1, a2, ..., ak] and B = [b1, b2, ..., bk],
dot(A, B) = a1*b1 + a2*b2 + ... + ak*bk

------------------------------------------------------
Example 1:
Input:
nums1 = [2,1,-2,5]
nums2 = [3,0,-6]

Output:
18

Explanation:
Choose subsequences [2,5] and [3,-6]
Dot product = 2*3 + 5*(-6) = 6 - 30 = -24 ❌  
Better choice: [2,-2] and [3,-6] → 6 + 12 = 18 ✅

------------------------------------------------------
Key Challenge:
- Subsequence must be **non-empty**
- Arrays can contain **negative numbers**
- We cannot default to 0 (empty subsequence is invalid)

------------------------------------------------------
Brute Force Approach:
1. Generate all subsequences of nums1 and nums2.
2. Compute dot product for pairs of equal length.
3. Track maximum.

- Time Complexity: Exponential (2ⁿ × 2ᵐ)
- Space Complexity: Large

Not feasible.

------------------------------------------------------
Optimal Approach (Dynamic Programming – 2D DP):
Idea:
Let:
dp[i][j] = maximum dot product using:
- first `i` elements of nums1
- first `j` elements of nums2
- **with at least one pair selected**

Transitions:
At (i, j), we have 4 choices:

1. Start a new subsequence with nums1[i-1] * nums2[j-1]
2. Extend previous subsequence:
      dp[i-1][j-1] + nums1[i-1] * nums2[j-1]
3. Skip nums1[i-1]:
      dp[i-1][j]
4. Skip nums2[j-1]:
      dp[i][j-1]

We take the maximum of all.

Initialization:
- Initialize dp with a very small negative value (−INF)
- This prevents empty subsequences from being chosen

Answer:
dp[n][m]

- Time Complexity: O(n * m)
- Space Complexity: O(n * m)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int INF = 1e7;
        int n = nums1.size(), m = nums2.size();

        // dp[i][j] = max dot product using first i of nums1 and first j of nums2
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max({
                    nums1[i - 1] * nums2[j - 1],                      // start new subsequence
                    dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1],   // extend subsequence
                    dp[i - 1][j],                                    // skip nums1[i-1]
                    dp[i][j - 1]                                     // skip nums2[j-1]
                });
            }
        }

        return dp[n][m];
    }
};

/*
Usage:
Solution obj;
int result = obj.maxDotProduct(nums1, nums2);
*/
