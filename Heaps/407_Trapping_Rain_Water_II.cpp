/*
407. Trapping Rain Water II
Link: https://leetcode.com/problems/trapping-rain-water-ii/

------------------------------------------------------
Problem Summary:
You are given a 2D height map `heights` where each cell represents elevation.
Rainwater can be trapped inside the low-height regions surrounded by
higher walls (similar to the 1D trapping rain water, but extended to 2D).

Return the **total amount of water** that can be trapped.

------------------------------------------------------
Example:
Input:
heights = [
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Output:
4

Explanation:
Water accumulates at low points: total = 4 units.

------------------------------------------------------
Brute Force Approach:
1. For each cell, try to compute the minimum height of boundary walls around it.
2. Water trapped = min_boundary_height - cell_height (if positive).
3. Repeat for all cells.

- Time Complexity: O(n² * max_height)
- Space Complexity: O(n*m)

This is too slow.

------------------------------------------------------
Optimal Approach (Min-Heap BFS / Dijkstra-like Flooding):
Idea:
- Same logic as filling a container from the outside inward.
- The boundary cells determine the initial water height limit.
- Always expand from the **lowest boundary** because it limits water trapping.
- Use a **min-heap** to simulate this "filling from the lowest point".

Steps:
1. Push all boundary cells into a min-heap and mark them visited.
2. Pop the lowest-height cell.
3. For each neighbor:
   - If unvisited:
     - Water trapped = max(0, current_height - neighbor_height)
     - Push neighbor into heap with updated height:
         max(current_height, neighbor_height)
     - Mark visited.
4. Continue until heap empty.
5. Sum all trapped water.

This ensures we always expand correctly controlled by the minimum height barrier.

- Time Complexity: O(n*m * log(n*m))
- Space Complexity: O(n*m)

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Add left and right boundaries
        for (int i = 0; i < n; i++) {
            vis[i][0] = true;
            pq.push({heights[i][0], {i, 0}});
            vis[i][m - 1] = true;
            pq.push({heights[i][m - 1], {i, m - 1}});
        }

        // Add top and bottom boundaries
        for (int i = 0; i < m; i++) {
            vis[0][i] = true;
            pq.push({heights[0][i], {0, i}});
            vis[n - 1][i] = true;
            pq.push({heights[n - 1][i], {n - 1, i}});
        }

        int volume = 0;
        int dirs[5] = {0, -1, 0, 1, 0};

        while (!pq.empty()) {
            int height = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + dirs[i];
                int newCol = col + dirs[i + 1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    !vis[newRow][newCol]) 
                {
                    volume += max(0, height - heights[newRow][newCol]);
                    pq.push({max(height, heights[newRow][newCol]), {newRow, newCol}});
                    vis[newRow][newCol] = true;
                }
            }
        }

        return volume;
    }
};

/*
Usage:
Solution obj;
int result = obj.trapRainWater(heights);
*/
