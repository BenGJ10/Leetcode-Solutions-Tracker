/*
1339. Maximum Product of Splitted Binary Tree
Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

------------------------------------------------------
Problem Summary:
You are given the root of a binary tree with positive integer values.

You may **split the binary tree into two subtrees** by removing exactly one edge.
After the split:
- Each subtree has its own sum of node values.

Your task:
Return the **maximum product of the sums** of the two subtrees, modulo 1e9+7.

------------------------------------------------------
Example:
Input:
        1
       / \
      2   3
Output:
9

Explanation:
Remove edge between 1 and 2:
- Sum1 = 2
- Sum2 = 1 + 3 = 4
Product = 2 × 4 = 8

Best split gives:
Sum1 = 6, Sum2 = 3 → product = 18 (depending on tree)

------------------------------------------------------
Brute Force Approach:
1. Compute sum of all nodes.
2. For every possible edge removal:
   - compute sum of both sides
   - track maximum product.

This requires repeated subtree sum calculations.

- Time Complexity: O(n²)
- Space Complexity: O(h)

Too slow for large trees.

------------------------------------------------------
Optimal Approach (Two DFS Passes):
Idea:
We just need **subtree sums**.

Steps:

1️⃣ First DFS:
- Compute `totalSum` of all tree nodes.

2️⃣ Second DFS:
- For every subtree:
    - Let `currSum` be subtree sum
    - Other subtree sum = `totalSum - currSum`
    - Product = currSum × (totalSum − currSum)
- Track maximum product.

We never actually delete edges, just simulate all possibilities.

- Time Complexity: O(n)
- Space Complexity: O(h) recursion stack

------------------------------------------------------
*/

#include <algorithm>
#include <cstdint>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    long long maxProd = 0;
    long long totalSum = 0;

    long long calculateTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + calculateTotalSum(root->left) + calculateTotalSum(root->right);
    }

    long long calculateMaxProduct(TreeNode* root) {
        if (!root) return 0;

        long long currSum =
            root->val +
            calculateMaxProduct(root->left) +
            calculateMaxProduct(root->right);

        maxProd = max(maxProd, currSum * (totalSum - currSum));
        return currSum;
    }

    int maxProduct(TreeNode* root) {
        if (!root) return 0;

        totalSum = calculateTotalSum(root);
        maxProd = 0;

        calculateMaxProduct(root);

        return maxProd % (int)(1e9 + 7);
    }
};

/*
Usage:
Solution obj;
int result = obj.maxProduct(root);
*/
