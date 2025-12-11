/*
2025. Special Triplets
Link: https://leetcode.com/problems/count-special-triplets/description/

------------------------------------------------------
Problem Summary:
Given an integer array `nums`, count the number of **special triplets** `(i, j, k)` 
such that:
1. `i < j < k`
2. `nums[i] + nums[k] = 2 * nums[j]`

This means the middle element must be the average of the two ends.

Return the total number of such triplets modulo 1e9+7.

------------------------------------------------------
Example:
Input:
nums = [2,3,4,6,8]

Possible triplets:
- (2,3,4)
- (3,4,5)
Total = 2

Output:
2

------------------------------------------------------
Brute Force Approach:
Use 3 nested loops for i < j < k, check if condition holds.

- Time Complexity: O(n³)
- Space Complexity: O(1)

Too slow for constraints.

------------------------------------------------------
Optimal Approach (Prefix-Suffix Hashing):
Idea:
Rewrite condition:
    nums[i] + nums[k] = 2 * nums[j]
→  nums[i] = 2*nums[j] - nums[k]

But instead of iterating all i and k pairs, we exploit symmetry:

For a fixed middle index j:
- `nums[i]` must equal `nums[j] * 2`.
- `nums[k]` must also equal `nums[j] * 2`.

So triplet count contribution becomes:
    prefix[2 * nums[j]] * suffix[2 * nums[j]]

Where:
- `prefix[x]` = count of the value x before index j.
- `suffix[x]` = count of the value x after index j.

Steps:
1. Build frequency map `suffix` for all numbers.
2. Iterate through every middle element `num = nums[j]`:
   - Remove nums[j] from suffix.
   - Add to answer: prefix[2*num] * suffix[2*num].
   - Add nums[j] to prefix.
3. Return answer % mod.

- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
        long long answer = 0;
        unordered_map<long, long> prefix, suffix;

        // Count all numbers in suffix initially
        for (int num : nums) {
            suffix[num] += 1;
        }

        // Iterate treating nums[j] as middle element
        for (int num : nums) {
            suffix[num] -= 1;  // remove current from suffix

            long long target = num * 2LL;
            answer += prefix[target] * suffix[target];

            prefix[num] += 1;  // add current to prefix
        }

        return answer % mod;
    }
};

/*
Usage:
Solution obj;
int result = obj.specialTriplets(nums)
*/
