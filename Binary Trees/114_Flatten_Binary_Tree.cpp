/*
114. Flatten Binary Tree to Linked List
Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

------------------------------------------------------
Problem Summary:
Convert a binary tree into a flattened linked list **in-place** such that:
- The list uses each node's `right` pointer as the next pointer.
- All `left` pointers are set to `nullptr`.
- The order of nodes follows **preorder traversal** (Root → Left → Right).

------------------------------------------------------
Optimal Iterative Approach (Pointer Manipulation):
1. Start from the root and iterate while `curr` is not null.
2. If `curr` has a left child:
   - Find the **rightmost node** in `curr->left` subtree.
   - Connect that node's `right` to `curr->right`.
   - Move the entire left subtree to `curr->right`.
   - Set `curr->left` to `nullptr`.
3. Move `curr` to `curr->right` and continue.

- Time Complexity:  O(n)  
  Each node is visited a constant number of times.
- Space Complexity: O(1)  
  Done completely in place, no extra stack or recursion.

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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find rightmost node of left subtree
                TreeNode* prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                // Connect rightmost node to current's right subtree
                prev->right = curr->right;
                // Move left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right; // Move to next node
        }
    }
};

