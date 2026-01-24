/*
3355. Zero Array Transformation I
Link: https://leetcode.com/problems/zero-array-transformation-i/

------------------------------------------------------
Problem Summary:
You are given:
- An integer array `nums`
- A list of queries, where each query is of the form `[l, r]`

Each query means:
- Decrease every element in the subarray `nums[l ... r]` by **1**

You can apply all queries in any order, but **each query can be applied at most once**.

Your task is to check whether it is possible to make **every element of `nums` equal to 0 or less**
after applying all queries.

Return `true` if possible, otherwise return `false`.

------------------------------------------------------
Example:
Input:
nums = [1,0,1]
queries = [[0,2]]

Output:
true

Explanation:
After applying the query:
nums → [0,-1,0], all values ≤ 0.

------------------------------------------------------
Brute Force Approach:
1. For each query:
   - Iterate from `l` to `r` and decrement each element.
2. After processing all queries, check if all elements ≤ 0.

- Time Complexity: O(n * q)
- Space Complexity: O(1)

This is too slow for large inputs.

------------------------------------------------------
Optimal Approach (Difference Array + Prefix Sum):
Idea:
- Each query applies a **range decrement (-1)**.
- Instead of updating each range directly, use a **difference array**.

For a query [l, r]:
- diff[l] -= 1
- diff[r + 1] += 1

After processing all queries:
- Compute prefix sum of diff to know total decrement applied at each index.
- Check if `nums[i] + prefixSum <= 0` for all `i`.

Why it works:
- Difference array converts multiple range updates into O(1) operations.
- Prefix sum reconstructs the net effect at each index.

Steps:
1. Initialize difference array of size `n + 1`.
2. Apply all queries as range updates.
3. Compute prefix sum and validate each element.
4. If any value becomes positive → return false.

- Time Complexity: O(n + q)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArray(n + 1, 0);

        // Apply difference array updates
        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];

            diffArray[l] -= 1;
            if (r + 1 < n) diffArray[r + 1] += 1;
        }

        // Build prefix sum and validate
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += diffArray[i];
            if (nums[i] + prefixSum > 0) return false;
        }

        return true;
    }
};

/*
Usage:
Solution obj;
bool result = obj.isZeroArray(nums, queries);
*/
