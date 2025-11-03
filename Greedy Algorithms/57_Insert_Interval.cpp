/*
57. Insert Interval
Link: https://leetcode.com/problems/insert-interval/

------------------------------------------------------
Problem Summary:
You are given an array of non-overlapping intervals `intervals` 
where each interval is represented as `[start, end]` and is sorted in ascending order by `start`.
You are also given a new interval `newInterval = [start, end]`.

Insert `newInterval` into `intervals` such that:
- The intervals remain sorted by their start times.
- The intervals remain non-overlapping (merge if necessary).

Return the resulting list of intervals after insertion.

------------------------------------------------------
Example 1:
Input:
intervals = [[1,3],[6,9]]
newInterval = [2,5]

Output:
[[1,5],[6,9]]

Explanation:
- [1,3] overlaps with [2,5], merge → [1,5]
- [6,9] comes after and doesn’t overlap.

Example 2:
Input:
intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]

Output:
[[1,2],[3,10],[12,16]]

Explanation:
- [3,5],[6,7],[8,10] all overlap with [4,8], merged into [3,10].

------------------------------------------------------
Brute Force Approach:
1. Insert `newInterval` into the correct position to maintain sorted order.
2. Sort all intervals again.
3. Merge overlapping intervals using a merge-intervals approach.

- Time Complexity: O(n log n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (One-pass Merge):
Idea:
Since intervals are already sorted and non-overlapping:
1. Add all intervals that come **before** `newInterval` (no overlap).
2. Merge all intervals that **overlap** with `newInterval`.
3. Add all intervals that come **after** `newInterval`.

Steps:
1. Initialize `result` to store final intervals.
2. Traverse `intervals`:
   - If `intervals[i].end < newInterval.start`, push to result.
   - If `intervals[i].start <= newInterval.end`, merge with newInterval.
   - Otherwise, break merge phase and push newInterval, then remaining ones.
3. Return `result`.

- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> result;
        int i = 0;

        // Step 1: Add all intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // Step 3: Add remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

/*
Usage:
Solution obj;
vector<vector<int>> result = obj.insert(intervals, newInterval);
*/
