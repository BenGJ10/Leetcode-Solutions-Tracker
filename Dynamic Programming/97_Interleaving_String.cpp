/*
97. Interleaving String
Link: https://leetcode.com/problems/interleaving-string/

------------------------------------------------------
Problem Summary:
Given three strings `s1`, `s2`, and `s3`, determine whether
`s3` is formed by an **interleaving** of `s1` and `s2`.

Interleaving means:
- The characters of `s1` and `s2` are merged in order.
- Relative order of characters in each string is preserved.

------------------------------------------------------
Example 1:
Input:
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"

Output:
true

------------------------------------------------------
Example 2:
Input:
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbbaccc"

Output:
false

------------------------------------------------------
Key Observation:
Length condition must hold:
    len(s1) + len(s2) == len(s3)

Otherwise, it is impossible.

------------------------------------------------------
Optimal Approach (Dynamic Programming):
Idea:
Let:
dp[i][j] = true if we can form
           s3[0..i+j-1] using
           s1[0..i-1] and s2[0..j-1]

Transitions:
If s1[i-1] == s3[i+j-1]:
    dp[i][j] |= dp[i-1][j]

If s2[j-1] == s3[i+j-1]:
    dp[i][j] |= dp[i][j-1]

Base Case:
dp[0][0] = true

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n * m)
- Space Complexity: O(n * m)

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<bool>> dp;

    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.length();
        int m = s2.length();

        if (n + m != s3.length())
            return false;

        dp.assign(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {

                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }

                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};

/*
Usage:
Solution obj;
bool result = obj.isInterleave(s1, s2, s3);
*/