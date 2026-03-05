/*
673. Number of Longest Increasing Subsequence
Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

------------------------------------------------------
Problem Summary:
Given an integer array `nums`, return the **number of longest
strictly increasing subsequences**.

A subsequence is strictly increasing if each element
is greater than the previous element.

------------------------------------------------------
Example 1:
Input:
nums = [1,3,5,4,7]

Output:
2

Explanation:
Two LIS exist:
[1,3,4,7]
[1,3,5,7]

------------------------------------------------------
Example 2:
Input:
nums = [2,2,2,2,2]

Output:
5

Explanation:
Each individual element forms an LIS of length 1.

------------------------------------------------------
Brute Force Approach:
Generate all subsequences and track the longest ones.

Number of subsequences = 2^n

Time Complexity: O(2^n)

Not feasible.

------------------------------------------------------
Optimal Approach (Dynamic Programming):
Idea:
We maintain two arrays:

1️⃣ dp[i] → length of LIS ending at index i  
2️⃣ count[i] → number of LIS ending at index i

Transition:
For every pair (j < i):

If nums[j] < nums[i]:

Case 1:
dp[j] + 1 > dp[i]
→ Found longer subsequence
→ Update dp[i]
→ count[i] = count[j]

Case 2:
dp[j] + 1 == dp[i]
→ Found another LIS
→ count[i] += count[j]

Finally:
Find maximum length and sum counts of
all subsequences with that length.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        int maxLen = 1;

        vector<int> dp(n, 1), count(n, 1);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (nums[j] < nums[i]) {

                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }

                    else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen)
                result += count[i];
        }

        return result;
    }
};

/*
Usage:
Solution obj;
int result = obj.findNumberOfLIS(nums);
*/