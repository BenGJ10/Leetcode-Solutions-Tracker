/*
454. 4Sum II
Link: https://leetcode.com/problems/4sum-ii/

------------------------------------------------------
Problem Summary:
You are given four integer arrays `nums1`, `nums2`, `nums3`, and `nums4`, each of length `n`.

Your task is to compute how many tuples `(i, j, k, l)` exist such that:
    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

Return the total count of such tuples.

------------------------------------------------------
Example:
Input:
nums1 = [1,2]
nums2 = [-2,-1]
nums3 = [-1,2]
nums4 = [0,2]

Output:
2

Explanation:
The valid tuples are:
- (0,0,0,1) → 1 + (-2) + (-1) + 2 = 0
- (1,1,0,0) → 2 + (-1) + (-1) + 0 = 0

------------------------------------------------------
Brute Force Approach:
1. Use four nested loops to check all possible tuples.
2. Count those whose sum equals zero.

- Time Complexity: O(n⁴)
- Space Complexity: O(1)

Not feasible for n up to 200.

------------------------------------------------------
Optimal Approach (HashMap + Two Sum Reduction):
Idea:
- Split the 4-sum into two independent 2-sum problems.
- Precompute all possible sums of nums3 and nums4.
- Store their frequencies in a hash map.
- For every pair from nums1 and nums2, check if the complementary sum exists.

Steps:
1. Iterate over nums3 and nums4:
   - Store `(nums3[k] + nums4[l])` in a hash map with its frequency.
2. Iterate over nums1 and nums2:
   - Compute `target = -(nums1[i] + nums2[j])`.
   - Add `mpp[target]` to the result.
3. Return the total count.

Why this works:
- We reduce the problem from O(n⁴) to O(n²).
- HashMap allows O(1) average lookup time.

- Time Complexity: O(n²)
- Space Complexity: O(n²)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                     vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int, int> mpp;
        int count = 0;

        // Store sums of nums3 and nums4
        for (int num3 : nums3) {
            for (int num4 : nums4) {
                mpp[num3 + num4]++;
            }
        }

        // Find complementary sums from nums1 and nums2
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                count += mpp[-(nums1[i] + nums2[j])];
            }
        }

        return count;
    }
};

/*
Usage:
Solution obj;
int result = obj.fourSumCount(nums1, nums2, nums3, nums4);
*/
