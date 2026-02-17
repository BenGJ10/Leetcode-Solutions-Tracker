/*
211. Design Add and Search Words Data Structure
Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/

------------------------------------------------------
Problem Summary:
Design a data structure that supports:
1️⃣ addWord(word)  
2️⃣ search(word)

search(word) supports '.' wildcard:
- '.' can represent any single lowercase letter.

------------------------------------------------------
Example:
Input:
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");

wordDictionary.search("pad"); // false
wordDictionary.search("bad"); // true
wordDictionary.search(".ad"); // true
wordDictionary.search("b.."); // true

------------------------------------------------------
Brute Force Approach:
Store words in a vector and:
- For search:
  - Compare with every stored word.
  - Handle '.' manually.

- Time Complexity:
  addWord → O(1)
  search  → O(N * L)
  (N = number of words, L = word length)

Inefficient for large inputs.

------------------------------------------------------
Optimal Approach (Trie + Backtracking):
Idea:
Use a Trie to store words efficiently.

For search:
- If character is normal:
    → move to corresponding child.
- If character is '.':
    → recursively try all 26 children.

If we reach end of word and node->endOfStr == true,
then word exists.

------------------------------------------------------
Time & Space Complexity:
- addWord: O(L)
- search:
    Worst case: O(26^L) (if many '.' wildcards)
    Typical case: O(L)
- Space Complexity: O(total characters inserted)

------------------------------------------------------
*/

#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* links[26];
    bool endOfStr;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
        endOfStr = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char &ch : word) {
            int idx = ch - 'a';

            if (curr->links[idx] == nullptr)
                curr->links[idx] = new TrieNode();

            curr = curr->links[idx];
        }

        curr->endOfStr = true;
    }

    bool search(string word) {
        return searchWord(word, 0, root);
    }

    bool searchWord(string &word, int index, TrieNode* node) {
        TrieNode* curr = node;

        for (int i = index; i < word.length(); i++) {
            char ch = word[i];

            if (ch == '.') {
                // Try all possible children
                for (TrieNode* child : curr->links) {
                    if (child != nullptr &&
                        searchWord(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            } 
            else {
                if (curr->links[ch - 'a'] == nullptr)
                    return false;

                curr = curr->links[ch - 'a'];
            }
        }

        return curr->endOfStr;
    }
};

/*
Usage:
WordDictionary* obj = new WordDictionary();
obj->addWord(word);
bool result = obj->search(word);
*/
