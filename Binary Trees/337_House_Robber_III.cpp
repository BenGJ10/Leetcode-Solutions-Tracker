/*
337. House Robber III
Link: https://leetcode.com/problems/house-robber-iii/

------------------------------------------------------
Problem Summary:
You are given the `root` of a binary tree.
Each node represents a house with some money.

You cannot rob two directly connected houses
(i.e., parent and child cannot both be robbed).

Return the **maximum amount of money** you can rob.

------------------------------------------------------
Example 1:
Input:
    3
   / \
  2   3
   \    \
    3    1

Output:
7

Explanation:
Rob 3 (root) + 3 + 1 = 7

------------------------------------------------------
Example 2:
Input:
    3
   / \
  4   5
 / \    \
1   3    1

Output:
9

Explanation:
Rob 4 + 5 = 9

------------------------------------------------------
Brute Force Approach:
For each node:
- Either rob it (skip its children)
- Or skip it (rob children)

This causes repeated subproblems.

- Time Complexity: Exponential
- Space Complexity: O(h)

------------------------------------------------------
Optimal Approach (Tree DP + Memoization):
Idea:
For each node, compute:
1️⃣ Include current node:
   - Add node value
   - Skip immediate children
   - Rob grandchildren

2️⃣ Exclude current node:
   - Rob left child
   - Rob right child

Take:
    max(include, exclude)

Use a hashmap to memoize results per node
to avoid recomputation.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n)
- Space Complexity: O(n) for memo + recursion stack

------------------------------------------------------
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<TreeNode*, int> mpp;

    int rob(TreeNode* root) {
        if (root == nullptr) return 0;

        if (mpp.find(root) != mpp.end())
            return mpp[root];

        // Include current node
        int include = root->val;

        if (root->left) {
            include += rob(root->left->left);
            include += rob(root->left->right);
        }

        if (root->right) {
            include += rob(root->right->left);
            include += rob(root->right->right);
        }

        // Exclude current node
        int exclude = rob(root->left) + rob(root->right);

        return mpp[root] = max(include, exclude);
    }
};

/*
Usage:
Solution obj;
int result = obj.rob(root);
*/
