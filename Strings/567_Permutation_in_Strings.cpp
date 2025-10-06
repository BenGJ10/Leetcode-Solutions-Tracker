/*
567. Permutation in String
Link: https://leetcode.com/problems/permutation-in-string/

------------------------------------------------------
Problem Summary:
Given two strings `s1` and `s2`, return true if `s2` contains a 
permutation of `s1`. In other words, one of `s1`'s permutations 
is a substring of `s2`.

------------------------------------------------------
Brute Force Approach:
1. Generate all permutations of `s1`.
2. Check if any permutation exists as a substring in `s2`.

------------------------------------------------------
Optimal Approach (Sliding Window with Frequency Count):

Idea:
- Two strings are permutations of each other if they have identical 
  character frequencies.
- Use a sliding window of length equal to `s1` over `s2` and 
  compare character counts at each step.

Steps:
1. Create frequency arrays of size 26 (for lowercase letters).
2. Count frequencies of characters in `s1`.
3. Traverse `s2`:
   - Add the current character to the window.
   - Once window size exceeds `s1.length()`, remove the oldest character.
   - Compare frequency arrays after each shift.
   - If they match at any point, return true.

- Time Complexity: O(n), where n = s2.length()
  (Each character is processed at most twice — added and removed once.)
- Space Complexity: O(1)
  (Constant extra space for frequency arrays of size 26.)

------------------------------------------------------
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        vector<int> windowFreq(26, 0);

        for (char c : s1) freq[c - 'a']++;

        int windowSize = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            windowFreq[s2[i] - 'a']++;

            if (i >= windowSize)
                windowFreq[s2[i - windowSize] - 'a']--;

            if (windowFreq == freq)
                return true;
        }
        return false;
    }
};

/*
Usage:
Solution sol;
bool res = sol.checkInclusion("ab", "eidbaooo"); // Output: true
*/

