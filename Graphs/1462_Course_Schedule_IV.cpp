/*
1462. Course Schedule IV
Link: https://leetcode.com/problems/course-schedule-iv/

------------------------------------------------------
Problem Summary:
You are given:
- `numCourses` labeled from 0 to numCourses-1
- A list of prerequisite pairs: prerequisites[i] = [a, b]
  meaning course `a` must be taken BEFORE course `b`
- A list of queries: queries[i] = [u, v]
  asking: "Is course u a prerequisite of course v?"

You must return a vector<bool> where each element is TRUE/FALSE for each query.

------------------------------------------------------
Example:
Input:
numCourses = 2
prerequisites = [[1,0]]
queries = [[0,1], [1,0]]

Output:
[false, true]

Explanation:
1 → 0, so 1 is a prerequisite of 0.

------------------------------------------------------
Brute Force Approach:
For every query:
  - Try a DFS from u to see if we reach v.

- Time Complexity: O(q * (n + p))
- Space Complexity: O(n)

Very inefficient when q is large.

------------------------------------------------------
Optimal Approach (Topological Sort + Transitive Closure):
Idea:
- Build the adjacency list for course prerequisites.
- Using indegrees, perform **Kahn’s Algorithm** (BFS Topological Sort).
- As we process a node:
  - Mark its direct child as reachable.
  - Additionally, if some other node i can reach the current node,
    then i can also reach all of its children.
  - Propagate reachability using a boolean matrix.

Steps:
1. Build adjacency list and indegree array.
2. Initialize a `reachable[n][n]` boolean matrix.
3. Push all nodes with indegree = 0 into queue.
4. BFS:
   - For each neighbor:
     - Mark reachable[node][neigh] = true
     - For all i:
         If reachable[i][node] is true:
             reachable[i][neigh] = true
     - Decrease indegree; if indegree becomes 0, enqueue it.
5. For each query [u,v], answer reachable[u][v].

- Time Complexity: O(n³) maximum (due to propagation in worst case)
- Space Complexity: O(n²)

Efficient enough for constraints (n ≤ 100).

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            indegrees[p[1]]++;
        }

        // Matrix to track reachability
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        queue<int> q;

        // Start with nodes having indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) q.push(i);
        }

        // Topological BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {
                // Direct prerequisite
                reachable[node][neigh] = true;

                // Propagate reachability
                for (int i = 0; i < numCourses; i++) {
                    if (reachable[i][node]) {
                        reachable[i][neigh] = true;
                    }
                }

                indegrees[neigh]--;
                if (indegrees[neigh] == 0) q.push(neigh);
            }
        }

        // Answer queries
        vector<bool> result;
        for (auto &qr : queries) {
            result.push_back(reachable[qr[0]][qr[1]]);
        }

        return result;
    }
};

/*
Usage:
Solution obj;
vector<bool> result = obj.checkIfPrerequisite(numCourses, prerequisites, queries);
*/

