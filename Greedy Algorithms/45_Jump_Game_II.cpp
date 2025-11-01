/*
45. Jump Game II
Link: https://leetcode.com/problems/jump-game-ii/

------------------------------------------------------
Problem Summary:
You are given an integer array `nums` where each element represents the maximum jump length
at that position. Your goal is to reach the **last index** in the minimum number of jumps.

Return the minimum number of jumps required to reach the last index.

------------------------------------------------------
Brute Force Approach (Recursive / BFS):
1. From each index, recursively explore all possible jumps up to `nums[i]`.
2. Keep track of the minimum jumps needed to reach the end.
3. Return the minimum among all valid paths.

- Time Complexity: O(2ⁿ)
- Space Complexity: O(n) (recursion depth)

------------------------------------------------------
Optimal Approach (Greedy - Level-Based Traversal):
Idea:
- Think of it like a BFS traversal of ranges.
- At each level (jump), we explore all positions we can reach.
- Once we move past the current range (`near` to `far`), we increase the jump count and
  update the next reachable range (`farthest`).

Steps:
1. Initialize:
   - `near` = start of the current level
   - `far` = end of the current level
   - `jumps` = 0
2. While `far` < `n - 1`:
   - For each index `i` from `near` to `far`, find the farthest reachable index (`farthest = max(farthest, i + nums[i])`).
   - Update `near = far + 1` and `far = farthest` for the next level.
   - Increment `jumps`.
3. Return `jumps`.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0, far = 0, jumps = 0;
        
        while (far < nums.size() - 1) {
            int farthest = 0;
            for (int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }
        
        return jumps;
    }
};

/*
Usage:
Solution obj;
int result = obj.jump(nums);
*/
