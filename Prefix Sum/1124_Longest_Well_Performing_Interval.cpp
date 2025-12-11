/*
1124. Longest Well-Performing Interval
Link: https://leetcode.com/problems/longest-well-performing-interval/

------------------------------------------------------
Problem Summary:
You are given an array `hours` where:
- hours[i] > 8 → tiring day
- hours[i] ≤ 8 → non-tiring day

A **well-performing interval** is one where:
#tiring_days > #non_tiring_days

Return the **length of the longest well-performing interval**.

------------------------------------------------------
Example:
Input:
hours = [9,9,6,0,6,6,9]

Output:
3

Explanation:
Valid longest interval is [9,9,6] or [6,6,9].

------------------------------------------------------
Brute Force Approach:
1. For every subarray, count tiring vs non-tiring days.
2. Check if tiring > non-tiring.

- Time Complexity: O(n²)
- Space Complexity: O(1)

Too slow for large input.

------------------------------------------------------
Optimal Approach (Prefix Sum + HashMap Trick):
Idea:
Transform the array:
- tiring day → +1
- non-tiring day → -1

We want longest subarray where:
prefixSum[j] - prefixSum[i] > 0
→ prefixSum[j] > prefixSum[i]

Key trick:
1. Let `sum` be prefix sum.
2. If `sum > 0`, the whole interval from 0..i is valid → update maxLen = i+1.
3. Otherwise, look for earliest prefix where:
    prefix[i] = sum - 1
because if:
sum(i) > sum(j) and sum(j) = sum(i) - 1 → interval (j+1 ... i) is valid.

Use HashMap:
- Store earliest index for each prefixSum.

Algorithm:
1. Convert hours to +1/-1.
2. Maintain prefix sum.
3. If sum > 0 → interval is i+1.
4. Else:
   - If (sum - 1) exists in map → update maxLen using earliest occurrence.
5. Store earliest index of each prefix sum in map.

- Time Complexity: O(n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int maxLen = 0;
        unordered_map<int, int> mpp;  // prefix sum → earliest index
        int sum = 0;

        for (int i = 0; i < hours.size(); i++) {
            sum += (hours[i] > 8 ? 1 : -1);

            // Store earliest occurrence of prefix sum
            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }

            if (sum > 0) {
                // entire interval [0..i] is well-performing
                maxLen = i + 1;
            } 
            else if (mpp.find(sum - 1) != mpp.end()) {
                // find longest interval ending at i
                maxLen = max(maxLen, i - mpp[sum - 1]);
            }
        }

        return maxLen;
    }
};

/*
Usage:
Solution obj;
int result = obj.longestWPI(hours);
*/
