/*
438. Find All Anagrams in a String  
Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

------------------------------------------------------
Problem Summary:
Given two strings `s` and `p`, return all the start indices of `p`'s anagrams in `s`.
An Anagram is a word formed by rearranging the letters of another word.

Example:
Input: s = "cbaebabacd", p = "abc"  
Output: [0, 6]  
Explanation:
- Substring "cba" (starting at index 0) and "bac" (starting at index 6) are anagrams of "abc".

------------------------------------------------------
Brute Force Approach:
1. Generate all substrings of length `p.length()` from `s`.
2. Check if each substring is an anagram of `p` using sorting or counting.
3. Push valid indices into the result vector.
Time Complexity: O((n - m + 1) * m * log m)  
Space Complexity: O(1)

⚠️ Inefficient for large strings (can easily time out).

------------------------------------------------------
Optimal Approach (Sliding Window + Frequency Count):

Idea:
- Use two frequency arrays of size 26:
  1. `patternFreq` for frequency of characters in `p`
  2. `stringFreq` for frequency of current window in `s`
- Slide a window of length `p.length()` across `s`:
  - Add current character to the window.
  - Remove the leftmost character when window size exceeds `p.length()`.
  - If both frequency arrays match, record the start index.

Steps:
1. Build `patternFreq` for `p`.
2. Iterate through `s` with a window of size `pSize`.
3. Update frequencies dynamically.
4. Compare frequency arrays — if equal, push the index.

- Time Complexity: O(n), where n = length of s
- Space Complexity: O(1), fixed size arrays (26)

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sSize = s.length(), pSize = p.length();
        vector<int> result;
        if (pSize > sSize) return result;

        vector<int> patternFreq(26, 0);
        vector<int> stringFreq(26, 0);

        for (auto &elem : p) patternFreq[elem - 'a']++;

        for (int i = 0; i < sSize; i++) {
            stringFreq[s[i] - 'a']++;

            if (i >= pSize) {
                stringFreq[s[i - pSize] - 'a']--;
            }

            if (stringFreq == patternFreq)
                result.push_back(i - pSize + 1);
        }

        return result;
    }
};

/*
Usage:
Solution sol;
vector<int> res = sol.findAnagrams("cbaebabacd", "abc"); // Output: [0, 6]
*/
