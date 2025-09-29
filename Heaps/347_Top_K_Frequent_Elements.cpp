/*
347. Top K Frequent Elements
Link: https://leetcode.com/problems/top-k-frequent-elements/

------------------------------------------------------
Problem Summary:
Given an integer array `nums` and an integer `k`,
return the `k` most frequent elements in any order.

------------------------------------------------------
Brute Force Approach:
1. Count frequency of each number using a hash map.
2. Sort the unique elements by their frequency in descending order.
3. Take the first `k` elements.
- Time Complexity: O(n log n) for sorting.
- Space Complexity: O(n) for frequency map.

------------------------------------------------------
Optimal Approach (Max-Heap):
Idea:
- Count frequencies with an unordered_map.
- Use a max-heap (priority_queue) storing pairs (frequency, number).
- Extract top `k` elements.

Steps:
1. Traverse `nums` and populate a frequency map.
2. Push {frequency, element} pairs into a max-heap.
3. Pop `k` times to get the most frequent elements.

- Time Complexity: O(n log n)
   * Building frequency map: O(n)
   * Pushing into heap: O(m log m), where m is number of unique elements (≤ n)
   * Extracting k elements: O(k log m)
- Space Complexity: O(n) for the map and heap.

------------------------------------------------------
Alternative (Bucket Sort) – More Optimal:
- Use an array of buckets where index = frequency,
  and each bucket contains elements with that frequency.
- Traverse buckets from high to low until k elements are collected.
- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto &elem: mpp){
            pq.push({elem.second, elem.first});
        }

        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};