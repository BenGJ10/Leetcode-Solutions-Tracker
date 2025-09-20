/*
144. Binary Tree Preorder Traversal (Morris Traversal)
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

------------------------------------------------------
Problem Summary:
Return the preorder traversal of a binary tree's node values.  
Preorder traversal order is: **Root → Left → Right**.

------------------------------------------------------
Optimal Approach (Morris Preorder Traversal - O(1) Space):
1. Initialize `curr` as root.
2. While `curr` is not null:
   - If `curr->left` is null:
     * Visit `curr` (append value to result).
     * Move to `curr->right`.
   - Else:
     * Find the inorder predecessor (`prev`) in the left subtree.
     * If `prev->right` is null:
       - Create a thread (`prev->right = curr`).
       - Visit `curr` (preorder).
       - Move `curr` to left.
     * Else (thread exists):
       - Remove the thread (`prev->right = nullptr`).
       - Move `curr` to `curr->right`.
3. This method avoids recursion and explicit stack by temporarily modifying tree pointers.

- Time Complexity: **O(n)**  
  Each node is visited at most twice.
- Space Complexity: **O(1)**  
  No recursion or stack used.

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                preorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = curr; // create thread
                    preorder.push_back(curr->val);
                    curr = curr->left;
                } else {
                    prev->right = nullptr; // remove thread
                    curr = curr->right;
                }
            }
        }

        return preorder;
    }
};
