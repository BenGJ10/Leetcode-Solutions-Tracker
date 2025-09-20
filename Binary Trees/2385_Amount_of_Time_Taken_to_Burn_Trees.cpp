/*
2385. Amount of Time for Binary Tree to Be Infected
Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

------------------------------------------------------
Problem Summary:
You are given the root of a binary tree and the value of a starting node.
A virus starts at the given node and every minute spreads to all directly
connected nodes (left child, right child, and parent).
Return the total minutes required to infect the entire tree.

------------------------------------------------------
Optimal BFS + Parent Mapping Approach:
1. **Map Each Node to Its Parent**
   - Perform a BFS from the root, building a map `parent[child] = parentNode`
     so we can move upward as well as downward.

2. **Multi-Source BFS from Start Node**
   - Begin a BFS from the starting node.
   - Maintain a visited set to avoid re-infecting nodes.
   - At each minute, infect all unvisited neighbors:
       * left child
       * right child
       * parent
   - Increment the time counter after each level where at least one new node is infected.

3. The total time when the queue becomes empty is the answer.

- Time Complexity: **O(n)**  
  Each node is processed once (for parent mapping and infection BFS).
- Space Complexity: **O(n)**  
  Parent map, visited set, and BFS queue all scale with number of nodes.

------------------------------------------------------
*/

#include <iostream>
#include <map>
#include <unordered_set>
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
    // Build parent pointers and locate start node
    TreeNode* findParents(TreeNode* root,
                          unordered_map<TreeNode*, TreeNode*>& parent,
                          int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->val == start) startNode = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return startNode;
    }

    // BFS to count minutes required to infect entire tree
    int burnTrees(TreeNode* startNode,
                  unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(startNode);
        visited.insert(startNode);
        int minutes = 0;

        while (!q.empty()) {
            int sz = q.size();
            bool spread = false;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                    spread = true;
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                    spread = true;
                }
                if (parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                    spread = true;
                }
            }
            if (spread) minutes++;
        }
        return minutes;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = findParents(root, parent, start);
        return burnTrees(startNode, parent);
    }
};
