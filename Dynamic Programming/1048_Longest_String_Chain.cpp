/*
1048. Longest String Chain
Link: https://leetcode.com/problems/longest-string-chain/

------------------------------------------------------
Problem Summary:
You are given an array of words.

A word `A` is a predecessor of word `B` if:
- You can insert exactly one character anywhere in `A`
- And make it equal to `B`

Return the **length of the longest possible word chain**.

------------------------------------------------------
Example 1:
Input:
words = ["a","b","ba","bca","bda","bdca"]

Output:
4

Explanation:
One valid chain:
"a" → "ba" → "bda" → "bdca"

------------------------------------------------------
Example 2:
Input:
words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]

Output:
5

------------------------------------------------------
Example 3:
Input:
words = ["abcd","dbqca"]

Output:
1

------------------------------------------------------
Approach (DP + Sorting):

Idea:
- Sort words based on length
- Try to build chains from smaller → larger words
- Use DP where:
    dp[i] = longest chain ending at word i

------------------------------------------------------
Key Observation:
If `s2` is a predecessor of `s1`, then:
length(s1) = length(s2) + 1

------------------------------------------------------
Steps:

1. Sort words by length (ascending)
2. Initialize dp[i] = 1 for all i
3. For each word `idx`:
    - Check all previous words `prev`
    - If words[prev] is predecessor of words[idx]:
        dp[idx] = max(dp[idx], dp[prev] + 1)

4. Track maximum dp value

------------------------------------------------------
Predecessor Check:

Two pointers:
- Traverse both strings
- Allow exactly one mismatch (skip in longer string)

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(n² * L)
- n = number of words
- L = average word length

Space Complexity:
O(n)

------------------------------------------------------
Better Approach (Not implemented below):

Use **HashMap + DP**:

For each word:
- Remove one character at every position
- Check if the smaller word exists in map

dp[word] = max(dp[prev_word] + 1)

This reduces complexity to:
O(n * L²)

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    struct Compare{
        bool operator()(string &s1, string &s2){
            return s1.length() < s2.length();
        }
    };

    bool isPredecessor(string &s1, string &s2){

        if(s1.length() != s2.length() + 1)
            return false;

        int i = 0, j = 0;

        while(i < s1.length()){
            if(j < s2.length() && s1[i] == s2[j]){
                i++; j++;
            }
            else{
                i++;
            }
        }

        return (i == s1.length() && j == s2.length());
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), Compare());

        int n = words.size();
        int maxLen = 1;

        vector<int> dp(n, 1);

        for(int idx = 0; idx < n; idx++){

            for(int prev = 0; prev < idx; prev++){

                if(isPredecessor(words[idx], words[prev]) 
                    && dp[prev] + 1 > dp[idx]){

                    dp[idx] = 1 + dp[prev];
                }
            }

            if(dp[idx] > maxLen){
                maxLen = dp[idx];
            }
        }

        return maxLen;
    }
};

/*
Usage:
Solution obj;
int result = obj.longestStrChain(words);
*/