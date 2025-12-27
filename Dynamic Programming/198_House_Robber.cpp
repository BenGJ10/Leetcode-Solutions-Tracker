/*
198. House Robber
Link: https://leetcode.com/problems/house-robber/

------------------------------------------------------
Problem Summary:
You are given an integer array `nums` where:
- nums[i] represents the amount of money in the i-th house.

Constraint:
You cannot rob two adjacent houses (security systems will alert).

Goal:
Return the **maximum amount of money** you can rob without robbing adjacent houses.

------------------------------------------------------
Example:
Input:
nums = [1,2,3,1]

Output:
4

Explanation:
Rob houses 1 and 3 → 1 + 3 = 4

Example 2:
Input:
nums = [2,7,9,3,1]

Output:
12

Explanation:
Rob houses 1, 3, 5 → 2 + 9 + 1 = 12

------------------------------------------------------
Brute Force Approach (Recursion / Try all choices):
1. For each index, either:
   - Rob current house → move to i+2
   - Skip current house → move to i+1
2. Return max of both choices.

- Time Complexity: O(2ⁿ)
- Space Complexity: O(n) recursion stack
Too slow.

------------------------------------------------------
Optimal Approach (Dynamic Programming – Space Optimized):
Idea:
- At each house, choose:
  - `pick`  = rob current + best up to i-2
  - `noPick` = best up to i-1
- Take max.

We only need last two states, so no array required.

Steps:
1. Handle case n = 1.
2. Maintain:
   - `prev` = best till previous house
   - `prevOfPrev` = best till house before previous
3. Iterate and update.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prevOfPrev = 0;
        int prev = nums[0];

        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prevOfPrev; // rob this house
            int noPick = prev;               // skip this house
            int curr = max(pick, noPick);

            prevOfPrev = prev;
            prev = curr;
        }

        return prev;
    }
};

/*
Usage:
Solution obj;
int result = obj.rob(nums);
*/
