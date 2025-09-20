/*
94. Binary Tree Inorder Traversal (Morris Traversal)
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

------------------------------------------------------
Problem Summary:
Return the inorder traversal of a binary tree's node values.  
Inorder traversal order is: **Left → Root → Right**.

------------------------------------------------------
Optimal Approach (Morris Traversal - O(1) Space):
1. Initialize `curr` as root.
2. While `curr` is not null:
   - If `curr->left` is null:
     * Visit `curr` (append value to result).
     * Move to `curr->right`.
   - Else:
     * Find the inorder predecessor (`prev`) in the left subtree.
     * If `prev->right` is null, set it to `curr` (thread) and move `curr` to left.
     * Else (thread exists):
       - Remove the thread (`prev->right = nullptr`).
       - Visit `curr` and move to `curr->right`.
3. This avoids recursion and stack by temporarily modifying tree pointers.

- Time Complexity: **O(n)**  
  Each node is visited at most twice.
- Space Complexity: **O(1)**  
  No recursion or stack is used.

------------------------------------------------------
*/

#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = curr; // create thread
                    curr = curr->left;
                } else {
                    prev->right = nullptr; // remove thread
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};
