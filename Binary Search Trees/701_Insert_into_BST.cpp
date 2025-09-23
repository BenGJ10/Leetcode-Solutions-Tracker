/*
701. Insert into a Binary Search Tree
Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/

------------------------------------------------------
Problem Summary:
You are given the root of a Binary Search Tree (BST) and an integer `val`.
Insert `val` into the BST so that it remains a valid BST.
Return the root of the BST after insertion.

------------------------------------------------------
Optimal Approach (Iterative BST Insertion):

Steps:
1. If root is nullptr, create and return a new TreeNode(val).
2. Use a pointer `curr` to traverse:
      - If val < curr->val:
           - If curr->left exists, move left.
           - Else create new node at curr->left and break.
      - Else (val > curr->val):
           - If curr->right exists, move right.
           - Else create new node at curr->right and break.
3. Return the original root.

Time Complexity:  O(h)  
    h = height of BST  
    (O(log n) for balanced tree, O(n) for skewed tree)
Space Complexity: O(1)  
    Iterative solution uses constant extra space.

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);

        TreeNode* curr = root;
        while (curr != nullptr) {
            if (val < curr->val) {
                if (curr->left) curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->right) curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
