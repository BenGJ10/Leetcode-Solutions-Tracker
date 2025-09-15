/*
103. Binary Tree Zigzag Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

------------------------------------------------------
Problem Summary:
Return the **zigzag level order traversal** of a binary tree’s nodes:
- Nodes at each level are visited from **left → right**, then **right → left**, alternating every level.

------------------------------------------------------
Approach (BFS with Direction Flag):
1. Use a queue for standard level-order (BFS) traversal.
2. Maintain a boolean `flag`:
   - `true` → left to right.
   - `false` → right to left.
3. For each level:
   - Create a vector `level` of size `levelSize`.
   - For every node in this level, compute its index:
       - If `flag` is true, index = i.
       - Else, index = levelSize - i - 1.
   - Place node values accordingly.
4. Toggle the `flag` after each level.

- Time Complexity: O(n)  
  Each node is visited once.
- Space Complexity: O(n)  
  Queue for BFS + result storage.

------------------------------------------------------
*/

#include <iostream>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; // true = left→right, false = right→left

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = flag ? i : levelSize - i - 1;
                level[index] = node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            flag = !flag;             // toggle direction
            result.push_back(level);  // add current level
        }
        return result;
    }
};

