/*
435. Non-overlapping Intervals
Link: https://leetcode.com/problems/non-overlapping-intervals/

------------------------------------------------------
Problem Summary:
You are given an array of intervals `intervals` where each interval is represented as `[start, end]`.
You need to remove the **minimum number** of intervals so that the remaining intervals 
do not overlap.

Return the **minimum number of intervals** you need to remove.

------------------------------------------------------
Brute Force Approach:
1. Try all possible subsets of intervals that don't overlap.
2. Choose the subset with the maximum count.
3. Return (n - max_count).

- Time Complexity: O(2^n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Greedy Approach:
Idea:
- Similar to "Activity Selection Problem."
- We want to keep as many **non-overlapping intervals** as possible.
- Sort by the **end time** of intervals (earliest finishing first).
- Always pick the interval that ends earliest (greedy choice).

Steps:
1. Sort `intervals` by their end times.
2. Initialize `count = 1` (we can always take the first interval).
3. Track the end of the last selected interval (`lastIndex`).
4. For each next interval:
   - If its start ≥ last selected end → select it, update `lastIndex`.
   - Else → skip (it overlaps).
5. Return `n - count` (number of intervals to remove).

- Time Complexity: O(n log n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(vector<int>& arr1, vector<int>& arr2) {
            return arr1[1] < arr2[1]; // Sort by end time
        }
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Compare());
        int n = intervals.size();
        int count = 1;                  // count of non-overlapping intervals
        int lastIndex = intervals[0][1]; // end of the first selected interval

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastIndex) { // no overlap
                count++;
                lastIndex = intervals[i][1];
            }
        }
        return n - count; // remove all others
    }
};

/*
Usage:
Solution obj;
int result = obj.eraseOverlapIntervals(intervals);
*/
