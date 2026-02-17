/*
208. Implement Trie (Prefix Tree)
Link: https://leetcode.com/problems/implement-trie-prefix-tree/

------------------------------------------------------
Problem Summary:
Implement a Trie (Prefix Tree) that supports:

1️⃣ insert(word)
2️⃣ search(word)
3️⃣ startsWith(prefix)

Where:
- insert → inserts a word into the Trie.
- search → returns true if the exact word exists.
- startsWith → returns true if any word starts with the given prefix.

------------------------------------------------------
Example:
Input:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // true
trie.search("app");     // false
trie.startsWith("app"); // true
trie.insert("app");
trie.search("app");     // true

------------------------------------------------------
Brute Force Approach:
Store words in a vector or set.

- insert → O(1)
- search → O(N)
- startsWith → O(N * L)

Not efficient for large datasets.

------------------------------------------------------
Optimal Approach (Trie Data Structure):
Idea:
Each node contains:
- Array of 26 child pointers (for lowercase letters)
- A boolean flag to mark end of word

Operations:
1️⃣ insert(word):
   Traverse characters.
   Create nodes if they don’t exist.
   Mark last node as endOfStr = true.

2️⃣ search(word):
   Traverse characters.
   If any node is missing → return false.
   At end, return endOfStr.

3️⃣ startsWith(prefix):
   Traverse characters.
   If all nodes exist → return true.

------------------------------------------------------
Time & Space Complexity:
- insert → O(L)
- search → O(L)
- startsWith → O(L)
- Space → O(total characters inserted)

------------------------------------------------------
*/

#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* links[26];
    bool endOfStr;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        endOfStr = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char &ch : word) {
            int idx = ch - 'a';

            if (curr->links[idx] == nullptr) {
                curr->links[idx] = new TrieNode();
            }

            curr = curr->links[idx];
        }

        curr->endOfStr = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for (char &ch : word) {
            int idx = ch - 'a';

            if (curr->links[idx] == nullptr)
                return false;

            curr = curr->links[idx];
        }

        return curr->endOfStr;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char &ch : prefix) {
            int idx = ch - 'a';

            if (curr->links[idx] == nullptr)
                return false;

            curr = curr->links[idx];
        }

        return true;
    }
};

/*
Usage:
Trie* obj = new Trie();
obj->insert(word);
bool param_2 = obj->search(word);
bool param_3 = obj->startsWith(prefix);
*/
