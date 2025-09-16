/*
113. Path Sum II
Link: https://leetcode.com/problems/path-sum-ii/

------------------------------------------------------
Problem Summary:
Return **all root-to-leaf paths** where the sum of node values equals a given `targetSum`.

- A path is from **root to any leaf node**.
- The total of all node values along that path must equal `targetSum`.

------------------------------------------------------
DFS + Backtracking Approach:
1. Start a Depth-First Search from the root.
2. Keep a running `path` vector and subtract each node's value from `targetSum`.
3. When a **leaf node** is reached and the remaining target is 0:
   - Push the current path into the final result.
4. Backtrack:
   - After exploring left and right subtrees, remove the current node from `path`.

- Time Complexity: **O(N)**  
  Each node is visited once; copying the current path to the answer costs proportional to the output size.
- Space Complexity: **O(H)** recursion stack, where H = height of the tree.

------------------------------------------------------
*/

#include <iostream>
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
    vector<vector<int>> pathSums;

    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == nullptr) return;

        path.push_back(root->val);
        targetSum -= root->val;

        if (!root->left && !root->right && targetSum == 0) {
            pathSums.push_back(path);
        } else {
            dfs(root->left, targetSum, path);
            dfs(root->right, targetSum, path);
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return pathSums;
    }
};
