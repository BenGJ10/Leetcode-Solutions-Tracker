/*
68. Text Justification
Link: https://leetcode.com/problems/text-justification/

------------------------------------------------------
Problem Summary:
Given an array of words and a width `maxWidth`, format the text so that each line has exactly `maxWidth` characters
and is fully justified. 
- Words should be packed in order.
- Each line (except last) should be fully justified — spaces distributed evenly.
- The last line should be left-justified.

Example:
Input: words = ["This","is","an","example","of","text","justification."], maxWidth = 16  
Output:  
["This    is    an",  
 "example  of text",  
 "justification.  "]

------------------------------------------------------
Brute Force Idea:
1. Keep adding words until the next word doesn’t fit in `maxWidth`.
2. Add minimal spaces between them, then distribute extra spaces from left to right.
3. Repeat for all lines.

This approach works conceptually but gets messy without modularization.

------------------------------------------------------
Optimal Modular Approach (Greedy Line Formation + Controlled Spacing):

Idea:
- Use a greedy approach to determine how many words fit in each line.
- For each line:
  * Compute the total spaces to insert (`maxWidth - totalWordLength`).
  * Distribute them evenly between words.
  * Handle special cases:
      - Last line → left-justified with single spaces.
      - Line with one word → pad all spaces to the right.

Functions:
1. **findRight()** → Find the last word index that fits in the current line.
2. **makeSentence()** → Construct a justified line with proper space distribution.
3. **addSpaces()** → Utility to generate `count` number of spaces.

Steps:
1. Start from the first word.
2. Use `findRight()` to locate the boundary for the current line.
3. Build the justified line using `makeSentence()`.
4. Move to the next line until all words are processed.

- Time Complexity: O(n) — each word processed once.
- Space Complexity: O(1) extra space (excluding output).

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findRight(vector<string> &words, int maxWidth, int left, int &size) {
        size = words[left].size();
        int right = left + 1;

        while (right < words.size() && size + 1 + words[right].size() <= maxWidth) {
            size += 1 + words[right].size(); // include 1 space between words
            right++;
        }
        return right - 1; // last valid word that fits
    }

    string makeSentence(vector<string> &words, int maxWidth, int left, int right, int size) {
        int n = words.size();
        int spaces = maxWidth - (size - (right - left));

        if (left == right)
            return words[left] + addSpaces(maxWidth - words[left].size());

        bool isLastLine = (right == n - 1);
        string sentence = "";

        int numWordGaps = right - left;
        int gapCount = spaces / numWordGaps;
        int extraGap = spaces % numWordGaps;

        while (left < right) {
            sentence += words[left];
            left++;

            if (isLastLine) {
                sentence += " "; // single space for last line
            } else {
                string sp = addSpaces(gapCount);
                if (extraGap > 0) {
                    sp += " ";
                    extraGap--;
                }
                sentence += sp;
            }
        }

        sentence += words[right];

        // pad remaining spaces at the end for last line
        if (isLastLine) {
            int remaining = maxWidth - sentence.size();
            sentence += addSpaces(remaining);
        }

        return sentence;
    }

    string addSpaces(int count) {
        string sp = "";
        for (int i = 0; i < count; i++)
            sp += " ";
        return sp;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int left = 0, right = 0, size = 0;
        vector<string> result;

        while (left < n) {
            right = findRight(words, maxWidth, left, size);
            result.push_back(makeSentence(words, maxWidth, left, right, size));
            left = right + 1;
        }
        return result;
    }
};

/*
Usage:
Solution sol;
vector<string> res = sol.fullJustify({"This","is","an","example","of","text","justification."}, 16);
for (auto &line : res) cout << '"' << line << '"' << endl;
*/
