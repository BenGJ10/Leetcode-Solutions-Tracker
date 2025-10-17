/*
70. Climbing Stairs  
Link: https://leetcode.com/problems/climbing-stairs/

------------------------------------------------------
Problem Summary:
You are climbing a staircase with `n` steps.  
You can climb either **1 step** or **2 steps** at a time.  
Return the total number of distinct ways to reach the top.

------------------------------------------------------
Approach 1: Recursive + Memoization (Top-Down DP)
------------------------------------------------------
Idea:
- The total ways to reach the `n`th step is the sum of:
  → ways to reach (n-1) + ways to reach (n-2)
- We use memoization to store results of subproblems to avoid recomputation.

Recurrence:
    f(n) = f(n-1) + f(n-2)
Base cases:
    f(0) = 1
    f(1) = 1

------------------------------------------------------
Algorithm:
1. If n == 0 or n == 1 → return 1.
2. If already computed, return dp[n].
3. Otherwise, compute dp[n] = f(n-1) + f(n-2).
4. Return dp[n].

------------------------------------------------------
Approach 2: Iterative DP (Bottom-Up)
------------------------------------------------------
Idea:
- Build the dp array iteratively using previous results.
- dp[i] = dp[i-1] + dp[i-2]

Base Cases:
- dp[0] = 1 (1 way to stay on ground)
- dp[1] = 1 (1 way to take one step)

------------------------------------------------------
Complexity:
Recursive + Memoization: 
- Time: O(n)
- Space: O(n) (for recursion stack + memo)

Iterative DP:
- Time: O(n)
- Space: O(n)
(Can be optimized to O(1) using 2 variables.)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    // ---------- Approach 1: Top-Down (Memoization) ----------
    int climbStairsMemo(int n, vector<int>& dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
    }

    // ---------- Approach 2: Bottom-Up (Tabulation) ----------
    int climbStairsTab(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

/*
Usage:
Solution sol;
int ways = sol.climbStairs(5); // Output: 8
*/
