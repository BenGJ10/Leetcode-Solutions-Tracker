/*
678. Valid Parenthesis String
Link: https://leetcode.com/problems/valid-parenthesis-string/

------------------------------------------------------
Problem Summary:
Given a string `s` containing only the characters `'('`, `')'`, and `'*'`, 
determine if it is possible to make the string a valid parenthesis expression.

Rules:
- `'('` must be closed by a corresponding `')'`.
- `'*'` can represent `'('`, `')'`, or an empty string.

Return `true` if the string can be made valid, otherwise `false`.

------------------------------------------------------
Example:
Input:
s = "(*)"

Output:
true

Explanation:
- '*' can be treated as an empty string, making it "()", which is valid.

Example 2:
Input:
s = "(*))"

Output:
true

------------------------------------------------------
Brute Force Approach:
1. For every `*`, try replacing it with `'('`, `')'`, or `''` (empty string).
2. Check all possible combinations for validity.
3. Return true if any valid configuration exists.
- Time Complexity: O(3ⁿ)
- Space Complexity: O(n) (recursion stack)

------------------------------------------------------
Optimal Approach (Greedy Range Tracking):
Idea:
- Track the **range of possible open parentheses** (`minCount` and `maxCount`) while scanning the string.
- For every character:
  - `'('`: increases both `minCount` and `maxCount` (since it adds an open bracket).
  - `')'`: decreases both (since it closes one).
  - `'*'`: can act as `'('` (increase `maxCount`) or `')'` (decrease `minCount`).
- If `minCount` becomes negative, reset it to 0 (since '*' can balance extra `')'`).
- If `maxCount` becomes negative → invalid state (too many `')'`).
- At the end, if `minCount == 0`, it's valid.

Steps:
1. Initialize `minCount = 0`, `maxCount = 0`.
2. Traverse each character and update both counts based on the character type.
3. Ensure counts stay within valid bounds.
4. Return `true` if `minCount == 0` at the end.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int minCount = 0, maxCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                minCount++;
                maxCount++;
            } 
            else if (s[i] == ')') {
                minCount--;
                maxCount--;
            } 
            else if (s[i] == '*') {
                minCount--;
                maxCount++;
            }
            if (minCount < 0) minCount = 0;
            if (maxCount < 0) return false;
        }
        return minCount == 0;
    }
};

/*
Usage:
Solution obj;
bool result = obj.checkValidString(s);
*/
