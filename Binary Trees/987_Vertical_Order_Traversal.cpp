/*
987. Vertical Order Traversal of a Binary Tree
Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

------------------------------------------------------
Problem Summary:
Return the **vertical order traversal** of a binary tree:
- Nodes are grouped by their horizontal distance (`column`) from the root.
- Within each column:
  1. Nodes are ordered by their depth (`row`).
  2. If multiple nodes share the same column and row, order them by value.

------------------------------------------------------
Optimal BFS + Ordered Maps Approach:
1. Use a nested ordered structure:
   - `map<int, map<int, multiset<int>>> nodes`
     - Outer key = column (vertical distance).
     - Inner key = row (depth).
     - multiset to keep same-level nodes sorted.

2. BFS Traversal:
   - Queue holds pairs of node and its `(column, row)`.
   - For each node:
       - Insert value into `nodes[column][row]`.
       - Push left child `(column-1, row+1)`.
       - Push right child `(column+1, row+1)`.

3. Collect Results:
   - Iterate columns (sorted by `map`).
   - For each row inside a column, append sorted node values.

- Time Complexity: **O(n log n)**  
  `log n` for ordered map/multiset insertions.
- Space Complexity: **O(n)**  
  For maps, multisets, and queue.

------------------------------------------------------
*/

#include <iostream>
#include <map>
#include <set>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // column -> (row -> multiset of node values)
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // node, {column, row}
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();

            int col = pos.first;
            int row = pos.second;
            nodes[col][row].insert(node->val);

            if (node->left)  q.push({node->left, {col - 1, row + 1}});
            if (node->right) q.push({node->right, {col + 1, row + 1}});
        }

        vector<vector<int>> result;
        for (auto &colPair : nodes) {
            vector<int> colVals;
            for (auto &rowPair : colPair.second) {
                colVals.insert(colVals.end(), rowPair.second.begin(), rowPair.second.end());
            }
            result.push_back(colVals);
        }
        return result;
    }
};
