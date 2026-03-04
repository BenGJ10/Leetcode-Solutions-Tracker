/*
139. Word Break
Link: https://leetcode.com/problems/word-break/

------------------------------------------------------
Problem Summary:
Given a string `s` and a dictionary of strings `wordDict`,
determine if `s` can be segmented into a space-separated
sequence of one or more dictionary words.

Note:
- Words from the dictionary can be reused multiple times.

------------------------------------------------------
Example 1:
Input:
s = "leetcode"
wordDict = ["leet", "code"]

Output:
true

Explanation:
"leetcode" = "leet" + "code"

------------------------------------------------------
Example 2:
Input:
s = "applepenapple"
wordDict = ["apple", "pen"]

Output:
true

Explanation:
"applepenapple" = "apple" + "pen" + "apple"

------------------------------------------------------
Example 3:
Input:
s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]

Output:
false

------------------------------------------------------
Brute Force Approach:
Try all possible partitions of the string
and check whether each substring exists in the dictionary.

This leads to exponential recursion.

Time Complexity: O(2^n)

------------------------------------------------------
Optimal Approach (Dynamic Programming):
Idea:
Let dp[i] represent whether substring
s[0...i-1] can be segmented using dictionary words.

Transition:
For every position i:
    check all previous positions j < i

If:
    dp[j] == true
    AND substring s[j...i-1] exists in dictionary
then:
    dp[i] = true

Base Case:
dp[0] = true (empty string)

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();

        vector<bool> dp(n + 1, false);

        unordered_set<string> st;
        for (string word : wordDict) {
            st.insert(word);
        }

        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {

                string word = s.substr(j, i - j);

                if (dp[j] && st.count(word)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

/*
Usage:
Solution obj;
bool result = obj.wordBreak(s, wordDict);
*/