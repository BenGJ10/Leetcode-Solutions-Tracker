/*
2477. Minimum Fuel Cost to Report to the Capital
Link: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

------------------------------------------------------
Problem Summary:
There are `n` cities connected by `n-1` roads forming a tree.
City `0` is the capital.

Each city has **one representative** who must travel to the capital.
A car:
- Can carry at most `seats` people.
- Consumes **1 unit of fuel per road traveled**, regardless of passengers.

Your task is to compute the **minimum fuel cost** required for all representatives
to reach the capital.

------------------------------------------------------
Example:
Input:
roads = [[0,1],[0,2],[0,3]]
seats = 5

Output:
3

Explanation:
Each representative can directly travel to city 0 using 1 unit of fuel.
Total fuel = 3.

------------------------------------------------------
Brute Force Approach:
1. For each city, compute its path to the capital.
2. Simulate car usage independently for each path.

- Time Complexity: O(n²)
- Space Complexity: O(n)

Not efficient and ignores shared rides.

------------------------------------------------------
Optimal Approach (Tree DFS + Greedy Aggregation):
Idea:
- Since the graph is a tree, we can do a **DFS from the capital (0)**.
- Each subtree returns how many people it contains.
- People from child nodes can share cars when traveling upward.
- Fuel needed from a subtree is:
      ceil(people / seats)

Key Observations:
- Every non-capital node contributes fuel based on how many cars are needed
  to move its subtree representatives to its parent.
- Capital itself does not need to move upward.

Steps:
1. Build adjacency list of the tree.
2. DFS from node 0:
   - Each node starts with 1 representative.
   - Collect representatives from children.
3. For each non-root node:
   - Add `ceil(people / seats)` to fuel.
4. Return total fuel.

- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    long long fuel = 0;
    int seats;

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        this->seats = seats;
        int n = roads.size();

        // n roads => n + 1 cities
        vector<vector<int>> adjMat(n + 1);
        for (auto &road : roads) {
            adjMat[road[0]].push_back(road[1]);
            adjMat[road[1]].push_back(road[0]);
        }

        dfs(0, -1, adjMat);
        return fuel;
    }

    int dfs(int currNode, int prevNode, vector<vector<int>> &adjMat) {
        int people = 1; // representative of current city

        for (auto &neighbour : adjMat[currNode]) {
            if (neighbour == prevNode) continue;
            people += dfs(neighbour, currNode, adjMat);
        }

        // Capital does not need to move upward
        if (currNode != 0) {
            fuel += (people + seats - 1) / seats; // ceil division
        }

        return people;
    }
};

/*
Usage:
Solution obj;
long long result = obj.minimumFuelCost(roads, seats);
*/
