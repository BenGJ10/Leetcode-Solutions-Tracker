/*
99. Recover Binary Search Tree
Link: https://leetcode.com/problems/recover-binary-search-tree/

------------------------------------------------------
Problem Summary:
You are given the root of a Binary Search Tree (BST), where
exactly two nodes of the tree were swapped by mistake. Recover
the tree without changing its structure.

------------------------------------------------------
Brute Force Approach (Inorder Traversal + Sorting):
1. Perform an inorder traversal to collect all node values in a vector.
2. Sort the vector (which should represent a valid inorder sequence).
3. Perform another inorder traversal and overwrite node values
   from the sorted vector.

- Time Complexity: O(n log n) due to sorting.
- Space Complexity: O(n) for storing values.

------------------------------------------------------
Optimal Approach (Inorder Traversal + Constant Space Tracking):

Idea:
- A BST’s inorder traversal should yield a sorted sequence.
- If two nodes are swapped:
   * Either they are adjacent in the inorder traversal (detected once).
   * Or they are non-adjacent (detected twice).
- Keep track of:
   * `first`  → first misplaced node
   * `middle` → next node when the adjacent swap occurs
   * `last`   → second misplaced node when non-adjacent
   * `prev`   → previously visited node in inorder

Steps:
1. Traverse the tree inorder.
2. Detect violations: if current node value < prev node value:
   - If `first` not set → assign `first = prev`, `middle = current`.
   - Else assign `last = current`.
3. After traversal:
   - If both `first` and `last` exist → swap their values.
   - Else swap `first` and `middle`.

- Time Complexity: O(n), each node visited once.
- Space Complexity: O(h) recursion stack (h = tree height).

------------------------------------------------------
*/

#include <climits>
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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);

        if(prev && root->val < prev->val){
            if(!first){
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};

