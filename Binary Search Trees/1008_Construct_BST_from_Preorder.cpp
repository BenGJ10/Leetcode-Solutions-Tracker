/*
1008. Construct Binary Search Tree from Preorder Traversal
Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

------------------------------------------------------
Problem Summary:
Given an array representing the preorder traversal of a BST, construct the original BST.
- Preorder traversal: Root → Left → Right.
- The constructed BST should satisfy BST properties.

------------------------------------------------------
Optimal Approach (Recursive with Bounds):

Idea:
- Use the preorder array and an index pointer to track current element.
- Keep an upper bound for each subtree.
- If current element exceeds the bound, it does not belong in this subtree.
- Recursively build left and right subtrees with updated bounds.

Steps:
1. Initialize `index = 0` and `bound = INT_MAX`.
2. For each recursive call:
   - If index == n or preorder[index] > bound → return nullptr.
   - Create a new node with preorder[index++].
   - Recursively build left subtree with bound = node->val.
   - Recursively build right subtree with bound = current bound.
3. Return the constructed node.

Time Complexity:  O(n)  
    Each element is visited once.
Space Complexity: O(h)  
    h = height of the BST (recursion stack).

------------------------------------------------------
*/

#include <iostream>
#include <vector>
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder, index, INT_MAX);
    }

private:
    TreeNode* build(vector<int> &preorder, int &index, int bound) {
        if(index == preorder.size() || preorder[index] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = build(preorder, index, root->val);
        root->right = build(preorder, index, bound);
        return root;
    }
};

