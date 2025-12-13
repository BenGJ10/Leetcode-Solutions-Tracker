/*
532. K-diff Pairs in an Array
Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/

------------------------------------------------------
Problem Summary:
You are given an integer array `nums` and an integer `k`.

A **k-diff pair** is defined as a pair of integers `(nums[i], nums[j])` such that:
- i ≠ j
- |nums[i] - nums[j]| = k

Return the **number of unique k-diff pairs** in the array.

------------------------------------------------------
Example 1:
Input:
nums = [3,1,4,1,5], k = 2

Output:
2

Explanation:
The pairs are (1,3) and (3,5).

------------------------------------------------------
Example 2:
Input:
nums = [1,2,3,4,5], k = 1

Output:
4

------------------------------------------------------
Example 3:
Input:
nums = [1,3,1,5,4], k = 0

Output:
1

Explanation:
Only pair is (1,1).

------------------------------------------------------
Brute Force Approach:
1. Use two nested loops to check every possible pair.
2. Count pairs satisfying |nums[i] - nums[j]| = k.
3. Use a set to avoid duplicate pairs.

- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Hash Map Frequency Counting):
Idea:
- Count the frequency of each number using a hash map.
- Handle two cases separately:
  1. **k = 0**:
     - We need numbers appearing at least twice.
  2. **k > 0**:
     - For each unique number `x`, check if `x + k` exists.

This ensures uniqueness and avoids double counting.

Steps:
1. Build frequency map of `nums`.
2. For each unique number:
   - If `k == 0` and frequency > 1 → valid pair.
   - If `k > 0` and `(number + k)` exists → valid pair.
3. Count all such cases.

- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int count = 0;

        // Count frequencies
        for (int num : nums) 
            mpp[num]++;

        // Count valid pairs
        for (auto &elem : mpp) {
            if (k == 0 && elem.second > 1) {
                count++;
            }
            if (k > 0 && mpp.find(elem.first + k) != mpp.end()) {
                count++;
            }
        }

        return count;
    }
};

/*
Usage:
Solution obj;
int result = obj.findPairs(nums, k);
*/
