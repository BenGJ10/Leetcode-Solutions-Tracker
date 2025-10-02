/*
692. Top K Frequent Words
Link: https://leetcode.com/problems/top-k-frequent-words/

------------------------------------------------------
Problem Summary:
Given an array of words, return the k most frequent words.
The answer should be sorted by frequency (highest first).
If multiple words have the same frequency, sort them lexicographically.

------------------------------------------------------
Brute Force Approach:
1. Count frequencies of all words using a hash map.
2. Sort all unique words based on:
   - Higher frequency first.
   - If tie, lexicographically smaller word first.
3. Return the top k words.
- Time Complexity: O(n log n) due to sorting.
- Space Complexity: O(n).

------------------------------------------------------
Optimal Approach (Heap + Custom Comparator):
Idea:
- Use a frequency map to count occurrences.
- Use a priority queue (max-heap) with custom comparator:
    * Higher frequency first.
    * If equal frequency, lexicographically smaller word first.
- Push all words into heap, then extract top k.

Steps:
1. Build frequency map of words.
2. Push all {word, frequency} into max-heap.
3. Pop top k elements to get result.

- Time Complexity: O(n log n) in worst case due to heap insertions (n unique words).
- Space Complexity: O(n) for map and heap.

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            if (a.second == b.second) return a.first > b.first; // lexicographic order
            return a.second < b.second; // higher freq first
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for (auto& word : words) {
            mpp[word]++;
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for (auto& elem : mpp) {
            pq.push({elem.first, elem.second});
        }

        vector<string> result;
        while (k--) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};

/*
Usage:
Solution sol;
vector<string> res = sol.topKFrequent(words, k);
*/
