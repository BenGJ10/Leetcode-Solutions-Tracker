/*
662. Maximum Width of Binary Tree
Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

------------------------------------------------------
Problem Summary:
Find the **maximum width** of a binary tree.  
- The width of one level is the distance between the leftmost and rightmost
  non-null nodes at that level, counted in terms of the node positions
  if the tree were a complete binary tree.

------------------------------------------------------
Optimal BFS + Indexing Approach:
1. Perform level-order traversal using a queue of `{node, index}`.
   - Treat the tree as if it were a complete binary tree:
     * Left child index = `2 * idx + 1`
     * Right child index = `2 * idx + 2`
2. For each level:
   - Normalize indices by subtracting the minimum index of that level
     to avoid overflow.
   - Record the first and last indices to compute width = `last - first + 1`.
3. Keep track of the maximum width across all levels.

- Time Complexity: **O(n)**  
  Every node is visited once.
- Space Complexity: **O(n)**  
  Queue stores nodes of the largest level.

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int levelSize = q.size();
            long long minIndex = q.front().second;
            long long firstIndex = 0, lastIndex = 0;

            for (int i = 0; i < levelSize; i++) {
                auto [node, idx] = q.front();
                q.pop();
                long long curr = idx - minIndex;  // normalize
                if (i == 0) firstIndex = curr;
                if (i == levelSize - 1) lastIndex = curr;

                if (node->left)  q.push({node->left,  2 * curr + 1});
                if (node->right) q.push({node->right, 2 * curr + 2});
            }
            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
        }
        return static_cast<int>(maxWidth);
    }
};

