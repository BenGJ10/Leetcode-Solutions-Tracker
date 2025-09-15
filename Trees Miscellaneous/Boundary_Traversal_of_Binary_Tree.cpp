/*
Boundary Traversal of Binary Tree (GeeksforGeeks)
Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

------------------------------------------------------
Problem Summary:
Print the **boundary traversal** of a binary tree in anti-clockwise direction:
1. **Root Node** (if not a leaf).
2. **Left Boundary** (top to bottom, excluding leaves).
3. **All Leaf Nodes** (from left to right).
4. **Right Boundary** (bottom to top, excluding leaves).

------------------------------------------------------
Approach:
Break the traversal into three helper routines:

1. **Left Boundary (excluding leaves)**  
   - Start from `root->left`.  
   - Keep moving to the left if possible, else right.  
   - Add node values to result except when it's a leaf.

2. **Leaf Nodes**  
   - Perform a DFS.
   - Add every leaf node to the result.

3. **Right Boundary (excluding leaves, reversed)**  
   - Start from `root->right`.
   - Keep moving to the right if possible, else left.
   - Push nodes onto a stack to reverse order, then append to result.

- Time Complexity: **O(n)**  
  Each node is visited at most once.
- Space Complexity: **O(h)** recursion/stack (h = height of tree).

------------------------------------------------------
*/

#include <iostream>
#include <stack>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool isLeaf(Node* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    
    void addLeftBoundary(Node* root, vector<int>& result) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) result.push_back(curr->data);
            curr = (curr->left) ? curr->left : curr->right;
        }
    }
    
    void addRightBoundary(Node* root, vector<int>& result) {
        Node* curr = root->right;
        stack<int> st;
        while (curr) {
            if (!isLeaf(curr)) st.push(curr->data);
            curr = (curr->right) ? curr->right : curr->left;
        }
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
    }
    
    void addLeaves(Node* root, vector<int>& result) {
        if (isLeaf(root)) {
            result.push_back(root->data);
            return;
        }
        if (root->left)  addLeaves(root->left, result);
        if (root->right) addLeaves(root->right, result);
    }

public:
    vector<int> boundaryTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;

        if (!isLeaf(root)) result.push_back(root->data);
        addLeftBoundary(root, result);
        addLeaves(root, result);
        addRightBoundary(root, result);

        return result;
    }
};
