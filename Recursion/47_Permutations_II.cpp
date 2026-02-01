/*
47. Permutations II
Link: https://leetcode.com/problems/permutations-ii/

------------------------------------------------------
Problem Summary:
Given a collection of numbers `nums` that **may contain duplicates**,
return **all unique permutations** in any order.

------------------------------------------------------
Example:
Input:
nums = [1,1,2]

Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

------------------------------------------------------
Optimal Approach (Backtracking + Set for Uniqueness):
Idea:
- Use backtracking with swapping to generate permutations.
- Insert each complete permutation into a `set` to avoid duplicates.
- Finally, convert the set into a vector.

Steps:
1. Start backtracking from index 0.
2. For each position, swap current index with all possible indices.
3. Recurse for next index.
4. Store permutations in a set to ensure uniqueness.
5. Convert set to result vector.

Note:
This approach is simple and correct, though a more optimized version
can avoid the set by skipping duplicates during recursion.

- Time Complexity: O(n! * n)
- Space Complexity: O(n! * n)

------------------------------------------------------
*/

#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int> &nums, set<vector<int>> &st) {
        if (index == nums.size()) {
            st.insert(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            backtrack(index + 1, nums, st);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        backtrack(0, nums, st);

        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};

/*
Usage:
Solution obj;
vector<vector<int>> result = obj.permuteUnique(nums);
*/
