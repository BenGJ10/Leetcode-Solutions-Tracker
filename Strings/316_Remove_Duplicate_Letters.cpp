/*
316. Remove Duplicate Letters
Link: https://leetcode.com/problems/remove-duplicate-letters/

------------------------------------------------------
Problem Summary:
Given a string `s`, remove duplicate letters so that every letter appears once and only once.  
You must make sure your result is the **smallest in lexicographical order** among all possible results.

Example:
Input: s = "bcabc"  
Output: "abc"

------------------------------------------------------
Brute Force Approach:
1. Generate all subsequences containing all unique characters.
2. Sort them lexicographically and pick the smallest one.
⚠️ Exponential time — not feasible for large strings.

------------------------------------------------------
Optimal Approach (Monotonic Stack + Last Occurrence Tracking):

Idea:
- Use a **stack** to build the result string (monotonic in lexicographical order).
- Keep track of:
  * Last index of each character (to know if it appears again later).
  * A `seen[]` array to ensure each character appears once.
- While traversing:
  * If the current character is smaller than the top of the stack **and**
    the top character appears again later → pop from stack.
  * Push the current character and mark it as seen.

Steps:
1. Precompute last index of each character.
2. Traverse each character:
   - If already seen → skip.
   - While top of stack > current char and top appears again → pop it.
   - Push current char and mark as seen.
3. Build result from stack and reverse it.

- Time Complexity: O(n)
- Space Complexity: O(26) = O(1)

------------------------------------------------------
*/

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> seen(26, false);
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            int curr = s[i] - 'a';
            if (seen[curr]) continue;

            while (!st.empty() && st.top() > s[i] && i < lastIndex[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[curr] = true;
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/*
Usage:
Solution sol;
string ans = sol.removeDuplicateLetters("cbacdcbc"); // Output: "acdb"
*/
