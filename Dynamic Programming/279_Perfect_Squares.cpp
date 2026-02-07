/*
279. Perfect Squares
Link: https://leetcode.com/problems/perfect-squares/

------------------------------------------------------
Problem Summary:
Given an integer `n`, return the **least number of perfect square numbers**
(e.g., 1, 4, 9, 16, ...) that sum to `n`.

You may use each perfect square **multiple times**.

------------------------------------------------------
Example 1:
Input:
n = 12

Output:
3

Explanation:
12 = 4 + 4 + 4

------------------------------------------------------
Example 2:
Input:
n = 13

Output:
2

Explanation:
13 = 4 + 9

------------------------------------------------------
Brute Force Approach:
Try every combination of perfect squares recursively.

- Time Complexity: Exponential
- Space Complexity: O(n)

Too slow due to repeated states.

------------------------------------------------------
Optimal Approach (Dynamic Programming — Unbounded Knapsack):
Idea:
This is equivalent to an **unbounded knapsack** problem where:
- Items = perfect squares ≤ n
- Goal = minimize number of items used to reach sum n

Define:
dp[i][t] = minimum count of squares using first `i` squares to make sum `t`.

Transition:
- Not pick square:
      dp[i-1][t]
- Pick square (stay on same index because unlimited):
      1 + dp[i][t - square]

Take the minimum.

Base Case:
For the smallest square (1):
- If t % 1 == 0 → t
- Otherwise impossible (INF)

Return dp[last][n].

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n * sqrt(n))
- Space Complexity: O(n * sqrt(n))

------------------------------------------------------
*/

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int numSquares(int n) {
        if (n == 1) return 1;

        vector<int> nums;

        // Generate all perfect squares <= n
        for (int i = 1; i * i <= n; i++) {
            nums.push_back(i * i);
        }

        dp.assign(nums.size(), vector<int>(n + 1, 0));

        // Base case
        for (int t = 1; t <= n; t++) {
            if (t % nums[0] == 0)
                dp[0][t] = t / nums[0];
            else
                dp[0][t] = 1e9;
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int t = 1; t <= n; t++) {

                int noPick = dp[i - 1][t];

                int pick = INT_MAX;
                if (nums[i] <= t)
                    pick = 1 + dp[i][t - nums[i]];

                dp[i][t] = min(pick, noPick);
            }
        }

        return dp[nums.size() - 1][n];
    }
};

/*
Usage:
Solution obj;
int result = obj.numSquares(n);
*/

