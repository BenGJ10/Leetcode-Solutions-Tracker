/*
235. Lowest Common Ancestor of a Binary Search Tree
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

------------------------------------------------------
Problem Summary:
Given the root of a Binary Search Tree (BST) and two nodes `p` and `q`,
find their lowest common ancestor (LCA).
- LCA of p and q is the lowest node in the tree that has both p and q as descendants.

------------------------------------------------------
Optimal Approach (BST Property):

Idea:
- In a BST, all nodes in the left subtree have values < root->val,
  and all nodes in the right subtree have values > root->val.
- If both p and q are smaller than root, LCA lies in the left subtree.
- If both are greater, LCA lies in the right subtree.
- Otherwise, the current root is the LCA.

Steps:
1. Start from the root.
2. If p->val and q->val < root->val, go to left subtree.
3. If p->val and q->val > root->val, go to right subtree.
4. Else, return current root as LCA.

Time Complexity:  O(h)  
    h = height of the tree (O(log n) for balanced, O(n) worst case).
Space Complexity: 
    - Recursive: O(h) due to call stack.
    - Iterative: O(1) if done without recursion.

------------------------------------------------------
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        int nodeVal = root->val;
        
        if (p->val < nodeVal && q->val < nodeVal)
            return lowestCommonAncestor(root->left, p, q);
        
            if (p->val > nodeVal && q->val > nodeVal)
            return lowestCommonAncestor(root->right, p, q);
        
            return root; // split point → LCA
    }
};

