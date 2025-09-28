/*
215. Kth Largest Element in an Array  
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

------------------------------------------------------
Problem Summary:
Given an integer array `nums` and an integer `k`,
return the kth largest element in the array.
Note: It is the kth largest *element*, not the kth distinct element.

------------------------------------------------------
Brute Force Approach (Sort Descending):
1. Sort the array in descending order.
2. Return nums[k-1].
- Time Complexity: O(n log n)
- Space Complexity: O(1) if sorting in-place.

------------------------------------------------------
Optimal Approach (Max-Heap / Priority Queue):
Idea:
- Build a max-heap of all elements.
- Pop the largest element k-1 times.
- The element at the top is the kth largest.

Steps:
1. Push all elements into a max-heap.
2. Pop the heap k-1 times.
3. Return the top element.

- Time Complexity: O(n + k log n) ≈ O(n log n)  
  (heap construction O(n), each pop O(log n))
- Space Complexity: O(n) for the heap.
------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; // max-heap
        for (int num : nums) {
            pq.push(num);
        }
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
