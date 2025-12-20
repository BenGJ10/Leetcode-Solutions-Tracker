/*
2101. Detonate the Maximum Bombs
Link: https://leetcode.com/problems/detonate-the-maximum-bombs/

------------------------------------------------------
Problem Summary:
You are given `n` bombs, where each bomb is described by:
    bombs[i] = [xi, yi, ri]
representing the bomb’s location `(xi, yi)` and explosion radius `ri`.

When a bomb explodes, it can trigger **other bombs** within its radius,
causing a chain reaction.

Your task is to determine the **maximum number of bombs** that can be detonated
if you choose exactly one bomb to start with.

------------------------------------------------------
Example:
Input:
bombs = [[2,1,3],[6,1,4]]

Output:
2

Explanation:
- Bomb 0 can detonate bomb 1.
- Total detonations = 2.

------------------------------------------------------
Brute Force Approach:
1. For each bomb, simulate the chain reaction using DFS/BFS.
2. Count how many bombs explode.
3. Take the maximum across all starting bombs.

- Time Complexity: O(n³)
- Space Complexity: O(n²)

------------------------------------------------------
Optimal Approach (Graph + DFS):
Idea:
- Treat each bomb as a node in a **directed graph**.
- Add a directed edge `i → j` if bomb `j` lies within the explosion radius of bomb `i`.
- For each bomb:
  - Run DFS to count how many bombs can be reached (detonated).
- Return the maximum count.

Key Observation:
Bomb `i` can detonate bomb `j` if:
    (xi - xj)² + (yi - yj)² ≤ ri²

Steps:
1. Build adjacency list using distance check.
2. For each bomb:
   - Run DFS with a fresh visited array.
   - Track number of bombs detonated.
3. Return the maximum count.

- Time Complexity: O(n² + n(n + e)) ≈ O(n³) worst case
- Space Complexity: O(n²)

------------------------------------------------------
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &count) {
        vis[node] = 1;
        count++;

        for (auto &neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour, adj, vis, count);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        // Build graph
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = x1 - x2;
                long long dy = y1 - y2;

                if (dx * dx + dy * dy <= r1 * r1) {
                    adj[i].push_back(j);
                }
            }
        }

        int maxBombs = 0;

        // Try detonating each bomb
        for (int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            int count = 0;
            dfs(i, adj, vis, count);
            maxBombs = max(maxBombs, count);
        }

        return maxBombs;
    }
};

/*
Usage:
Solution obj;
int result = obj.maximumDetonation(bombs);
*/
