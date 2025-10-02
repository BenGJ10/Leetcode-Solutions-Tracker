/*
703. Kth Largest Element in a Stream
Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

------------------------------------------------------
Problem Summary:
Design a class `KthLargest` that maintains a stream of numbers 
and efficiently returns the kth largest element at any point.

Class should support:
    - Constructor: `KthLargest(int k, vector<int>& nums)`
    - Method: `int add(int val)` → returns the kth largest element 
      after inserting `val`.

------------------------------------------------------
Brute Force Approach:
1. On each insertion, add the number to an array.
2. Sort the array in descending order.
3. Return the kth largest element.
- Time Complexity: O(n log n) per insertion.
- Space Complexity: O(n).

------------------------------------------------------
Optimal Approach (Min-Heap of Size k):
Idea:
- Maintain a min-heap of size k.
- The smallest element in the heap will always be the kth largest in the stream.
- Push incoming numbers into the heap.
- If size exceeds k, remove the smallest.
- Return heap top (kth largest).

Steps:
1. Initialize heap with at most k elements from nums.
2. For `add(val)`:
   - Push `val` into heap.
   - If heap size > k, pop the top.
   - Return heap.top() (kth largest).

- Time Complexity:
    * Constructor: O(n log k) for inserting nums.
    * add(): O(log k) for insertion/deletion.
- Space Complexity: O(k).

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    int k;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
};

/*
Usage:
KthLargest* obj = new KthLargest(k, nums);
int res = obj->add(val);
*/
