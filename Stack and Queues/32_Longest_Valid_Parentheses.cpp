/*
32. Longest Valid Parentheses
Link: https://leetcode.com/problems/longest-valid-parentheses/

------------------------------------------------------
Problem Summary:
Given a string `s` containing just '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

------------------------------------------------------
Optimal Approach (Stack-Based Index Tracking):

Idea:
- Use a stack to keep track of indices of unmatched '('.
- Initialize stack with -1 to handle base cases.
- For each character:
    - If '(': push index onto stack.
    - If ')': pop from stack. 
        - If stack becomes empty, push current index as new base.
        - Else, update max length as `i - st.top()`.

Steps:
1. Initialize stack with -1.
2. Iterate over string:
    - Push index if '('.
    - Pop and compute maxLen if ')'.
3. Return maxLen.

- Time Complexity: O(n), single pass over string.
- Space Complexity: O(n) for stack in worst case.

------------------------------------------------------
*/

#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        if(s.empty()) return maxLen;

        stack<int> st;
        st.push(-1);

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) st.push(i);
                else maxLen = max(maxLen, i - st.top());
            }
        }

        return maxLen;
    }
};

/*
Usage:
Solution sol;
int len = sol.longestValidParentheses("(()"); // Output: 2
*/
