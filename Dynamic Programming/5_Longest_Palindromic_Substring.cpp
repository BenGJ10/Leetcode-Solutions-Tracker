/*
5. Longest Palindromic Substring
Link: https://leetcode.com/problems/longest-palindromic-substring/

------------------------------------------------------
Problem Summary:
Given a string `s`, return the **longest palindromic substring** in `s`.

A palindrome is a string that reads the same forward and backward.

------------------------------------------------------
Example 1:
Input:
s = "babad"

Output:
"bab"

Explanation:
"aba" is also a valid answer.

------------------------------------------------------
Example 2:
Input:
s = "cbbd"

Output:
"bb"

------------------------------------------------------
Brute Force Approach:
1. Generate all substrings.
2. Check if each substring is a palindrome.
3. Track the longest one.

- Number of substrings = O(n²)
- Palindrome check = O(n)

- Time Complexity: O(n³)
- Space Complexity: O(1)

Too slow.

------------------------------------------------------
Optimal Approach (DP + Memoized Palindrome Check):
Idea:
- Try every possible substring `(i, j)`.
- Use memoization to avoid recomputing palindrome checks.
- A substring is palindrome if:
    s[l] == s[r] AND inner substring is palindrome.

Steps:
1. Create DP table initialized with -1.
2. For every substring `(i, j)`:
    - Check palindrome using recursion + memo.
3. Track starting index and maximum length.
4. Return substring.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n²)
- Space Complexity: O(n²)

(Note: Expand Around Center can achieve O(n²) time with O(1) space.)

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    bool isPalindrome(string &s, int l, int r) {
        if (l >= r) return true;

        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] == s[r])
            return dp[l][r] = isPalindrome(s, l + 1, r - 1);

        return dp[l][r] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int startIdx = 0, maxLen = 0;

        dp.assign(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        startIdx = i;
                    }
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};

/*
Usage:
Solution obj;
string result = obj.longestPalindrome(s);
*/
