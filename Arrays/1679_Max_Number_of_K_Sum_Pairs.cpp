/*
1679. Max Number of K-Sum Pairs
Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/

------------------------------------------------------
Problem Summary:
You are given an integer array `nums` and an integer `k`.
Your task is to find the **maximum number of operations** such that:

- In each operation, you pick two numbers from `nums` whose sum is exactly `k`.
- Remove both numbers from the array.
- Return the total number of such operations.

------------------------------------------------------
Brute Force Approach:
1. For each element, search the array for another element that makes sum = k.
2. When found, mark both as used.
3. Continue.

- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Hash Map Counting):
Idea:
- Use a hash map to store counts of numbers seen so far.
- For each number `num`, check if we have seen a complement `k - num` available.
- If found → form a pair and decrement its count.
- Else → store `num` for future pairing.

Steps:
1. Initialize `unordered_map<int, int> mpp` for frequency counting.
2. Traverse each number in `nums`:
   - Compute `value = k - num`.
   - If `mpp[value] > 0`, form a valid operation and decrement `mpp[value]`.
   - Else, store the number by incrementing `mpp[num]`.
3. Return `count` of successful operations.

- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int count = 0;

        for (int num : nums) {
            int needed = k - num;
            if (mpp[needed] > 0) {
                count++;
                mpp[needed]--;
            } else {
                mpp[num]++;
            }
        }
        return count;
    }
};

/*
Usage:
Solution obj;
int result = obj.maxOperations(nums, k);
*/
