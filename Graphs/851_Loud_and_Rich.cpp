/*
851. Loud and Rich
Link: https://leetcode.com/problems/loud-and-rich/

------------------------------------------------------
Problem Summary:
You are given:
- A list `richer`, where richer[i] = [a, b]
  means person `a` is richer than person `b`.
- An array `quiet` where quiet[i] represents how quiet person `i` is.

You must return an array `answer` such that:
`answer[i]` = the person who is at least as rich as `i` AND is the quietest among all such people.

------------------------------------------------------
Example:
Input:
richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
quiet  =  [3,2,5,4,6,1,7,0]

Output:
[5,5,2,5,4,5,6,7]

Explanation:
- Person 0 is poorer than 1 → poorer than 2 → poorer than 3 → ...  
  Quietest among all reachable richer people is 5.

------------------------------------------------------
Brute Force Approach:
1. For each person i:
   - Run DFS to find all richer people.
   - Among them, pick the quietest.
2. Store results.

- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Topological Sort + Propagation):
Idea:
- Richer relationships form a DAG.
- If `a` is richer than `b`, then when processing `a`, 
  we can propagate the quietest-rich person to `b`.

Steps:
1. Build adjacency list where edges `a -> b` mean a is richer than b.
2. Compute indegrees for topological ordering.
3. Initialize `answer[i] = i` (quietest person richer than themselves is themselves).
4. Use Kahn’s BFS:
   - Process richer people first.
   - For each richer → poorer edge:
       - If quiet[answer[richer]] < quiet[answer[poor]]:
             update answer[poor] = answer[richer]
       - Reduce indegree; push to queue when it becomes 0.
5. After BFS, answer[i] holds the quietest person at least as rich as `i`.

- Time Complexity: O(n + edges)
- Space Complexity: O(n + edges)

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> indegrees(n, 0);

        // Build graph: richer → poorer
        for (auto &r : richer) {
            int rich = r[0];
            int poor = r[1];
            adj[rich].push_back(poor);
            indegrees[poor]++;
        }

        // Initially, each person's quietest richer person is themselves
        vector<int> answer(n);
        for (int i = 0; i < n; i++) 
            answer[i] = i;

        // Topological BFS
        queue<int> q;
        for (int i = 0; i < n; i++) 
            if (indegrees[i] == 0) q.push(i);

        while (!q.empty()) {
            int rich = q.front(); 
            q.pop();

            for (int poor : adj[rich]) {
                // Propagate quietest richer person
                if (quiet[answer[rich]] < quiet[answer[poor]]) {
                    answer[poor] = answer[rich];
                }

                indegrees[poor]--;
                if (indegrees[poor] == 0) {
                    q.push(poor);
                }
            }
        }

        return answer;
    }
};

/*
Usage:
Solution obj;
vector<int> result = obj.loudAndRich(richer, quiet);
*/

