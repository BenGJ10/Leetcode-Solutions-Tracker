/*
1456. Maximum Number of Vowels in a Substring of Given Length
Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

------------------------------------------------------
Problem Summary:
Given a string `s` and an integer `k`, return the **maximum number of vowels**
in any substring of length `k`.

Vowels are: a, e, i, o, u.

------------------------------------------------------
Brute Force Approach:
1. For every index i, check substring s[i : i+k].
2. Count the vowels inside it.
3. Keep track of the maximum count.

- Time Complexity: O(n * k)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Sliding Window):
Idea:
- Use a window of fixed length `k`.
- Count vowels inside the window.
- Slide window one position at a time:
  - Add vowel entering the window.
  - Remove vowel leaving the window.
- Track the maximum vowel count.

Steps:
1. Initialize count of vowels in first window of size `k`.
2. For each new index:
   - Increment count if s[i] is vowel.
   - Decrement count if s[i-k] is vowel.
3. Keep updating `maxCount`.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0, maxCount = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) count++;
        }

        maxCount = count;

        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) count++;
            if (isVowel(s[i - k])) count--;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

/*
Usage:
Solution obj;
int result = obj.maxVowels(s, k);
*/
