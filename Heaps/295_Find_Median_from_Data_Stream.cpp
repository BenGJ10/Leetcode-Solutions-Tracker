/*
295. Find Median from Data Stream
Link: https://leetcode.com/problems/find-median-from-data-stream/

------------------------------------------------------
Problem Summary:
Design a data structure that supports:
1. Adding integers from a data stream.
2. Finding the median of all elements so far.

The median:
- If odd number of elements → middle element.
- If even → average of two middle elements.

Example:
Input:
addNum(1)
addNum(2)
findMedian() → 1.5
addNum(3)
findMedian() → 2.0

------------------------------------------------------
Brute Force Approach:
1. Store all numbers in a sorted array or vector.
2. On each insertion, insert at correct position (O(n)).
3. Median is at middle index or average of two middle indices.
- Time Complexity: O(n) per insertion.
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Two Heaps):

Idea:
- Use two heaps to efficiently balance lower and upper halves:
  * Max-heap (`maxHeap`) for smaller half.
  * Min-heap (`minHeap`) for larger half.
- Maintain invariant:
  * `maxHeap.size()` >= `minHeap.size()`
  * All elements in `maxHeap` ≤ all elements in `minHeap`
- On each insertion:
  * Push to `maxHeap`, then move its top to `minHeap` to balance.
  * If `minHeap` grows larger, move its top back to `maxHeap`.

Finding Median:
- If total elements odd → top of `maxHeap`.
- If even → average of tops of both heaps.

- Time Complexity: O(log n) per insertion.
- Space Complexity: O(n) for storing elements.

------------------------------------------------------
*/

#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap; // lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // upper half

    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) 
            return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/*
Usage:
MedianFinder mf;
mf.addNum(1);
mf.addNum(2);
double m1 = mf.findMedian(); // 1.5
mf.addNum(3);
double m2 = mf.findMedian(); // 2.0
*/
