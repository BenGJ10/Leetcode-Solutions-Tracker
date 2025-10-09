/*
6. Zigzag Conversion  
Link: https://leetcode.com/problems/zigzag-conversion/

------------------------------------------------------
Problem Summary:
Given a string `s` and an integer `numRows`, rearrange `s` in a zigzag pattern on `numRows` rows,
then read line by line to produce the converted string.

Example:
Input: s = "PAYPALISHIRING", numRows = 3  
Pattern:
P   A   H   N  
A P L S I I G  
Y   I   R  
Output: "PAHNAPLSIIGYIR"

------------------------------------------------------
Brute Force Approach:
1. Build a 2D matrix of characters.
2. Fill characters diagonally down and up in a zigzag pattern.
3. Read all rows sequentially to get the result.
- Time Complexity: O(n)
- Space Complexity: O(n), but uses extra space for matrix representation.

------------------------------------------------------
Optimal Approach (Simulated Zigzag Rows):

Idea:
- Maintain a vector of strings, one per row.
- Traverse characters of `s`, appending each to the correct row.
- Change direction (down ↕ up) when reaching top or bottom row.

Steps:
1. If numRows == 1 → return s (no zigzag possible).
2. Use `currRow` to track current row.
3. Use a boolean flag `direction` to determine traversal direction.
4. Join all rows at the end for the final result.

- Time Complexity: O(n), where n = length of s.
- Space Complexity: O(n), for storing characters in rows.

------------------------------------------------------
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;

        vector<string> rows(numRows);
        int currRow = 0;
        bool direction = false;

        for (char ch : s) {
            rows[currRow] += ch;

            if (currRow == 0 || currRow == numRows - 1)
                direction = !direction;

            currRow += direction ? 1 : -1;
        }

        string result = "";
        for (string &row : rows)
            result += row;

        return result;
    }
};

/*
Usage:
Solution sol;
string res = sol.convert("PAYPALISHIRING", 3); // Output: "PAHNAPLSIIGYIR"
*/
