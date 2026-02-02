/*
698. Partition to K Equal Sum Subsets
Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

------------------------------------------------------
Problem Summary:
You are given an integer array `nums` and an integer `k`.

Your task is to determine whether it is possible to divide the array
into **k non-empty subsets** such that:
- Each subset has the **same sum**
- Every element in `nums` is used exactly once

------------------------------------------------------
Example 1:
Input:
nums = [4,3,2,3,5,2,1], k = 4

Output:
true

Explanation:
The array can be partitioned into:
[5], [1,4], [2,3], [2,3]
Each subset sums to 5.

------------------------------------------------------
Example 2:
Input:
nums = [1,2,3,4], k = 3

Output:
false

------------------------------------------------------
Brute Force Approach:
Try all possible ways to divide elements into k groups.

- Time Complexity: Exponential (kⁿ)
- Space Complexity: O(n)

Not feasible.

------------------------------------------------------
Optimal Approach (Backtracking + Pruning):
Idea:
- Total sum must be divisible by k.
- Each subset must sum to `target = totalSum / k`.
- Use backtracking to build subsets one by one.
- Use a `used[]` array to track which elements are already placed.

Key Optimizations:
1. If `currSum == target`, move on to build the next subset.
2. Sort (or reverse-sort) nums so larger numbers are placed first (pruning).
3. If a number doesn’t fit in an empty subset, stop early.

Steps:
1. Compute total sum; if not divisible by k → return false.
2. Set `target = totalSum / k`.
3. Use a boolean `used[]` array.
4. Backtrack to try forming subsets.
5. If all k subsets are formed → return true.

- Time Complexity: O(k * 2ⁿ) (pruned heavily in practice)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int target;
    vector<bool> used;

    bool backtrack(int index, int k, int currSum, vector<int> &nums) {
        // All subsets formed
        if (k == 0) return true;

        // One subset completed, move to next
        if (currSum == target)
            return backtrack(0, k - 1, 0, nums);

        for (int i = index; i < nums.size(); i++) {
            if (used[i] || currSum + nums[i] > target) continue;

            used[i] = true;
            if (backtrack(i + 1, k, currSum + nums[i], nums))
                return true;
            used[i] = false;

            // Pruning: if first element doesn't fit, no need to try others
            if (currSum == 0) return false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;

        target = totalSum / k;
        used.assign(nums.size(), false);

        // Sort in descending order for better pruning
        sort(nums.rbegin(), nums.rend());

        // Largest element cannot exceed target
        if (nums[0] > target) return false;

        return backtrack(0, k, 0, nums);
    }
};

/*
Usage:
Solution obj;
bool result = obj.canPartitionKSubsets(nums, k);
*/
