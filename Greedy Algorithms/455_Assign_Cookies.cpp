/*
455. Assign Cookies
Link: https://leetcode.com/problems/assign-cookies/

------------------------------------------------------
Problem Summary:
You are given two integer arrays:
- `g[i]`: the greed factor of the i-th child.
- `s[j]`: the size of the j-th cookie.

You want to assign cookies to children such that each child gets at most one cookie,
and a child i can be content only if `s[j] >= g[i]`.
Return the maximum number of content children you can have.

------------------------------------------------------
Brute Force Approach:
1. For each child, find a cookie that satisfies their greed factor.
2. Mark that cookie as used.
3. Repeat until no cookies left.
- Time Complexity: O(n²)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Two Pointer + Sorting):
Idea:
- Sort both arrays `g` and `s`.
- Use two pointers:
  - `i` for children, `j` for cookies.
- If `s[j]` (cookie size) satisfies `g[i]` (greed), assign and move both pointers.
- Otherwise, move `j` to check the next cookie.
- Count the number of successful assignments.

Steps:
1. Sort `g` and `s`.
2. Initialize `i = 0`, `j = 0`.
3. Traverse both arrays using two pointers.
4. For each match (`g[i] <= s[j]`), increment `i` and `count`.
5. Always move `j` to the next cookie.

- Time Complexity: O(n log n + m log m)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, count = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                i++;
                count++;
            }
            j++;
        }
        return count;
    }
};

/*
Usage:
Solution obj;
int result = obj.findContentChildren(g, s);
*/
