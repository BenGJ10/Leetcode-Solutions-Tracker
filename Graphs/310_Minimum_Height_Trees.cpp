/*
310. Minimum Height Trees
Link: https://leetcode.com/problems/minimum-height-trees/

------------------------------------------------------
Problem Summary:
Given an undirected tree with `n` nodes labeled from 0 to n-1,
and an array `edges` where edges[i] = [u, v] represents an edge
between nodes u and v,

Return all possible roots of Minimum Height Trees (MHTs).

Height of a tree = number of edges on the longest downward path
between the root and a leaf.

------------------------------------------------------
Example 1:
Input:
n = 4
edges = [[1,0],[1,2],[1,3]]

Output:
[1]

------------------------------------------------------
Example 2:
Input:
n = 6
edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]

Output:
[3,4]

------------------------------------------------------
Brute Force Approach:
For every node:
- Run BFS/DFS to compute height.
- Choose nodes with minimum height.

Time Complexity: O(n²)
Too slow.

------------------------------------------------------
Optimal Approach (Topological Trim — Leaf Removal):
Key Idea:
- The root of Minimum Height Tree must be the "center" of the tree.
- Repeatedly remove leaf nodes (nodes with degree 1).
- Continue until 1 or 2 nodes remain.
- These remaining nodes are the MHT roots.

Steps:
1. Build adjacency list.
2. Compute indegrees (degree of each node).
3. Push all leaf nodes (degree == 1) into queue.
4. Remove leaves layer by layer.
5. Last remaining nodes are answer.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1) return {0};

        vector<vector<int>> adjList(n);
        vector<int> indegrees(n, 0);

        // Build graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);

            indegrees[u]++;
            indegrees[v]++;
        }

        queue<int> q;

        // Push initial leaves
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 1)
                q.push(i);
        }

        vector<int> mhts;

        // Trim leaves layer by layer
        while (!q.empty()) {
            int levelSize = q.size();
            mhts.clear();

            for (int i = 0; i < levelSize; i++) {
                int node = q.front();
                q.pop();

                mhts.push_back(node);

                for (auto &neighbour : adjList[node]) {
                    indegrees[neighbour]--;

                    if (indegrees[neighbour] == 1)
                        q.push(neighbour);
                }
            }
        }

        return mhts;
    }
};

/*
Usage:
Solution obj;
vector<int> result = obj.findMinHeightTrees(n, edges);
*/