/*
297. Serialize and Deserialize Binary Tree
Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

------------------------------------------------------
Problem Summary:
Implement two functions:
1. **serialize(TreeNode*)** – Convert a binary tree into a single string.
2. **deserialize(string)** – Reconstruct the same binary tree from that string.

The output of `serialize` must be a string that `deserialize` can perfectly rebuild.

------------------------------------------------------
Optimal Level-Order (BFS) Approach:
**Serialization**  
1. Perform a level-order traversal using a queue.
2. Append each node's value to a string separated by commas.
3. For null children, append a sentinel (e.g., "#").
   Example: `1,2,3,#,#,4,5,#,#,#,#,`

**Deserialization**  
1. Use a stringstream to read the serialized data token by token.
2. The first token is the root value.
3. Use a queue to attach left and right children:
   - For each node, read two tokens.
   - If token is "#", that child is null; otherwise create a new node and push to queue.

- Time Complexity: **O(n)**  
  Each node is visited/created once.
- Space Complexity: **O(n)**  
  Queue and output string grow proportionally to number of nodes.

------------------------------------------------------
*/

#include <iostream>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string using BFS
    string serialize(TreeNode* root) {
        if (!root) return "";
        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                result.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            } else {
                result.append("#,");
            }
        }
        return result;
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(const string& data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            // Left child
            if (getline(ss, token, ',')) {
                if (token != "#") {
                    node->left = new TreeNode(stoi(token));
                    q.push(node->left);
                }
            }
            // Right child
            if (getline(ss, token, ',')) {
                if (token != "#") {
                    node->right = new TreeNode(stoi(token));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};

// Usage:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

