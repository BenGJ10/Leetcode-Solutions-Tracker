/*
863. All Nodes Distance K in Binary Tree
Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

------------------------------------------------------
Problem Summary:
Given the root of a binary tree, a target node, and an integer k,
return all node values that are exactly distance k edges away from
the target node.

- The binary tree is not necessarily a BST.
- Distance is measured as number of edges in the shortest path.

------------------------------------------------------
Optimal BFS + Parent Tracking Approach:
1. **Record Parent Pointers**  
   - Perform a BFS from the root and build a map `parent[child] = parentNode`
     so that we can move upward as well as downward.

2. **BFS Outward from Target**  
   - Start a queue from the `target` node.
   - Maintain a visited set to avoid revisiting nodes.
   - For each BFS level, expand to:
       * left child
       * right child
       * parent node
   - Stop expanding when current level == k.

3. The queue now contains all nodes at distance k.

- Time Complexity: **O(n)**  
  Each node is visited at most once (parent marking + BFS).
- Space Complexity: **O(n)**  
  Extra maps for parent tracking and visited nodes.

------------------------------------------------------
*/

#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void markParents(unordered_map<TreeNode*, TreeNode*> &track, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left != nullptr){
                track[node->left] = node;
                q.push(node->left);
            }
            if(node->right != nullptr){
                track[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> trackParents;
        markParents(trackParents, root); 
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        int level = 0;
        q.push(target);
        vis[target] = true;

        while(!q.empty()){
            int size = q.size();
            if(level == k)  break;
            level++;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr && !vis[node->left]){
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if(node->right != nullptr && !vis[node->right]){
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if(!vis[trackParents[node]] && trackParents[node]){
                    vis[trackParents[node]] = true;
                    q.push(trackParents[node]);
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* node = q.front();
            result.push_back(node->val);
            q.pop();
        }   
        return result;
    }
};