/*
2785. Sort Vowels in a String
Link: https://leetcode.com/problems/sort-vowels-in-a-string/

------------------------------------------------------
Problem Summary:
You are given a string `s`.  
You must sort ONLY the vowels in the string in **non-decreasing order**, 
while keeping consonants in their original positions.

Vowels include:
A, E, I, O, U, a, e, i, o, u

Return the resulting string after sorting the vowels.

------------------------------------------------------
Example 1:
Input:
s = "lEetcOde"

Output:
"lEOtcede"

Explanation:
Extract vowels → E, e, O, e  
Sorted → E, O, e, e  
Rebuild string: place sorted vowels at original vowel positions.

Example 2:
Input:
s = "lYmpH"

Output:
"lYmpH"  
(Contains no vowels)

------------------------------------------------------
Brute Force Approach:
1. Extract all vowels into a list.
2. Sort the list.
3. Replace vowel positions in the string with sorted vowels.

- Time Complexity: O(n log n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Counting Sort for Vowels):
Idea:
Since there are only 10 possible vowels, we can:
1. Count frequency of each vowel.
2. Iterate through the string again:
   - If character is vowel, replace it using the ordered vowel list.
3. This avoids sorting and improves performance.

Steps:
1. Use a frequency map for vowels.
2. Maintain a fixed ordering string `"AEIOUaeiou"`.
3. Walk through original string and fill vowels in sorted order using frequency.

- Time Complexity: O(n)
- Space Complexity: O(1) extra (only fixed vowel list + count map)

------------------------------------------------------
*/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s) {
        unordered_map<char, int> count;

        // Count vowel frequencies
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) count[s[i]]++;
        }

        string vowels = "AEIOUaeiou";
        string result = s;
        int j = 0; // pointer to sorted vowels

        // Place vowels back in sorted order
        for (int i = 0; i < s.length(); i++) {
            if (!isVowel(s[i])) continue;

            while (j < vowels.length() && count[vowels[j]] == 0) {
                j++;
            }

            result[i] = vowels[j];
            count[vowels[j]]--;
        }
        return result;
    }
};

/*
Usage:
Solution obj;
string result = obj.sortVowels(s)
*/

