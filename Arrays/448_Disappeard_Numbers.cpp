/*
448. Find All Numbers Disappeared in an Array
Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

------------------------------------------------------
Problem Summary:
Given an integer array `nums` of length `n` where each element is between 1 and n (inclusive),
some elements appear twice and others appear once.

Return an array of all the integers in the range [1, n] that do **not** appear in `nums`.

------------------------------------------------------
Brute Force Approach:
1. For each number from 1 to n, check if it exists in `nums`.
2. If not, add it to the result vector.

- Time Complexity: O(n²)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (In-place Marking using Negatives):
Idea:
- Each value `nums[i]` maps to an index `abs(nums[i]) - 1`.
- Use the sign of elements to track which numbers have been seen.
- Mark `nums[index]` as negative to indicate that `(index + 1)` exists in the array.
- Finally, the indices with positive values represent missing numbers.

Steps:
1. Iterate over `nums` and for each value `v = abs(nums[i])`, mark `nums[v - 1]` as negative.
2. Traverse the array again and collect indices where the values are still positive.

- Time Complexity: O(n)
- Space Complexity: O(1) (in-place modification)

------------------------------------------------------
*/

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0)
                nums[index] = -nums[index];
        }

        vector<int> disappeared;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                disappeared.push_back(i + 1);
        }

        return disappeared;
    }
};

/*
Usage:
Solution obj;
vector<int> result = obj.findDisappearedNumbers(nums);
*/
