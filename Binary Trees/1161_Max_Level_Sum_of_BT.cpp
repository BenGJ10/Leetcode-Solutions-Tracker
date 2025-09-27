/*
1161. Maximum Level Sum of a Binary Tree
Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

------------------------------------------------------
Problem Summary:
Given the root of a binary tree, find the level (1-indexed)
that has the maximum sum of node values.
If multiple levels have the same maximum sum, return the smallest level number.

------------------------------------------------------
Optimal Approach (Level Order Traversal / BFS):

Idea:
- Perform a breadth-first search (BFS) to process the tree level by level.
- For each level:
    * Calculate the sum of all node values.
    * Track which level has the maximum sum.

Steps:
1. Initialize:
    - `maxLevelSum = INT_MIN`
    - `maxLevel = 1`
    - `currentLevel = 1`
2. Use a queue for BFS:
    - For each level:
        * Compute `levelSum`.
        * Update `maxLevelSum` and `maxLevel` if `levelSum` is larger.
3. Increment `currentLevel` after each level is processed.
4. Return `maxLevel`.

- Time Complexity: O(n)  
  (each node visited once)
- Space Complexity: O(w)  
  (queue holds at most the maximum width of the tree)

------------------------------------------------------
*/

#include <climits>
#include <queue>
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
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 1;
        int maxLevelSum = INT_MIN;
        int currentLevel = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (levelSum > maxLevelSum) {
                maxLevelSum = levelSum;
                maxLevel = currentLevel;
            }
            currentLevel++;
        }
        return maxLevel;
    }
};
