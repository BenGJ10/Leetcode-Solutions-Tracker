/*
1046. Last Stone Weight
Link: https://leetcode.com/problems/last-stone-weight/

------------------------------------------------------
Problem Summary:
You are given an array `stones` where each element represents
the weight of a stone. Every turn:
  1. Take the two heaviest stones and smash them together.
  2. If their weights are equal, both are destroyed.
  3. If not equal, the smaller one is destroyed and the larger one
     has new weight = difference of the two.
Repeat until at most one stone remains.
Return the weight of the last remaining stone, or 0 if none.

------------------------------------------------------
Brute Force Approach (Sort Each Time):
1. Sort the array descending.
2. Take last two stones, smash them, insert the result back, repeat.
- Time Complexity: O(n^2 log n) (sorting repeatedly).
- Space Complexity: O(1) or O(n) depending on sorting method.

------------------------------------------------------
Optimal Approach (Max-Heap / Priority Queue):
Idea:
- A max-heap efficiently gives the two largest stones.
- Repeatedly pop the two largest and push back their difference if > 0.

Steps:
1. Push all stone weights into a max-heap.
2. While heap size > 1:
    - Pop top two elements.
    - If their difference > 0, push it back.
3. If heap is empty, return 0; else return top.

- Time Complexity: O(n log n)
  (Building heap O(n), each pop/push O(log n), up to n operations)
- Space Complexity: O(n) for the heap.

------------------------------------------------------
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            if (first != second) pq.push(first - second);
        }
        return pq.empty() ? 0 : pq.top();
    }
};


