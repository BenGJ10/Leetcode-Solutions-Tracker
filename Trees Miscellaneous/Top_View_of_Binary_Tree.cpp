/*
Top View of Binary Tree (GeeksforGeeks)
Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

------------------------------------------------------
Problem Summary:
Return the list of nodes visible from the **top view** of a binary tree,
from **leftmost horizontal distance** to **rightmost**.

Definition:
- The top view includes the first node encountered at each horizontal
  distance (HD) from the root when looking from above.

------------------------------------------------------
Approach:
We use **level-order BFS** while tracking each node’s horizontal distance.

1. **Horizontal Distance (HD):**
   - Root node has HD = 0.
   - Left child → HD = parent HD - 1.
   - Right child → HD = parent HD + 1.

2. **Algorithm Steps:**
   - Initialize a `queue<pair<Node*, int>>` for BFS with {root, 0}.
   - Maintain a `map<int,int>` to store the first node value for each HD.
   - For each popped node:
        • If HD not present in map, store `node->data`.
        • Push left child with HD - 1.
        • Push right child with HD + 1.
   - After traversal, iterate over the map (keys auto-sorted) to build result.

- Time Complexity: **O(N log N)**  
  N nodes, each insertion in map costs O(log N).
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
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;

        queue<pair<Node*, int>> q;     // Node with its HD
        map<int, int> hdMap;           // HD -> node->data
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();

            // Store the first node encountered at each HD
            if (hdMap.find(hd) == hdMap.end())
                hdMap[hd] = node->data;

            if (node->left)  q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        // Extract values in sorted order of HD
        for (auto &entry : hdMap)
            result.push_back(entry.second);

        return result;
    }
};