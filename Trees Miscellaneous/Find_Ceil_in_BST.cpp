/*
Find Ceil in a Binary Search Tree
Link: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

------------------------------------------------------
Problem Summary:
Given the root of a Binary Search Tree (BST) and an integer `x`,
find the **ceil** of `x` in the BST.
- The **ceil** of `x` is the smallest integer in the BST
  that is greater than or equal to `x`.
- If no such value exists, return -1.

------------------------------------------------------
Optimal Approach (Iterative BST Traversal):

1. Initialize `ceil = -1`.
2. While root is not nullptr:
      - If root->data == x: return root->data.
      - If root->data < x: move root = root->right.
      - Else: 
          - Update ceil = root->data.
          - Move root = root->left.
3. Return `ceil`.

Time Complexity:  O(h)  
    h = height of BST  
    (O(log n) for balanced tree, O(n) worst case)
Space Complexity: O(1)  
    Iterative traversal uses constant extra space.

------------------------------------------------------
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findCeil(Node* root, int x) {
        int ceil = -1;
        while (root != nullptr) {
            if (root->data == x) {
                return root->data; // Exact match
            }
            
            if (root->data < x) {
                root = root->right; // Need a bigger value
            } 
            else {
                ceil = root->data;  // Possible ceil
                root = root->left;  // Look for smaller valid value
            }
        }
        return ceil;
    }
};
