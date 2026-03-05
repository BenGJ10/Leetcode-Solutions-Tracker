/*
343. Integer Break
Link: https://leetcode.com/problems/integer-break/

------------------------------------------------------
Problem Summary:
Given an integer `n`, break it into the sum of at least
two positive integers and maximize the product of those integers.

Return the maximum product you can get.

------------------------------------------------------
Example 1:
Input:
n = 2

Output:
1

Explanation:
2 = 1 + 1 → 1 * 1 = 1

------------------------------------------------------
Example 2:
Input:
n = 10

Output:
36

Explanation:
10 = 3 + 3 + 4 → 3 * 3 * 4 = 36

------------------------------------------------------
Brute Force Approach:
Try all possible splits of the integer:
    n = i + (n - i)

For each split, recursively compute the maximum
product of the two parts.

This leads to exponential recursion.

Time Complexity: O(2^n)

------------------------------------------------------
Optimal Approach (DP + Memoization):
Idea:
For each number `num`, compute the maximum product
we can obtain by splitting it.

Two possibilities for each split:
1️⃣ Do not split further → i * (num - i)
2️⃣ Split further → dp[i] * dp[num - i]

We recursively compute results and memoize them.

Important trick:
For the original number `n`, we must split it,
so the base result is initialized accordingly.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int backtrack(int num, int input) {

        if (dp[num] != -1)
            return dp[num];

        int result = (num == input) ? 0 : num;

        for (int i = 1; i < num; i++) {

            int prod = backtrack(i, input) *
                       backtrack(num - i, input);

            result = max(result, prod);
        }

        return dp[num] = result;
    }

    int integerBreak(int n) {

        dp.assign(n + 1, -1);

        dp[1] = 1;

        return backtrack(n, n);
    }
};

/*
Usage:
Solution obj;
int result = obj.integerBreak(n);
*/