/*
55. Jump Game
Link: https://leetcode.com/problems/jump-game/

------------------------------------------------------
Problem Summary:
You are given an integer array `nums` where each element represents the maximum jump length
from that position. Your goal is to determine if you can reach the **last index** starting from index `0`.

Return `true` if you can reach the last index, otherwise `false`.

------------------------------------------------------
Example:
Input:
nums = [2,3,1,1,4]

Output:
true

Explanation:
- Start at index 0 → jump to index 1 (max jump = 2)
- From index 1 → can reach the last index easily (3 + 1 >= 4)
So, it is possible to reach the end.

Example 2:
Input:
nums = [3,2,1,0,4]

Output:
false

Explanation:
You reach index 3 but can’t jump further since `nums[3] = 0`.

------------------------------------------------------
Brute Force Approach:
1. From each index, recursively try all possible jumps up to `nums[i]`.
2. If any path reaches the end, return true.
3. Otherwise, false.

- Time Complexity: O(2ⁿ)
- Space Complexity: O(n) (recursion stack)

------------------------------------------------------
Optimal Approach (Greedy):
Idea:
- Maintain the farthest index you can reach so far (`maxIndex`).
- Traverse from left to right:
  - If at any index `i`, `i > maxIndex`, you can’t reach this position → return false.
  - Otherwise, update `maxIndex = max(maxIndex, i + nums[i])`.
- If the loop completes, it means the end is reachable.

Steps:
1. Initialize `maxIndex = 0`.
2. For each index `i`:
   - If `i > maxIndex` → return false.
   - Update `maxIndex = max(maxIndex, i + nums[i])`.
3. If loop ends → return true.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxIndex < i)
                return false;
            maxIndex = max(maxIndex, nums[i] + i);
        }
        return true;
    }
};

/*
Usage:
Solution obj;
bool result = obj.canJump(nums);
*/
