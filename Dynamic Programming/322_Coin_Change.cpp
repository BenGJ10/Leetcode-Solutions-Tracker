/*
322. Coin Change
Link: https://leetcode.com/problems/coin-change/

------------------------------------------------------
Problem Summary:
You are given:
- An array `coins` representing different coin denominations.
- An integer `amount` representing the total money.

Return the **minimum number of coins** required to make up that amount.
If it is not possible, return `-1`.

You may use each coin **unlimited times**.

------------------------------------------------------
Example 1:
Input:
coins = [1,2,5], amount = 11

Output:
3

Explanation:
11 = 5 + 5 + 1 → minimum coins = 3

------------------------------------------------------
Example 2:
Input:
coins = [2], amount = 3

Output:
-1

Explanation:
Cannot form 3 using coin 2.

------------------------------------------------------
Brute Force Approach:
Try every combination of coins recursively.

- Time Complexity: Exponential
- Space Complexity: O(amount)

Leads to TLE.

------------------------------------------------------
Optimal Approach (Dynamic Programming — Unbounded Knapsack):
Idea:
This is a classic **unbounded knapsack** problem because:
- Each coin can be reused infinitely.

Define:
dp[i][t] = minimum coins needed using first `i` coins to make target `t`.

Transition:
- Not pick coin:
      dp[i-1][t]
- Pick coin (stay on same index since unlimited):
      1 + dp[i][t - coins[i]]

Take minimum of both.

Base Case:
For coin[0]:
- If t % coins[0] == 0 → t / coins[0]
- Else → INF (impossible)

Return -1 if result is still INF.

- Time Complexity: O(n * amount)
- Space Complexity: O(n * amount)

------------------------------------------------------
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    // Memoization (Top-Down)
    int reqCoins(int index, int target, vector<int> &coins) {
        if (index == 0) {
            if (target % coins[index] == 0)
                return target / coins[index];
            else
                return 1e9;
        }

        if (dp[index][target] != -1)
            return dp[index][target];

        int noPick = reqCoins(index - 1, target, coins);

        int pick = INT_MAX;
        if (coins[index] <= target) {
            pick = 1 + reqCoins(index, target - coins[index], coins);
        }

        return dp[index][target] = min(noPick, pick);
    }

    // Tabulation (Bottom-Up)
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        dp.assign(n, vector<int>(target + 1, 0));

        // Base case
        for (int t = 0; t <= target; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = t / coins[0];
            else
                dp[0][t] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= target; t++) {
                int noPick = dp[i - 1][t];

                int pick = INT_MAX;
                if (coins[i] <= t)
                    pick = 1 + dp[i][t - coins[i]];

                dp[i][t] = min(pick, noPick);
            }
        }

        return dp[n - 1][target] == 1e9 ? -1 : dp[n - 1][target];
    }
};

/*
Usage:
Solution obj;
int result = obj.coinChange(coins, amount);
*/
