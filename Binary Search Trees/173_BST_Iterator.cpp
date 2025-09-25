/*
173. Binary Search Tree Iterator
Link: https://leetcode.com/problems/binary-search-tree-iterator/

------------------------------------------------------
Problem Summary:
Implement an iterator over a Binary Search Tree (BST) that returns
the next smallest number in ascending order.
Class should support:
    - `int next()`   → returns the next smallest element.
    - `bool hasNext()` → returns true if there is a next smallest element.

------------------------------------------------------
Brute Force Approach (Inorder Traversal + Array):
1. Perform a full inorder traversal of the BST.
2. Store all elements in a vector during construction.
3. Maintain an index pointer to track the next element.

- Time Complexity:
    * Construction: O(n)
    * next()/hasNext(): O(1)
- Space Complexity: O(n) to store all elements.

------------------------------------------------------
Optimal Approach (Controlled Inorder Traversal with Stack):
1. Constructor: push all left nodes starting from root onto stack.
2. next():
    - Pop top of stack.
    - If popped node has a right child, push all its left descendants.
    - Return popped node's value.
3. hasNext(): return whether stack is non-empty.

- Time Complexity:
    * Overall amortized O(n) for n calls to next (each node pushed/popped once).
    * next(): O(1) amortized.
    * hasNext(): O(1).
- Space Complexity: O(h) for stack, where h is the height of the tree.

------------------------------------------------------
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

/*
Usage:
BSTIterator* obj = new BSTIterator(root);
int val = obj->next();
bool more = obj->hasNext();
*/
