/*
1143. Longest Common Subsequence
Link: https://leetcode.com/problems/longest-common-subsequence/

------------------------------------------------------
Problem Summary:
Given two strings `text1` and `text2`, return the length of their
**Longest Common Subsequence (LCS)**.

A subsequence is a sequence derived from another string by deleting
some or no characters **without changing the order**.

------------------------------------------------------
Example 1:
Input:
text1 = "abcde"
text2 = "ace"

Output:
3

Explanation:
The LCS is "ace".

------------------------------------------------------
Example 2:
Input:
text1 = "abc"
text2 = "abc"

Output:
3

------------------------------------------------------
Example 3:
Input:
text1 = "abc"
text2 = "def"

Output:
0

------------------------------------------------------
Brute Force Approach:
Generate all subsequences of one string and check whether they
exist in the other string.

- Number of subsequences = 2ⁿ
- Checking each takes O(m)

- Time Complexity: O(2ⁿ * m)
- Space Complexity: O(n)

Clearly inefficient.

------------------------------------------------------
Optimal Approach (Dynamic Programming):
Idea:
Let dp[i][j] represent the length of LCS between:
- First `i` characters of text1
- First `j` characters of text2

Transition:
If characters match:
    dp[i][j] = 1 + dp[i-1][j-1]

Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Base Case:
If either string is empty → LCS = 0

Steps:
1. Create a DP table of size (m+1) x (n+1).
2. Initialize first row and column with 0.
3. Fill table using transitions.
4. Answer is dp[m][n].

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(m * n)
- Space Complexity: O(m * n)
(Can be optimized to O(min(m,n)) using rolling arrays.)

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    // Memoization (Top-Down)
    int LCS(string &text1, string &text2, int m, int n) {
        if (m < 0 || n < 0) return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (text1[m] == text2[n])
            return dp[m][n] = 1 + LCS(text1, text2, m - 1, n - 1);

        return dp[m][n] = max(
            LCS(text1, text2, m - 1, n),
            LCS(text1, text2, m, n - 1)
        );
    }

    // Tabulation (Bottom-Up)
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();

        dp.assign(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) dp[i][0] = 0;
        for (int j = 0; j <= n; j++) dp[0][j] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
    }
};

/*
Usage:
Solution obj;
int result = obj.longestCommonSubsequence(text1, text2);
*/
