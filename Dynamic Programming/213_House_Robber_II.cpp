/*
213. House Robber II
Link: https://leetcode.com/problems/house-robber-ii/

------------------------------------------------------
Problem Summary:
You are given an integer array `nums` where:
- nums[i] is the amount of money in the i-th house.
- Houses are arranged in a **circle** (first and last are adjacent).

Constraint:
You cannot rob any two adjacent houses.

Goal:
Return the **maximum money** you can rob without triggering alarms.

Key Difference from House Robber I:
- First and last houses are neighbors.
- Therefore, you cannot rob both together.

------------------------------------------------------
Examples:

Example 1:
Input:
nums = [2,3,2]

Output:
3

Explanation:
Rob house 2 only (can't rob both 2 and 2).

Example 2:
Input:
nums = [1,2,3,1]

Output:
4

Explanation:
Rob house 1 and 3 → 1 + 3 = 4

------------------------------------------------------
Brute Force Approach:
Try every subset of non-adjacent houses using recursion or bitmask.

- Time Complexity: O(2ⁿ)
- Space Complexity: O(n)

Not feasible.

------------------------------------------------------
Optimal Approach (Reduce to Two Linear Robber Problems):
Idea:
Since first and last houses cannot both be robbed, consider two scenarios:

Case 1: Exclude first house → rob from index 1 to n-1  
Case 2: Exclude last house → rob from index 0 to n-2  

Then take the maximum of results from both cases.

We solve each case using **House Robber I DP**.

House Robber I Transition:
- `curr = max(nums[i] + prevOfPrev, prev)`

Steps:
1. If n == 1 → return nums[0].
2. Form two arrays:
   - excludeFirst = nums[1…n-1]
   - excludeLast  = nums[0…n-2]
3. Run standard linear robber DP on both.
4. Return max of both results.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Standard House Robber I (linear street)
    int houseRobber(vector<int> &nums) {
        int n = nums.size();
        int prevOfPrev = 0, prev = nums[0], curr = 0;

        for (int i = 1; i < n; i++) {
            curr = max(nums[i] + prevOfPrev, prev);
            prevOfPrev = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> excludeFirst, excludeLast;

        for (int i = 0; i < n; i++) {
            if (i != 0)      excludeFirst.push_back(nums[i]);
            if (i != n - 1)  excludeLast.push_back(nums[i]);
        }

        return max(houseRobber(excludeFirst), houseRobber(excludeLast));
    }
};

/*
Usage:
Solution obj;
int result = obj.rob(nums);
*/
