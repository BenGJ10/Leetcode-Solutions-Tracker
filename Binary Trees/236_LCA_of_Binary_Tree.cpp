/*
236. Lowest Common Ancestor of a Binary Tree
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

------------------------------------------------------
Problem Summary:
Given a binary tree and two nodes `p` and `q`, find their **lowest common ancestor (LCA)**.  
The LCA is the lowest node in the tree that has both `p` and `q` as descendants  
(where a node can be a descendant of itself).

------------------------------------------------------
Recursive DFS Approach:
1. Base cases:
   - If the current node is `nullptr`, return `nullptr`.
   - If the current node equals `p` or `q`, return that node.
2. Recurse on left and right subtrees.
3. After recursion:
   - If both left and right calls return non-null, current node is the LCA.
   - Otherwise, return the non-null child.

- Time Complexity: **O(n)**  
  Each node is visited once.
- Space Complexity: **O(h)**  
  Recursion stack, where `h` is the height of the tree.

------------------------------------------------------
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;

        TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;   // p and q found in different subtrees
        return left ? left : right;       // either one side is non-null
    }
};
