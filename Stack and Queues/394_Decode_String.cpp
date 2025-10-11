/*
394. Decode String
Link: https://leetcode.com/problems/decode-string/

------------------------------------------------------
Problem Summary:
Given an encoded string, return its decoded string.  
The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is repeated exactly `k` times.  
- Nested encodings are allowed.
- You may assume the input string is always valid.

Example:
Input: s = "3[a2[c]]"  
Output: "accaccacc"

------------------------------------------------------
Brute Force Approach:
1. Recursively find the innermost brackets.
2. Decode the substring inside and repeat `k` times.
- Time Complexity: O(n^2) due to repeated string concatenations.
- Space Complexity: O(n) for recursion stack.

------------------------------------------------------
Optimal Approach (Using Two Stacks):

Idea:
- Use one stack for numbers (`numStack`) and one for strings (`strStack`).
- Traverse the string:
  * If digit → build current number.
  * If '[' → push current number and string onto stacks; reset them.
  * If ']' → pop number and string; repeat the current string `num` times and append to previous string.
  * Else → append character to current string.

Steps:
1. Initialize `num = 0` and `currStr = ""`.
2. For each character `ch`:
   - If digit: `num = num * 10 + (ch - '0')`
   - If '[': push `num` and `currStr` onto stacks; reset both.
   - If ']': pop number and string; append repeated current string.
   - Else: append `ch` to `currStr`.
3. Return `currStr` after traversal.

- Time Complexity: O(n * k), where k is the maximum repeat factor.
- Space Complexity: O(n) for stacks.

------------------------------------------------------
*/

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        int num = 0;
        string currStr = "";

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '[') {
                numStack.push(num);
                strStack.push(currStr);
                num = 0;
                currStr = "";
            } else if (ch == ']') {
                string temp = currStr;
                currStr = strStack.top(); strStack.pop();
                int repeat = numStack.top(); numStack.pop();

                while (repeat--) currStr += temp;
            } else {
                currStr += ch;
            }
        }
        return currStr;
    }
};

/*
Usage:
Solution sol;
string decoded = sol.decodeString("3[a2[c]]"); // Output: "accaccacc"
*/
