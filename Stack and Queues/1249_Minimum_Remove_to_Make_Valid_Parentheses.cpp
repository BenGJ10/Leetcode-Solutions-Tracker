/*
1249. Minimum Remove to Make Valid Parentheses
Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

------------------------------------------------------
Problem Summary:
Given a string `s` containing lowercase letters and parentheses
'(' and ')', remove the **minimum number of parentheses** so that
the resulting string is valid.

A string is valid if:
1. Open brackets are closed in correct order.
2. No unmatched parentheses exist.

------------------------------------------------------
Example 1:
Input:
s = "lee(t(c)o)de)"

Output:
"lee(t(c)o)de"

------------------------------------------------------
Example 2:
Input:
s = "a)b(c)d"

Output:
"ab(c)d"

------------------------------------------------------
Example 3:
Input:
s = "))(("

Output:
""

------------------------------------------------------
Approach (Stack + Index Tracking):

Idea:
- Track indices of **invalid parentheses** using a stack.
- First pass: identify all unmatched '(' and ')'.
- Second pass: build result string excluding those indices.

------------------------------------------------------
Steps:

1. Traverse string:
   - If '(' → push (char, index)
   - If ')':
        - If matching '(' exists → pop
        - Else → push invalid ')'

2. Stack now contains indices of all invalid parentheses.

3. Traverse string from end:
   - Skip indices present in stack
   - Add remaining characters to result

4. Reverse result (since we built it backward)

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(n)

Space Complexity:
O(n) (stack + result)

------------------------------------------------------
Better Approach (Not implemented below):

Use a **two-pass greedy approach without stack**:

1. Left → Right:
   - Remove extra ')'

2. Right → Left:
   - Remove extra '('

This reduces space usage and is more optimal in practice.

------------------------------------------------------
*/

#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.length();
        stack<pair<char, int>> st;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push({'(', i});
            }
            else if(s[i] == ')'){
                if(!st.empty() && st.top().first == '('){
                    st.pop();
                }
                else{
                    st.push({')', i});
                }
            }
        }

        if(st.empty()) return s;
        
        string result = "";

        for(int i = n - 1; i >= 0; i--){
            if(!st.empty() && i == st.top().second){
                st.pop();
            }
            else{
                result += s[i];
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

/*
Usage:
Solution obj;
string result = obj.minRemoveToMakeValid(s);
*/