/*
890. Find and Replace Pattern
Link: https://leetcode.com/problems/find-and-replace-pattern/

------------------------------------------------------
Problem Summary:
You are given a list of words and a string `pattern`.
Return all words that match the pattern — meaning there exists a bijection (one-to-one mapping)
between each letter in the word and each letter in the pattern.

Example:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]

Explanation:
- "mee" → m→a, e→b (bijection valid)
- "aqq" → a→a, q→b (bijection valid)
- "abc" → invalid because pattern repeats 'b', but word does not repeat.

------------------------------------------------------
Brute Force Approach:
For each word:
1. Compare with pattern letter by letter.
2. Create mapping from pattern → word and word → pattern.
3. If mapping violates one-to-one property, reject the word.
Time Complexity: O(N * L), where N = number of words, L = word length.
Space Complexity: O(L) for maps.

------------------------------------------------------
Optimal Approach (Bijective Mapping Verification):

Idea:
To check if a word follows the pattern:
- Maintain two hash maps:
  1. `WtoP`: word char → pattern char
  2. `PtoW`: pattern char → word char
- For each index `i`, ensure mappings are consistent both ways.
- If at any point they mismatch, return false.

Steps:
1. For each word, initialize two empty hash maps.
2. Traverse each character of the word and pattern simultaneously.
3. Check if current mapping is consistent in both directions.
4. If valid for all positions, add the word to result.

- Time Complexity: O(N * L)
- Space Complexity: O(L)

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool matcher(string word, string pattern) {
        unordered_map<char, char> WtoP;
        unordered_map<char, char> PtoW;

        for (int i = 0; i < word.length(); i++) {
            char w = word[i];
            char p = pattern[i];

            if (WtoP.count(w) && WtoP[w] != p) return false;
            if (PtoW.count(p) && PtoW[p] != w) return false;

            WtoP[w] = p;
            PtoW[p] = w;
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (string word : words) {
            if (matcher(word, pattern)) {
                result.push_back(word);
            }
        }
        return result;
    }
};

/*
Usage:
Solution sol;
vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
string pattern = "abb";
vector<string> res = sol.findAndReplacePattern(words, pattern); // Output: ["mee", "aqq"]
*/

