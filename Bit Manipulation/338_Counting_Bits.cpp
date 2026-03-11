/*
338. Counting Bits
Link: https://leetcode.com/problems/counting-bits/

------------------------------------------------------
Problem Summary:
Given an integer `n`, return an array `ans` of length `n + 1`
where:

ans[i] = number of 1's in the binary representation of `i`.

------------------------------------------------------
Example 1:
Input:
n = 2

Output:
[0,1,1]

Explanation:
0 → 0 → 0 ones
1 → 1 → 1 one
2 → 10 → 1 one

------------------------------------------------------
Example 2:
Input:
n = 5

Output:
[0,1,1,2,1,2]

Explanation:
0  → 0    → 0
1  → 1    → 1
2  → 10   → 1
3  → 11   → 2
4  → 100  → 1
5  → 101  → 2

------------------------------------------------------
Brute Force Approach:
For every number `i` from 0 → n:

1. Convert number to binary.
2. Count the number of set bits.

Method:
Repeatedly check `(n & 1)` and shift right.

Time Complexity:
- For each number we process up to log₂(n) bits
- Total = O(n log n)

Space Complexity:
- O(1) extra (excluding output)

------------------------------------------------------
Optimal Approach (Dynamic Programming / Bit Manipulation):

Observation:
For any number `i`:

i >> 1 removes the last bit.

Example:
5  = 101
5 >> 1 = 10 = 2

So:

countBits(i) = countBits(i >> 1) + (i & 1)

Explanation:
- `(i & 1)` tells whether the last bit is 1.
- `i >> 1` already has its bit count computed.

Thus we reuse previous results.

------------------------------------------------------
DP Relation:

dp[i] = dp[i >> 1] + (i & 1)

Base Case:
dp[0] = 0

------------------------------------------------------
Steps:
1. Create dp array of size n + 1.
2. Initialize dp[0] = 0.
3. For each number i from 1 → n:
       dp[i] = dp[i >> 1] + (i & 1)
4. Return dp.

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(n)

Space Complexity:
O(n)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};

/*
Usage:
Solution obj;
vector<int> result = obj.countBits(n);
*/