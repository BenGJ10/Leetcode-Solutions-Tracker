/*
1312. Minimum Insertion Steps to Make a String Palindrome
Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

------------------------------------------------------
Problem Summary:
Given a string `s`, return the **minimum number of insertions**
needed to make the string a palindrome.

You can insert characters at any position.

------------------------------------------------------
Example 1:
Input:
s = "zzazz"

Output:
0

Explanation:
Already a palindrome.

------------------------------------------------------
Example 2:
Input:
s = "mbadm"

Output:
2

Explanation:
One possible palindrome → "mbdadbm"

------------------------------------------------------
Example 3:
Input:
s = "leetcode"

Output:
5

------------------------------------------------------
Brute Force Approach:
Try inserting characters at every possible position and check
if the string becomes a palindrome.

- Time Complexity: Exponential
- Space Complexity: O(n)

Clearly inefficient.

------------------------------------------------------
Optimal Approach (Reduce to Longest Palindromic Subsequence):
Key Insight:
Instead of thinking about insertions directly:

👉 Minimum Insertions = n - LPS

Where:
LPS (Longest Palindromic Subsequence) is found by computing
the **Longest Common Subsequence (LCS)** between:

    s and reverse(s)

Why?
Because characters already forming a palindrome do not need insertion.

------------------------------------------------------
DP Transition (LCS):
If characters match:
    dp[i][j] = 1 + dp[i-1][j-1]

Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Answer:
    n - LCS

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n²)
- Space Complexity: O(n²)

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int findLCS(string &s1, string &s2, int i, int j) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + findLCS(s1, s2, i - 1, j - 1);

        return dp[i][j] = max(
            findLCS(s1, s2, i - 1, j),
            findLCS(s1, s2, i, j - 1)
        );
    }

    int minInsertions(string s) {
        int n = s.length();

        string rev = s;
        reverse(rev.begin(), rev.end());

        dp.assign(n, vector<int>(n, -1));

        int lcs = findLCS(s, rev, n - 1, n - 1);

        return n - lcs;
    }
};

/*
Usage:
Solution obj;
int result = obj.minInsertions(s);
*/

