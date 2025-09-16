/*
199. Binary Tree Right Side View
Link: https://leetcode.com/problems/binary-tree-right-side-view/

------------------------------------------------------
Problem Summary:
Return the values of the nodes visible when looking at a binary tree from the **right side**.
That is, for each depth level, choose the **rightmost** node.

------------------------------------------------------
Optimal DFS Approach (Right-First Preorder):
1. Perform a depth-first search, always visiting **right child first**, then left.
2. Maintain a vector `result` where `result[level]` holds the first node seen at that level.
3. When we reach a new depth equal to `result.size()`, append the current node's value.

- Time Complexity: **O(n)**  
  Each node is visited once.
- Space Complexity: **O(h)**  
  h = tree height (recursion stack).

------------------------------------------------------
Alternative BFS (Level Order):
- Use a queue for standard level order.
- At each level, record the last node encountered.

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
    void addNodes(TreeNode* root, int level, vector<int>& result) {
        if (root == nullptr) return;

        // If first node at this level, add it (rightmost due to traversal order)
        if (level == (int)result.size()) {
            result.push_back(root->val);
        }
        addNodes(root->right, level + 1, result);
        addNodes(root->left,  level + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        addNodes(root, 0, result);
        return result;
    }
};
