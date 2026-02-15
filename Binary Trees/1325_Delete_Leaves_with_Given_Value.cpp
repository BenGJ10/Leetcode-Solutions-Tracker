/*
1325. Delete Leaves With a Given Value
Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/

------------------------------------------------------
Problem Summary:
Given a binary tree `root` and an integer `target`,
delete all the **leaf nodes** with value equal to `target`.

Note:
- After deleting a leaf node, its parent may become a leaf.
- If that parent’s value equals `target`, it must also be deleted.
- Continue until no such nodes remain.

Return the updated root.

------------------------------------------------------
Example 1:
Input:
root = [1,2,3,2,null,2,4], target = 2

Output:
[1,null,3,null,4]

------------------------------------------------------
Example 2:
Input:
root = [1,3,3,3,2], target = 3

Output:
[1,3,null,null,2]

------------------------------------------------------
Brute Force Approach:
Repeatedly:
1. Traverse the tree.
2. Remove all matching leaf nodes.
3. Repeat until no more deletions happen.

- Time Complexity: O(n²) worst case
- Space Complexity: O(h)

Inefficient due to repeated traversals.

------------------------------------------------------
Optimal Approach (Postorder DFS):
Idea:
Use **postorder traversal** (Left → Right → Root).

Why?
Because:
- We must process children first.
- After updating children, the current node may become a leaf.
- If it's a leaf and matches target → delete it.

Steps:
1. Recursively update left and right children.
2. If both children are null and current value == target:
   → return nullptr.
3. Otherwise return current node.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n)
- Space Complexity: O(h) recursion stack
  (h = height of tree)

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return nullptr;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (root->left == nullptr && root->right == nullptr &&
            root->val == target) {
            return nullptr;
        }
        return root;
    }
};

/*
Usage:
Solution obj;
TreeNode* result = obj.removeLeafNodes(root, target);
*/
