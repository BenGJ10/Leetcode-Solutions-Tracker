/*
1209. Remove All Adjacent Duplicates in String II
Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

------------------------------------------------------
Problem Summary:
Given a string `s` and an integer `k`, repeatedly remove groups of `k` identical consecutive characters from `s` 
until no more such groups exist. Return the final string.

Example:
Input: s = "deeedbbcccbdaa", k = 3  
Output: "aa"  
Explanation: 
- Remove "eee" → "ddbbcccbdaa"  
- Remove "bbb" → "ddcccbdaa"  
- Remove "ccc" → "ddbdaa"  
- No more groups of 3, final string = "aa"

------------------------------------------------------
Optimal Approach (Stack with Count Tracking):

Idea:
- Use a stack to track each character along with its consecutive count.
- When top of stack matches current character, increment count.
- If count reaches `k`, pop from stack.
- After processing all characters, rebuild the string from the stack.

Steps:
1. Initialize a stack of pairs `(char, count)`.
2. Iterate through the string:
    - If stack top character equals current, increment count.
        - If count == k, pop.
    - Else, push `(current_char, 1)` onto stack.
3. Build result string from stack (repeat char `count` times).
4. Reverse string (stack gives reversed order) and return.

- Time Complexity: O(n), each character is pushed/popped at most once.
- Space Complexity: O(n), for stack.

------------------------------------------------------
*/

#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;
                if (st.top().second == k) st.pop();
            } 
            else {
                st.push({c, 1});
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/*
Usage:
Solution sol;
string res = sol.removeDuplicates("deeedbbcccbdaa", 3); // Output: "aa"
*/
