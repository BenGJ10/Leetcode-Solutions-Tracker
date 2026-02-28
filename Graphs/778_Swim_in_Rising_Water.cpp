/*
778. Swim in Rising Water
Link: https://leetcode.com/problems/swim-in-rising-water/

------------------------------------------------------
Problem Summary:
You are given an `n x n` grid where:
- grid[i][j] represents the elevation at cell (i, j).
- Water level rises over time.
- At time `t`, you can enter a cell if grid[i][j] <= t.

You start at (0,0) and want to reach (n-1,n-1).
Return the minimum time `t` such that you can reach the destination.

------------------------------------------------------
Example:
Input:
grid = [[0,2],[1,3]]

Output:
3

Explanation:
You must wait until time = 3 to reach bottom-right.

------------------------------------------------------
Brute Force Approach:
Try increasing time from 0 upward and check via BFS
whether destination is reachable.

Time Complexity: O(n² * maxHeight)
Too slow.

------------------------------------------------------
Optimal Approach (Dijkstra / Minimum Maximum Path):
Key Insight:
This is a **minimum maximum path problem**.

We want to minimize:
    max elevation along the chosen path

So instead of summing weights, we take:
    newTime = max(currentTime, grid[newCell])

Use a **min-heap (priority_queue)**:
- Always process the cell with minimum current time.
- Update neighbors if we find a better (smaller max elevation) path.

------------------------------------------------------
Algorithm:
1. Use a min-heap storing:
      {time, {row, col}}
2. Maintain `dist[][]` storing minimum time needed to reach each cell.
3. Start from (0,0).
4. For each neighbor:
      newTime = max(currentTime, grid[newRow][newCol])
      If newTime < dist[newRow][newCol]:
          update and push to heap
5. Stop when reaching bottom-right.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n² log n)
- Space Complexity: O(n²)

------------------------------------------------------
*/

#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        int dirs[5] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {

            auto [time, cell] = pq.top();
            pq.pop();

            auto [row, col] = cell;

            if (row == n - 1 && col == n - 1)
                return time;

            for (int i = 0; i < 4; i++) {
                int newR = row + dirs[i];
                int newC = col + dirs[i + 1];

                if (newR >= 0 && newC >= 0 && newR < n && newC < n) {

                    int newTime = max(time, grid[newR][newC]);

                    if (newTime < dist[newR][newC]) {
                        dist[newR][newC] = newTime;
                        pq.push({newTime, {newR, newC}});
                    }
                }
            }
        }

        return -1;
    }
};

/*
Usage:
Solution obj;
int result = obj.swimInWater(grid);
*/