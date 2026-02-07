/*
91. Decode Ways
Link: https://leetcode.com/problems/decode-ways/

------------------------------------------------------
Problem Summary:
A message containing letters is encoded as numbers using the mapping:

'A' -> 1  
'B' -> 2  
...  
'Z' -> 26  

Given a string `s` containing only digits, return the **total number of ways**
to decode it.

Rules:
- '0' cannot be decoded alone.
- Valid two-digit numbers must be between 10 and 26.

------------------------------------------------------
Example 1:
Input:
s = "12"

Output:
2

Explanation:
"12" → "AB" (1,2) or "L" (12)

------------------------------------------------------
Example 2:
Input:
s = "226"

Output:
3

Explanation:
"2 2 6" → "BBF"  
"22 6" → "VF"  
"2 26" → "BZ"

------------------------------------------------------
Brute Force Approach:
Try all possible splits recursively.

At each index:
- Take one digit
- Take two digits (if valid)

- Time Complexity: O(2ⁿ)
- Space Complexity: O(n)

This leads to repeated computations.

------------------------------------------------------
Optimal Approach (Dynamic Programming — Bottom-Up):
Idea:
Let `dp[i]` represent the number of ways to decode the substring starting at index `i`.

Transition:
If s[i] != '0':

1️⃣ Take one digit:
    dp[i] += dp[i + 1]

2️⃣ Take two digits if valid (10–26):
    dp[i] += dp[i + 2]

Base Case:
- dp[n] = 1  
  (Empty string has one valid decoding)

Steps:
1. Initialize dp array of size n+1.
2. Traverse from right → left.
3. Apply transitions carefully checking '0'.
4. Return dp[0].

- Time Complexity: O(n)
- Space Complexity: O(n)
(Can be optimized to O(1))

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        dp[n] = 1; // base case

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                int pickOne = dp[i + 1];
                int pickTwo = 0;

                if (i + 1 < n) {
                    if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                        pickTwo = dp[i + 2];
                    }
                }

                dp[i] = pickOne + pickTwo;
            }
        }

        return dp[0];
    }
};

/*
Usage:
Solution obj;
int result = obj.numDecodings(s);
*/

