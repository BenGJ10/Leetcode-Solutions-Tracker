/*
22. Generate Parentheses
Link: https://leetcode.com/problems/generate-parentheses/

------------------------------------------------------
Problem Summary:
Given an integer `n`, generate **all combinations of well-formed parentheses**
that consist of `n` pairs of parentheses.

A parentheses string is valid if:
- It contains exactly `n` opening '(' and `n` closing ')'
- At any point, the number of ')' does not exceed '('

------------------------------------------------------
Example:
Input:
n = 3

Output:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

------------------------------------------------------
Brute Force Approach:
1. Generate all possible strings of length `2n` using '(' and ')'.
2. Check each string for validity.

- Total strings: 2^(2n)
- Validity check per string: O(n)

- Time Complexity: O(2^(2n) * n)
- Space Complexity: O(n)

This is inefficient.

------------------------------------------------------
Optimal Approach (Backtracking):
Idea:
Build the string step-by-step while maintaining validity.

State:
- `open`  → number of '(' used
- `close` → number of ')' used
- `curr`  → current string being built

Rules:
- You can add '(' if `open < n`
- You can add ')' if `close < open`
- When `curr.length() == 2 * n`, it's a valid combination

This prunes invalid paths early.

Steps:
1. Start with empty string and open = close = 0.
2. Try adding '(' and ') when valid.
3. Collect valid strings when length reaches 2n.

- Time Complexity: O(Catalan(n))
- Space Complexity: O(n) recursion depth

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void backtrack(int open, int close, int n, string curr, vector<string> &res) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            backtrack(open + 1, close, n, curr + '(', res);
        }

        if (close < open) {
            backtrack(open, close + 1, n, curr + ')', res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(0, 0, n, "", ans);
        return ans;
    }
};

/*
Usage:
Solution obj;
vector<string> result = obj.generateParenthesis(n);
*/
