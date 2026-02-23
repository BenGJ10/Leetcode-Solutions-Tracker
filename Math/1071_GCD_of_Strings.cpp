/*
1071. Greatest Common Divisor of Strings
Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/

------------------------------------------------------
Problem Summary:
For two strings `str1` and `str2`, return the largest string `x`
such that:

1️⃣ `x` divides `str1`
2️⃣ `x` divides `str2`

A string `t` divides string `s` if:
    s = t + t + t + ... (one or more times)

If no such string exists, return "".

------------------------------------------------------
Example 1:
Input:
str1 = "ABCABC", str2 = "ABC"

Output:
"ABC"

------------------------------------------------------
Example 2:
Input:
str1 = "ABABAB", str2 = "ABAB"

Output:
"AB"

------------------------------------------------------
Example 3:
Input:
str1 = "LEET", str2 = "CODE"

Output:
""

------------------------------------------------------
Brute Force Approach:
1. Check all possible prefixes of the smaller string.
2. For each prefix:
   - Verify it divides both strings.
3. Return the largest valid prefix.

Time Complexity: O(n²)
Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Math + GCD Insight):
Key Observations:

1️⃣ If a valid divisor string exists, then:
    str1 + str2 must equal str2 + str1

   If this fails → return "" immediately.

2️⃣ The length of the answer must be:
    gcd(len(str1), len(str2))

So:
- Compute gcd of lengths.
- Return prefix of length gcd from str1.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <string>
using namespace std;

class Solution {
public:
    int findGCD(int len1, int len2) {
        while (len2 != 0) {
            int temp = len1 % len2;
            len1 = len2;
            len2 = temp;
        }
        return len1;
    }

    string gcdOfStrings(string str1, string str2) {

        if (str1 + str2 != str2 + str1)
            return "";

        int len1 = str1.length();
        int len2 = str2.length();

        int gcdLen = findGCD(len1, len2);

        return str1.substr(0, gcdLen);
    }
};

/*
Usage:
Solution obj;
string result = obj.gcdOfStrings(str1, str2);
*/