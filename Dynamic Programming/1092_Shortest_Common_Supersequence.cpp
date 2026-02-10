/*
1092. Shortest Common Supersequence
Link: https://leetcode.com/problems/shortest-common-supersequence/

------------------------------------------------------
Problem Summary:
Given two strings `str1` and `str2`, return the **shortest string**
that has **both `str1` and `str2` as subsequences**.

If multiple answers exist, return **any** of them.

------------------------------------------------------
Example 1:
Input:
str1 = "abac", str2 = "cab"

Output:
"cabac"

------------------------------------------------------
Example 2:
Input:
str1 = "aaaaaaaa", str2 = "aaaaaaaa"

Output:
"aaaaaaaa"

------------------------------------------------------
Key Insight:
The **Shortest Common Supersequence (SCS)** is closely related to the
**Longest Common Subsequence (LCS)**.

Formula:
Length of SCS = n + m − LCS(str1, str2)

We first compute the LCS DP table, then **reconstruct the SCS** by
traversing the DP table from bottom-right to top-left.

------------------------------------------------------
Optimal Approach (DP + Backtracking):
Idea:
1. Compute LCS DP table.
2. Traverse from `dp[n][m]`:
   - If characters match → include once.
   - Else include the character from the direction with larger DP value.
3. Append remaining characters if one string finishes early.
4. Reverse the built string.

------------------------------------------------------
DP Definition:
dp[i][j] = length of LCS between
           str1[0..i-1] and str2[0..j-1]

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n * m)
- Space Complexity: O(n * m)

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build LCS table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Reconstruct SCS from DP table
        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--; j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            }
            else {
                ans += str2[j - 1];
                j--;
            }
        }

        // Append remaining characters
        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Usage:
Solution obj;
string result = obj.shortestCommonSupersequence(str1, str2);
*/
