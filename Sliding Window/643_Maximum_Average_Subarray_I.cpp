/*
643. Maximum Average Subarray I
Link: https://leetcode.com/problems/maximum-average-subarray-i/

------------------------------------------------------
Problem Summary:
You are given an integer array `nums` and an integer `k`.
Your task is to find the **maximum average** of any contiguous subarray of length `k`.

Return the maximum average as a double.

------------------------------------------------------
Brute Force Approach:
1. For each index i, compute the sum of the subarray nums[i : i+k].
2. Track the maximum sum encountered.
3. Convert maximum sum to average by dividing by k.

- Time Complexity: O(n * k)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Sliding Window):
Idea:
- Use a sliding window of size `k`.
- Compute the sum of the first window.
- Then slide the window:
  - Add the incoming value.
  - Subtract the outgoing value.
- Track the maximum window sum.

Steps:
1. Compute initial sum of first `k` elements.
2. For each index from `k` to `n-1`:
   - Update current window sum.
   - Update max sum.
3. Return `maxAvg / k`.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = 0, maxAvg = 0;

        for (int i = 0; i < k; i++) 
            avg += nums[i];
        
        maxAvg = avg;

        for (int i = k; i < n; i++) {
            avg += nums[i] - nums[i - k];
            maxAvg = max(maxAvg, avg);
        }

        return maxAvg / k;
    }
};

/*
Usage:
Solution obj;
double result = obj.findMaxAverage(nums, k);
*/
