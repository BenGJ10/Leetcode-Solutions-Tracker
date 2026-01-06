/*
416. Partition Equal Subset Sum
Link: https://leetcode.com/problems/partition-equal-subset-sum/

------------------------------------------------------
Problem Summary:
You are given an integer array `nums`.

Your task is to determine whether the array can be partitioned into
two subsets such that the **sum of elements in both subsets is equal**.

Equivalently:
Check if there exists a subset whose sum is `totalSum / 2`.

------------------------------------------------------
Example 1:
Input:
nums = [1,5,11,5]

Output:
true

Explanation:
Subset A = [1,5,5]  → sum = 11  
Subset B = [11]    → sum = 11

------------------------------------------------------
Example 2:
Input:
nums = [1,2,3,5]

Output:
false

Explanation:
Total sum is odd, so partition is impossible.

------------------------------------------------------
Brute Force Approach:
Generate all subsets and check sums.

- Time Complexity: O(2ⁿ)
- Space Complexity: O(n)

Not feasible for constraints.

------------------------------------------------------
Optimal Approach (Subset Sum DP — Space Optimized):
Idea:
- Let `totalSum` be sum of all elements.
- If totalSum is odd → cannot split equally.
- We must check whether there exists a subset that sums to `target = totalSum / 2`.

Use Boolean DP:
- `dp[s] = true` means a subset with sum `s` exists.

Transition:
For each number `num`:
    for s from target down to num:
        dp[s] |= dp[s - num]

This avoids recomputation and uses O(target) memory.

Steps:
1. Compute total sum.
2. If sum is odd → return false.
3. Initialize dp[0] = true.
4. Update dp for each number.
5. Return dp[target].

- Time Complexity: O(n * target)
- Space Complexity: O(target)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums) totalSum += num;

        // If total sum is odd, partition impossible
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            vector<bool> prev = dp;

            for (int j = 1; j <= target; j++) {
                bool notPick = dp[j];
                bool pick = false;

                if (j >= nums[i]) 
                    pick = dp[j] || dp[j - nums[i]];

                prev[j] = notPick || pick;
            }

            dp = prev;
        }

        return dp[target];
    }
};

/*
Usage:
Solution obj;
bool result = obj.canPartition(nums);
*/
