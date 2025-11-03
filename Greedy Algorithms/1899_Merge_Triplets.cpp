/*
1899. Merge Triplets to Form Target Triplet
Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

------------------------------------------------------
Problem Summary:
You are given a list of triplets, where each triplet `triplets[i] = [ai, bi, ci]` represents
a point in 3D space. You are also given a target triplet `[x, y, z]`.

You can merge any two triplets `(a, b, c)` and `(d, e, f)` to form:
    (max(a, d), max(b, e), max(c, f))

Return `true` if you can form the target triplet `(x, y, z)` by merging some of the given triplets, 
otherwise `false`.

------------------------------------------------------
Brute Force Approach:
1. Try merging all combinations of triplets.
2. Keep checking if any merged result equals the target.
3. Return true if found.

- Time Complexity: O(n²)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Greedy Filtering):
Idea:
- We only care about triplets that do not exceed the target in any dimension.
- Filter triplets where all values are ≤ their corresponding target values.
- Track whether each coordinate (x, y, z) of the target can be formed from at least one triplet.

Steps:
1. Initialize `valid = {0, 0, 0}` to track if each target component can be matched.
2. For each triplet:
   - If any value in the triplet exceeds the corresponding target value, skip it.
   - Otherwise:
     - If `triplet[i] == target[i]`, mark `valid[i] = 1`.
3. After processing all triplets, return true if all `valid` values are > 0.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int valid[3] = {0};
        
        for (auto &triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            } else {
                if (target[0] == triplet[0]) valid[0] += 1;
                if (target[1] == triplet[1]) valid[1] += 1;
                if (target[2] == triplet[2]) valid[2] += 1;
            }
        }
        
        return valid[0] > 0 && valid[1] > 0 && valid[2] > 0;
    }
};

/*
Usage:
Solution obj;
bool result = obj.mergeTriplets(triplets, target);
*/
