/*
44. Wildcard Matching
Link: https://leetcode.com/problems/wildcard-matching/

------------------------------------------------------
Problem Summary:
You are given two strings:

- `s` → input string
- `p` → pattern string

The pattern may contain special wildcard characters:

    '?' → matches exactly ONE character
    '*' → matches ANY sequence of characters (including empty)

Your task is to determine whether the entire string `s`
matches the pattern `p`.

------------------------------------------------------
Example 1:
Input:
s = "aa"
p = "a"

Output:
false

Explanation:
Pattern expects only one 'a', but string has two.

------------------------------------------------------
Example 2:
Input:
s = "aa"
p = "*"

Output:
true

Explanation:
'*' can match any sequence of characters.

------------------------------------------------------
Example 3:
Input:
s = "cb"
p = "?a"

Output:
false

Explanation:
'?' matches 'c', but 'a' ≠ 'b'.

------------------------------------------------------
Brute Force Approach:
Try all possibilities for '*' expansion.

At every '*', we can:
- match 0 characters
- match 1 character
- match many characters

This leads to exponential recursion.

- Time Complexity: O(2^(n+m))
- Space Complexity: O(n+m)

Not feasible for large inputs.

------------------------------------------------------
Optimal Approach (Recursion + Memoization DP):

Idea:
We compare characters from the end of both strings.

Define:
dp[i][j] → whether s[0..i] matches p[0..j]

Transitions:

1. If characters match OR pattern has '?':
      matchCharacters(i-1, j-1)

2. If pattern has '*':
      '*' can represent:
        - empty sequence → matchCharacters(i, j-1)
        - one/more chars → matchCharacters(i-1, j)

3. If characters don't match:
      return false

Base Cases:

1. i < 0 AND j < 0
      Both strings finished → true

2. j < 0 AND i >= 0
      Pattern finished but string remains → false

3. i < 0 AND j >= 0
      String finished but pattern remains
      Valid only if remaining pattern characters are all '*'

------------------------------------------------------
Time Complexity:
O(n * m)

Each state (i, j) computed once.

Space Complexity:
O(n * m) for memoization table.

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;

    bool matchCharacters(int i, int j, string &s, string &p){

        // Both strings finished
        if(i < 0 && j < 0) return true;

        // Pattern finished but string remains
        if(j < 0 && i >= 0) return false;

        // String finished but pattern remains
        if(i < 0 && j >= 0){
            for(int idx = j; idx >= 0; idx--){
                if(p[idx] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // Characters match OR pattern '?'
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = matchCharacters(i - 1, j - 1, s, p);
        }

        // Pattern '*'
        if(p[j] == '*'){
            return dp[i][j] =
                matchCharacters(i, j - 1, s, p) ||  // '*' as empty
                matchCharacters(i - 1, j, s, p);    // '*' consumes char
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();

        dp.assign(n, vector<int>(m, -1));

        return matchCharacters(n - 1, m - 1, s, p);
    }
};

/*
Usage:

Solution obj;
bool result = obj.isMatch("abcde", "a*de");

*/
