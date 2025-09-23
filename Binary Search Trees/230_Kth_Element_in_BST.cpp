/*
230. Kth Smallest Element in a BST
Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

------------------------------------------------------
Problem Summary:
Given the root of a Binary Search Tree (BST) and an integer `k`, 
return the kth smallest element in the BST.

------------------------------------------------------
Optimal Approach (Morris Inorder Traversal):

Idea:
- Inorder traversal of a BST gives nodes in **sorted order**.
- Use Morris Traversal to achieve **O(1) space** (no recursion/stack).
- Keep a counter to track the number of nodes visited.
- When counter == k, we have found the kth smallest element.

Steps:
1. Initialize `curr` as root and `counter = 0`.
2. While `curr` is not nullptr:
   - If `curr->left` is nullptr:
        * Increment counter.
        * If counter == k, record `curr->val`.
        * Move to `curr->right`.
   - Else:
        * Find the rightmost node in `curr->left` subtree (`prev`).
        * If `prev->right` is nullptr:
            - Make temporary link `prev->right = curr`.
            - Move `curr = curr->left`.
        * Else:
            - Break temporary link `prev->right = nullptr`.
            - Increment counter.
            - If counter == k, record `curr->val`.
            - Move `curr = curr->right`.

Time Complexity:  O(n)  
    Each node is visited a constant number of times.
Space Complexity: O(1)  
    Morris traversal uses no extra space.

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
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int kthElem = -1;
        TreeNode* curr = root;

        while(curr != nullptr) {
            if(curr->left == nullptr) {
                counter++;
                if(counter == k) kthElem = curr->val;
                curr = curr->right;
            } 
            else {
                TreeNode* prev = curr->left;
                while(prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }
                
                if(prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } 
                else {
                    prev->right = nullptr;
                    counter++;
                    if(counter == k) kthElem = curr->val;
                    curr = curr->right;
                }
            }
        }
        
        return kthElem;
    }
};
