/*
2488. Count Subarrays With Median K
Link: https://leetcode.com/problems/count-subarrays-with-median-k/

------------------------------------------------------
Problem Summary:
You are given an array `nums` and an integer `k`.

A subarray is considered **valid** if the median of the subarray equals `k`.
Your task is to count how many such subarrays exist.

Important:
- Median definition matches "middle element" when the subarray is sorted.
- For odd length → exact middle.
- For even length → left middle (floor median).

------------------------------------------------------
Example:
Input:
nums = [3,2,1,4,5], k = 4
Output: 3

Valid subarrays:
- [4]
- [4,5]
- [1,4,5]

------------------------------------------------------
Brute Force Approach:
1. For every subarray:
   - Extract subarray
   - Sort it
   - Check if median = k
2. Count all valid ones.

- Time Complexity: O(n³ log n)
- Space Complexity: O(n)

Way too slow.

------------------------------------------------------
Optimal Approach (Transform + Prefix Sum Balance):
Key Observations:
1. For a subarray to have median k:
   - k must be inside the subarray.
   - Count of numbers > k and < k determines validity.
2. Convert numbers:
        nums[i] > k → +1
        nums[i] = k → 0
        nums[i] < k → -1

Let `pivot` be index where nums[i] == k.

For a subarray containing k:
- Let sumLeft = prefix sum on left of pivot
- Let sumRight = prefix sum on pivot...R

The valid condition derived is:
    prefixLeft + prefixRight == 0   OR   prefixLeft + prefixRight == 1

This comes from the rule:
- Odd length: balance must be zero.
- Even length: right side can contribute one extra +1.

Algorithm Steps:
1. Transform nums into -1, 0, 1 array.
2. Compute prefix sums LEFT of pivot and count frequencies in a hashmap.
3. For RIGHT side (including pivot):
   - Compute running prefix.
   - For each prefixR:
        need0 = -prefixR
        need1 = 1 - prefixR
     Add counts from hashmap.
4. Return total count.

- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int pivot = -1, count = 0;

        vector<int> trans(n);

        // Step 1: Transform array and find pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                pivot = i;
                trans[i] = 0;
            } 
            else if (nums[i] > k) trans[i] = 1;
            else trans[i] = -1;
        }

        // Step 2: Map prefix sums on the LEFT of pivot
        unordered_map<int, int> mpp;
        int prefix = 0;
        mpp[0] = 1;  // empty left prefix

        for (int i = pivot - 1; i >= 0; i--) {
            prefix += trans[i];
            mpp[prefix]++;
        }

        // Step 3: Traverse RIGHT side including pivot
        prefix = 0;
        for (int i = pivot; i < n; i++) {
            prefix += trans[i];

            int need1 = -prefix;     // odd-length median condition
            int need2 = 1 - prefix;  // even-length median condition

            count += mpp[need1];
            count += mpp[need2];
        }

        return count;
    }
};

/*
Usage:
Solution obj;
int result = obj.countSubarrays(nums, k);
*/
