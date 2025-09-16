/*
Bottom View of Binary Tree (GeeksforGeeks)
Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

------------------------------------------------------
Problem Summary:
Return the list of nodes visible from the **bottom view** of a binary tree,
from **leftmost horizontal distance** to **rightmost**.

Definition:
- The bottom view contains the **last (deepest) node** encountered at each
  horizontal distance (HD) when the tree is viewed from below.

------------------------------------------------------
Approach:
Use **level-order BFS** while tracking horizontal distance.

1. **Horizontal Distance (HD):**
   - Root node has HD = 0.
   - Left child → HD = parent HD - 1.
   - Right child → HD = parent HD + 1.

2. **Algorithm Steps:**
   - Initialize a `queue<pair<Node*, int>>` with {root, 0}.
   - Maintain a `map<int,int>` to store the most recent node value for each HD.
   - During BFS:
        • For each node, overwrite `map[hd]` with `node->data` 
          (ensuring the last node at that HD is stored).
        • Push left child with HD - 1.
        • Push right child with HD + 1.
   - After traversal, iterate over the map to collect node values.

- Time Complexity: **O(N log N)**  
  N nodes, each map update/find is O(log N).
- Space Complexity: **O(N)**  
  For queue and map.

------------------------------------------------------
*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> result;
        if (!root) return result;

        queue<pair<Node*, int>> q;   // Node with its HD
        map<int, int> hdMap;         // HD -> node->data
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();

            // Overwrite to ensure deepest node at each HD
            hdMap[hd] = node->data;

            if (node->left)  q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto &entry : hdMap)
            result.push_back(entry.second);

        return result;
    }
};
