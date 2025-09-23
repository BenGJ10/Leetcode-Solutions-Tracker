/*
700. Search in a Binary Search Tree
Link: https://leetcode.com/problems/search-in-a-binary-search-tree/

------------------------------------------------------
Problem Summary:
Given the root of a Binary Search Tree (BST) and an integer `val`,
return the subtree rooted at the node whose value equals `val`.
If such a node does not exist, return nullptr.

------------------------------------------------------
Optimal Approach (Recursive or Iterative BST Search):

Idea:
- A BST has the property:
      left subtree values < node->val < right subtree values.
- Use this property to decide which direction to move.

Steps:
1. If root is nullptr, return nullptr (value not found).
2. If root->val == val, return root.
3. If val < root->val, search in the left subtree.
4. Else, search in the right subtree.

Time Complexity:  O(h)  
    h = height of the tree  
    (O(log n) for a balanced BST, O(n) in the worst skewed case)
Space Complexity: 
    - Recursive: O(h) due to call stack.
    - Iterative: O(1) if we avoid recursion.

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
    // Recursive implementation
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) 
            return root;
        if (val < root->val) 
            return searchBST(root->left, val);
        else 
            return searchBST(root->right, val);
    }

    // Iterative implementation (optional)
    TreeNode* searchBSTIterative(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            if (val < root->val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};



