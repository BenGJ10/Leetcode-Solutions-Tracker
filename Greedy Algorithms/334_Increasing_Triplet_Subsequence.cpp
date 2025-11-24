/*
334. Increasing Triplet Subsequence
Link: https://leetcode.com/problems/increasing-triplet-subsequence/

------------------------------------------------------
Problem Summary:
Given an integer array `nums`, return `true` if there exists a triplet 
(i < j < k) such that:
    nums[i] < nums[j] < nums[k]

Otherwise, return `false`.

You must achieve this in O(n) time and O(1) extra space.

------------------------------------------------------
Brute Force Approach:
1. For each index i, check all j > i.
2. For each j, check all k > j.
3. If nums[i] < nums[j] < nums[k], return true.

- Time Complexity: O(n³)
- Space Complexity: O(1)

Better brute force:
- Fix middle value j and check left smaller + right bigger.

- Time Complexity: O(n²)
- Space Complexity: O(1)

Still too slow.

------------------------------------------------------
Optimal Approach (Greedy - Track First Two Minimums):
Idea:
We only need to track two values:
- `first` → smallest number so far
- `second` → second smallest number larger than `first`

Algorithm:
1. Initialize:
   - `first = INT_MAX`
   - `second = INT_MAX`
2. Traverse array:
   - If `num <= first`, update `first = num`
   - Else if `num <= second`, update `second = num`
   - Else → num is larger than both → found triplet → return true.

Why this works:
- `first` ensures the left smallest.
- `second` ensures the middle number.
- Any number greater than both forms a valid triplet.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num;          // update smallest so far
            } 
            else if (num <= second) {
                second = num;         // update middle number
            } 
            else {
                return true;          // found num > second > first
            }
        }
        return false;
    }
};

/*
Usage:
Solution obj;
bool result = obj.increasingTriplet(nums);
*/
