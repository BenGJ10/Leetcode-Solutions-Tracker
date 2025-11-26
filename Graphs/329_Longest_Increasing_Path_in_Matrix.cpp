/*
329. Longest Increasing Path in a Matrix
Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

------------------------------------------------------
Problem Summary:
You are given an `n x m` matrix of integers.  
Your task is to find the **length of the longest strictly increasing path**.

Rules:
- From each cell `(i, j)`, you may move in 4 directions:
  up, down, left, right.
- You may only move to a cell with a **strictly greater** value.
- Return the maximum path length.

------------------------------------------------------
Example:
Input:
matrix = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]

Output:
4

Explanation:
The longest increasing path is: 1 → 2 → 6 → 9

------------------------------------------------------
Brute Force Approach (DFS on each cell):
1. For each cell, DFS explore all valid increasing paths.
2. Track the longest path using memoization.

- Time Complexity: O(n*m)
- Space Complexity: O(n*m) for recursion + memo.

------------------------------------------------------
Optimal Approach (Topological Sort on DAG):

Idea:
- Treat the matrix as a **Directed Acyclic Graph (DAG)**:
  - Each cell points to its neighbors with larger values.
- Compute **indegree** for each node (count incoming edges).
- Cells with indegree = 0 start the longest path.
- Use **Kahn’s Algorithm** (topological BFS):
  - Each BFS layer corresponds to one more step in the increasing path.
- The number of BFS layers = longest increasing path length.

Steps:
1. Compute indegree of every cell by checking neighbors with greater value.
2. Push all indegree-0 cells into a queue.
3. BFS level by level:
   - For every outgoing edge, reduce indegree.
   - If indegree becomes 0, push into queue.
4. Count BFS layers → that is the longest increasing path.

- Time Complexity: O(n*m)
- Space Complexity: O(n*m)

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> indegree(n, vector<int> (m, 0));
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(auto [row, col]: dirs){
                    int newRow = i + row, newCol = j + col;
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                    matrix[newRow][newCol] > matrix[i][j]){
                        indegree[newRow][newCol]++;
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(indegree[i][j] == 0) q.push({i, j});
            }
        }

        int pathLength = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [i, j] = q.front(); q.pop();
                for(auto [row, col]: dirs){
                    int newRow = row + i, newCol = col + j;
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    matrix[newRow][newCol] > matrix[i][j]){
                        indegree[newRow][newCol]--;
                        if(indegree[newRow][newCol] == 0)   q.push({newRow, newCol});
                    }
                }
            }
            pathLength++;
        }
        return pathLength;
    }
};

/*
Usage:
Solution obj;
int result = obj.longestIncreasingPath(matrix);
*/
