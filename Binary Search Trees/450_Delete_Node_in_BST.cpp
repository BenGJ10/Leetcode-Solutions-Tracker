/*
450. Delete Node in a BST
Link: https://leetcode.com/problems/delete-node-in-a-bst/

------------------------------------------------------
Problem Summary:
Given the root of a Binary Search Tree (BST) and an integer `key`,
delete the node with value equal to `key` and return the new root.
The BST must remain valid after deletion.

------------------------------------------------------
Optimal Approach (Iterative + Helper Functions):

Idea:
- To delete a node in a BST:
  1. **No child**: Simply remove it.
  2. **One child**: Replace it with its single child.
  3. **Two children**: 
        - Find the inorder predecessor (rightmost node in left subtree)
          or inorder successor (leftmost node in right subtree).
        - Attach the right subtree of the node being deleted
          to the rightmost node of its left subtree.
        - Return the left subtree as the new root of this subtree.

Steps:
1. Create a helper to find the rightmost node of a given subtree (`findLastRightNode`).
2. Create a helper to handle deletion (`helper`):
      - If only one child exists, return that child.
      - If both children exist:
            * Save pointer to right child.
            * Find rightmost node of left subtree.
            * Attach saved right child to that rightmost node.
            * Return left child as new subtree root.
3. Traverse tree iteratively until you find the node whose child matches `key`.
4. Replace the child pointer using the helper function.
5. Return the (possibly unchanged) original root.

Time Complexity:  O(h)  
    h = height of BST  
    O(log n) for balanced tree, O(n) for skewed.
Space Complexity: O(h) for recursion in helper (or O(1) if tail recursion is optimized).

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
    // Find the rightmost node in a subtree
    TreeNode* findLastRightNode(TreeNode* root) {
        if (root->right == nullptr) return root;
        return findLastRightNode(root->right);
    }

    // Helper to delete current node and rearrange subtree
    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr)  return root->right;
        if (root->right == nullptr) return root->left;

        TreeNode* rightSubtree = root->right;
        TreeNode* lastRight = findLastRightNode(root->left);
        lastRight->right = rightSubtree;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) return helper(root);

        TreeNode* curr = root;
        while (curr != nullptr) {
            if (key < curr->val) {
                if (curr->left && curr->left->val == key) {
                    curr->left = helper(curr->left);
                    break;
                } 
                else curr = curr->left;
            } 
            else {
                if (curr->right && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                } 
                else curr = curr->right;
            }
        }
        return root;
    }
};

