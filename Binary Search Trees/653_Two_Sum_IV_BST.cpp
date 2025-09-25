/*
653. Two Sum IV – Input is a BST
Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

------------------------------------------------------
Problem Summary:
Given the root of a Binary Search Tree (BST) and an integer k,
return true if there exist two elements in the BST such that
their sum is equal to k.

------------------------------------------------------
Brute Force Approach (Inorder + Two Pointers):
1. Perform an inorder traversal to get all values in a sorted vector.
2. Use the classic two-pointer method from both ends to find a pair
   whose sum equals k.

- Time Complexity: O(n) for traversal + O(n) for two-pointer = O(n).
- Space Complexity: O(n) to store all node values.

------------------------------------------------------
Optimal Approach (Two Iterators – Space O(h)):

Idea:
- Instead of storing all values, use two controlled iterators:
  * One iterator gives the next smallest element (inorder).
  * Another iterator gives the next largest element (reverse inorder).
- Compare their sums like two pointers on a sorted array.

Steps:
1. Implement a flexible BSTIterator that can:
      * Traverse in normal inorder (ascending) if reverse = false.
      * Traverse in reverse inorder (descending) if reverse = true.
   - `fillAll(node)` pushes all left/right nodes depending on traversal.
   - `next()` returns the next value in chosen order.

2. Initialize:
      * left iterator (ascending) from root
      * right iterator (descending) from root

3. Fetch the first values l and r from both iterators.
4. While l < r:
      * If l + r == k → return true.
      * If l + r < k → move left iterator to get a bigger number.
      * Else move right iterator to get a smaller number.

- Time Complexity: O(n) in total (each node visited once).
- Space Complexity: O(h) for two stacks, where h is tree height.

------------------------------------------------------
*/

#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private: 
    stack<TreeNode*> st;
    bool reverse;  // true = reverse inorder (descending), false = normal inorder (ascending)

    void fillAll(TreeNode* node){
        while(node){
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool reverseOrder) {
        reverse = reverseOrder;
        fillAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (!reverse) fillAll(node->right);
        else          fillAll(node->left);
        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator left(root, false);   // ascending
        BSTIterator right(root, true);   // descending

        int l = left.next();
        int r = right.next();

        while (l < r) {
            int sum = l + r;
            if (sum == k) return true;
            else if (sum < k) l = left.next();
            else              r = right.next();
        }

        return false;
    }
};

/*
Brute Force alternative (only description required):
- Inorder traverse entire tree into vector<int> vals.
- Use two-pointer from both ends to check for pair sum k.
- O(n) time, O(n) space.
*/
