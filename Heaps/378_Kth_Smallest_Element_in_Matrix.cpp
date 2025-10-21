/*
378. Kth Smallest Element in a Sorted Matrix
Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

------------------------------------------------------
Problem Summary:
Given an n x n matrix where each row and column is sorted in ascending order,  
return the kth smallest element in the matrix.

Example:
Input:
matrix = [
  [1, 5, 9],
  [10, 11, 13],
  [12, 13, 15]
], k = 8  
Output: 13  
Explanation: The sorted elements are [1, 5, 9, 10, 11, 12, 13, 13, 15].

------------------------------------------------------
Brute Force Approach:
1. Flatten the matrix into a single list.
2. Sort the list.
3. Return the (k-1)th element.
- Time Complexity: O(n^2 log n)
- Space Complexity: O(n^2)

------------------------------------------------------
Optimal Approach (Min Heap / K-Way Merge):

Idea:
- Each row is sorted, so treat each row like a sorted list.
- Use a min heap to simulate merging k sorted lists.
- Push the first element of each row into the heap.
- Repeatedly pop the smallest element and push the next element from the same row.
- The kth popped element is the kth smallest.

Steps:
1. Push the first element of each row into a min heap (value, row, col).
2. Pop the top (smallest element).
3. Push the next element in the same row if it exists.
4. Repeat until k elements have been popped.
5. The last popped element is the answer.

- Time Complexity: O(k * log n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minHeap;

        int n = matrix.size();

        // Step 1: Push first element of each row
        for (int i = 0; i < n; i++) {
            minHeap.push({matrix[i][0], {i, 0}});
        }

        int ans = 0;

        // Step 2: Pop k elements
        while (k--) {
            auto [value, pos] = minHeap.top(); 
            minHeap.pop();

            int row = pos.first, col = pos.second;
            ans = value;

            // Step 3: Push next element in the same row
            if (col + 1 < n)
                minHeap.push({matrix[row][col + 1], {row, col + 1}});
        }

        return ans;
    }
};

/*
Usage:
Solution sol;
vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
int result = sol.kthSmallest(matrix, 8); // Output: 13
*/
