/*
300. Longest Increasing Subsequence
Link: https://leetcode.com/problems/longest-increasing-subsequence/

------------------------------------------------------
Problem Summary:
Given an integer array `nums`, return the length of the
**longest strictly increasing subsequence**.

A subsequence is derived by deleting some or no elements
without changing the order.

------------------------------------------------------
Example 1:
Input:
nums = [10,9,2,5,3,7,101,18]

Output:
6

Explanation:
One LIS is [2,3,7,101]

------------------------------------------------------
Example 2:
Input:
nums = [0,1,0,3,2,3]

Output:
4

------------------------------------------------------
Example 3:
Input:
nums = [7,7,7,7,7]

Output:
1

------------------------------------------------------
Brute Force Approach:
Generate all subsequences and check which are increasing.

Time Complexity:
O(2^n)

Clearly inefficient.

------------------------------------------------------
Better Approach (DP - O(n²)):

dp[i] = length of LIS ending at index i

For each i:
    dp[i] = 1 + max(dp[j]) where j < i and nums[j] < nums[i]

Time Complexity:
O(n²)

------------------------------------------------------
Optimal Approach (Binary Search + Greedy):

Idea:
Maintain a temporary array `res` where:
- res[k] = smallest possible tail of an increasing subsequence of length k+1

------------------------------------------------------
Key Observations:

1. If current element > last element of res:
   → extend the sequence

2. Else:
   → replace the **first element >= current element**
     using binary search (lower_bound)

Why replace?
→ To keep future possibilities open with smaller values

------------------------------------------------------
Steps:

1. Initialize res with first element
2. Iterate through array:
   - If nums[i] > res.back():
        → push_back
   - Else:
        → find index using lower_bound
        → replace res[index]

3. Length of res = answer

------------------------------------------------------
Important Note:
The `res` array does NOT represent the actual LIS,
but its length is correct.

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(n log n)

Space Complexity:
O(n)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> res;
        res.push_back(nums[0]);

        int len = 1;
        
        for(int i = 1; i < n; i++){

            if(nums[i] > res.back()){
                res.push_back(nums[i]);
                len++;
            }
            else{
                int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[index] = nums[i];
            }
        }

        return len;
    }
};

/*
Usage:
Solution obj;
int result = obj.lengthOfLIS(nums);
*/