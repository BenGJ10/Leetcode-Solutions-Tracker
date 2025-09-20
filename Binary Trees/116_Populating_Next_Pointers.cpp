/*
116. Populating Next Right Pointers in Each Node
Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

------------------------------------------------------
Problem Summary:
Given a **perfect binary tree**, connect each node's `next` pointer to its next right node.  
- If there is no next right node, set `next` to `nullptr`.  
- Initially, all `next` pointers are `nullptr`.  
- The connection should be done **level by level**.

------------------------------------------------------
Optimal BFS Approach (Right-to-Left):
1. Use a queue to perform level-order traversal.
2. For each level:
   - Traverse nodes **from right to left**.
   - Maintain a pointer `nextNode` which points to the previously processed node in that level.
   - Set `curr->next = nextNode` for each node.
3. Enqueue children **right first, then left** so that rightmost nodes are processed first.

- Time Complexity: **O(n)**  
  Each node is visited once.
- Space Complexity: **O(n)**  
  Queue stores nodes of the largest level.

------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* nextNode = nullptr;
            int size = q.size();

            for (int i = size; i > 0; i--) {
                Node* curr = q.front();
                q.pop();
                curr->next = nextNode;
                nextNode = curr;

                if (curr->right) q.push(curr->right);
                if (curr->left)  q.push(curr->left);
            }
        }
        return root;
    }
};
