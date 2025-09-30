/*
973. K Closest Points to Origin
Link: https://leetcode.com/problems/k-closest-points-to-origin/

------------------------------------------------------
Problem Summary:
You are given an array of points where points[i] = [xi, yi]
represents a point on the X-Y plane, and an integer k.
Return the k closest points to the origin (0,0).
The answer can be returned in any order.

------------------------------------------------------
Brute Force Approach:
1. Calculate Euclidean distance for each point.
2. Sort points by distance.
3. Return the first k points.
- Time Complexity: O(n log n) due to sorting.
- Space Complexity: O(n).

------------------------------------------------------
Optimal Approach (Max-Heap):
Idea:
- Use squared distance (avoids floating-point computation).
- Maintain a max-heap of size k with pairs {distance, point}.
- If heap size exceeds k, pop the farthest point.
- After processing all points, heap contains the k closest.

Steps:
1. Compute squared distance for each point.
2. Push into max-heap; if size > k, pop the farthest.
3. Extract points from heap.

- Time Complexity: O(n log k)
   * Each insertion/removal in heap costs log k.
   * Done n times → O(n log k).
- Space Complexity: O(k) for heap + O(k) for result.

------------------------------------------------------
Alternative (Quickselect) – More Optimal:
- Partition-based selection (like QuickSort).
- Expected Time: O(n), Worst-case O(n²).
- Space Complexity: O(1).

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq; // {distance, {x, y}}
        for (auto &p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            pq.push({dist, {p[0], p[1]}});
            
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            auto top = pq.top(); 
            pq.pop();
            result.push_back({top.second.first, top.second.second});
        }
        return result;
    }
};

