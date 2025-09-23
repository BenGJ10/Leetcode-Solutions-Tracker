/*
98. Validate Binary Search Tree
Link: https://leetcode.com/problems/validate-binary-search-tree/

------------------------------------------------------
Problem Summary:
Determine if a binary tree is a valid Binary Search Tree (BST).  
- A BST satisfies: left subtree < node < right subtree for all nodes.
- All values in the left subtree must be strictly less than the node's value.
- All values in the right subtree must be strictly greater than the node's value.

------------------------------------------------------
Optimal Approach (DFS with Range Limits):

Idea:
- Use a helper function that carries the valid range (`min`, `max`) for each node.
- Check if node->val lies within `(min, max)`.
- Recursively check left subtree with updated max = node->val.
- Recursively check right subtree with updated min = node->val.

Steps:
1. Initialize check with range `(-∞, +∞)`.
2. For each node:
   - If node is null, return true.
   - If node->val not in (min, max), return false.
   - Recursively check left and right subtrees with updated ranges.

Time Complexity:  O(n)  
    Visit each node once.
Space Complexity: O(h)  
    h = height of the tree (recursion stack).

------------------------------------------------------
*/

#include <iostream>
#include <climits>
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
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }

private:
    bool checkBST(TreeNode* root, long left, long right){
        if(root == nullptr) return true;
        if(root->val <= left || root->val >= right) return false;
        return checkBST(root->left, left, root->val) &&
               checkBST(root->right, root->val, right);
    }
};
