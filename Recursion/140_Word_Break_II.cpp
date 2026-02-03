/*
140. Word Break II
Link: https://leetcode.com/problems/word-break-ii/

------------------------------------------------------
Problem Summary:
You are given:
- A string `s`
- A dictionary of strings `wordDict`

Your task is to return **all possible sentences** where:
- The sentence is formed by inserting spaces into `s`
- Every word in the sentence exists in `wordDict`
- Words can be reused multiple times

------------------------------------------------------
Example:
Input:
s = "catsanddog"
wordDict = ["cat","cats","and","sand","dog"]

Output:
[
  "cats and dog",
  "cat sand dog"
]

------------------------------------------------------
Brute Force Approach:
1. Try all possible ways to split the string `s`.
2. For each split, check if all substrings exist in `wordDict`.
3. Collect valid sentences.

- Time Complexity: Exponential (all partitions)
- Space Complexity: Exponential (recursion + results)

------------------------------------------------------
Optimal Approach (Backtracking with Hash Set):
Idea:
- Use **backtracking** to try all valid prefixes.
- At each index, try forming substrings `s[index...i]`.
- If substring exists in dictionary, recursively solve for remaining string.
- Maintain a current sentence being built.

Key Optimizations:
- Store `wordDict` in a hash set for O(1) lookup.
- Build sentence incrementally and backtrack when needed.

Steps:
1. Insert all dictionary words into an unordered_set.
2. Start backtracking from index 0.
3. For each index:
   - Try all substrings starting at index.
   - If substring is valid:
       - Add it to current sentence
       - Recurse for next index
4. When index reaches end of string:
   - Add constructed sentence to result.

- Time Complexity: Exponential (worst case)
- Space Complexity: O(n) recursion depth + output size

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> result;
    unordered_set<string> words;

    void backtrack(int index, string curr, string s) {
        if (index == s.length()) {
            result.push_back(curr);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            string word = s.substr(index, i - index + 1);

            if (words.find(word) == words.end()) continue;

            string temp = curr;
            if (!curr.empty()) curr += " ";
            curr += word;

            backtrack(i + 1, curr, s);

            curr = temp; // backtrack
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string &word : wordDict) {
            words.insert(word);
        }

        backtrack(0, "", s);
        return result;
    }
};

/*
Usage:
Solution obj;
vector<string> result = obj.wordBreak(s, wordDict);
*/
