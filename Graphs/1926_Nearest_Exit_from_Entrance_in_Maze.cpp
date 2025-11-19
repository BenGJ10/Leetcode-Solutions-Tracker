/*
1926. Nearest Exit from Entrance in Maze
Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

------------------------------------------------------
Problem Summary:
You are given an `n x m` maze represented by a 2D grid of characters.
- `'+'` represents a wall.
- `'.'` represents an empty cell.
You are also given an `entrance` position = `[row, col]` in the maze, where you start.

Your goal is to find the **nearest exit** in the maze, defined as:
- Any empty cell on the boundary (edge of the maze) that is **not** the entrance itself.

Return the **minimum number of steps** required to reach the nearest exit.
If no exit exists, return `-1`.

------------------------------------------------------
Example 1:
Input:
maze = [["+","+",".","+"],
        [".",".",".","+"],
        ["+","+","+","."]]
entrance = [1,2]

Output:
1

Explanation:
The nearest exit is at [0,2].

Example 2:
Input:
maze = [["+","+","+"],
        [".",".","."],
        ["+","+","+"]]
entrance = [1,0]

Output:
2

Explanation:
From [1,0] → [1,1] → [1,2]. Exit at [1,2].

------------------------------------------------------
Brute Force Approach:
1. Perform DFS from the entrance exploring all possible paths.
2. Track minimum distance to any boundary cell.
3. Return the minimum distance found.
- Time Complexity: O(4^(n*m))
- Space Complexity: O(n*m) recursion depth.

------------------------------------------------------
Optimal Approach (BFS - Shortest Path in Unweighted Grid):
Idea:
Since each move costs 1 step, use **Breadth-First Search (BFS)** 
to find the shortest path to the nearest exit.

Steps:
1. Initialize a queue with the entrance cell and mark it as visited.
2. For each position, explore its 4 adjacent cells (up, down, left, right).
3. If the new cell:
   - Is inside the maze,
   - Not visited,
   - Not a wall (`'+'`),
   - And lies on the boundary (not entrance) → return `steps + 1`.
4. If BFS finishes without finding any exit, return `-1`.

- Time Complexity: O(n * m)
- Space Complexity: O(n * m)

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.push({{entrance[0], entrance[1]}, 0});
        vis[entrance[0]][entrance[1]] = true;

        int dirs[5] = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + dirs[i];
                int newCol = col + dirs[i + 1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    if (maze[newRow][newCol] == '+' || vis[newRow][newCol]) continue;
                    if (newRow == 0 || newRow == n - 1 || newCol == 0 || newCol == m - 1)
                        return steps + 1;

                    vis[newRow][newCol] = true;
                    q.push({{newRow, newCol}, steps + 1});
                }
            }
        }
        return -1;
    }
};

/*
Usage:
Solution obj;
int result = obj.nearestExit(maze, entrance);
*/
