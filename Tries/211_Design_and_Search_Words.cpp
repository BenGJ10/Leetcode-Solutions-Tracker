/*
211. Design Add and Search Words Data Structure
Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/

------------------------------------------------------
Problem Summary:
Design a data structure that supports adding new words
and searching for words where '.' can represent any letter.

Class should support:
    - `void addWord(string word)`
    - `bool search(string word)` (with '.' wildcard support)

------------------------------------------------------
Brute Force Approach (Store All Words & Check):
1. Keep a list/vector of all added words.
2. For search:
   - Compare against every stored word.
   - Handle '.' by allowing any char at that position.
3. Return true if any word matches.

- Time Complexity:
    * addWord: O(1)
    * search: O(n * m), where n = number of words, m = word length
- Space Complexity: O(n * m) to store all words.

------------------------------------------------------
Optimal Approach (Trie with DFS for Wildcard):
Idea:
- Use a Trie to store words character by character.
- `addWord` → Insert into Trie normally.
- `search` → 
    * Traverse Trie character by character.
    * If '.', branch out to all children and DFS.
    * If normal character, just follow that child.
    * At end, check isEndOfWord.

Steps:
1. Constructor initializes root node with 26 children.
2. addWord: iterate through chars, create nodes if missing.
3. search:
   - If char is '.', try all children recursively.
   - Otherwise follow specific path.
   - Base condition: return true if isEndOfWord at end.

- Time Complexity:
    * addWord: O(m), where m = word length.
    * search: O(26^d * m) worst-case (d = number of '.' wildcards).
- Space Complexity: O(n * m) for Trie storage.

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class WordDictionary {
private:
    vector<WordDictionary*> children;
    bool isEndOfWord;
public:
    WordDictionary(): isEndOfWord(false) {
        children = vector<WordDictionary*>(26, nullptr);
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for (char ch: word) {
            if (curr->children[ch - 'a'] == nullptr) {
                curr->children[ch - 'a'] = new WordDictionary();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        WordDictionary* curr = this;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto ch: curr->children) {
                    if (ch != nullptr && ch->search(word.substr(i + 1))) 
                        return true;
                }
                return false;
            }
            if (curr->children[c - 'a'] == nullptr) return false;
            curr = curr->children[c - 'a'];
        } 
        return curr && curr->isEndOfWord;
    }
};

/*
Usage:
WordDictionary* obj = new WordDictionary();
obj->addWord("bad");
bool found = obj->search("b.."); // true
*/
