/*
846. Hand of Straights
Link: https://leetcode.com/problems/hand-of-straights/

------------------------------------------------------
Problem Summary:
You are given an integer array `hand` where `hand[i]` represents a card value,
and an integer `groupSize`. Return true if the cards can be rearranged into groups
of size `groupSize` such that each group contains `groupSize` consecutive cards.

------------------------------------------------------
Example:
Input:
hand = [1,2,3,6,2,3,4,7,8], groupSize = 3

Output:
true

Explanation:
Form 3 groups:
[1,2,3], [2,3,4], [6,7,8]

------------------------------------------------------
Brute Force Approach:
1. Sort the hand.
2. Try to greedily form consecutive groups of size `groupSize`.
3. Keep track of used cards.
- Time Complexity: O(n²)
- Space Complexity: O(n).

------------------------------------------------------
Optimal Approach (Using Map + Min-Heap):
Idea:
- Count frequency of each card using a hash map.
- Use a min-heap to always access the smallest card value.
- Repeatedly try to form groups starting from the smallest card.
- For each group, check if all consecutive cards exist in sufficient quantity.
- If at any point a card is missing or insufficient, return false.

Steps:
1. Build a frequency map of all cards.
2. Push all unique card values into a min-heap.
3. While heap is not empty:
   - Let `minElem` be the smallest card.
   - Determine how many groups start from `minElem` (its count).
   - For each next `groupSize - 1` card, check and reduce counts.
   - Remove cards from heap whose count becomes zero.
4. If all cards are grouped successfully, return true.

- Time Complexity: O(n log n)
  (log n for heap operations, n for processing all cards)
- Space Complexity: O(n).

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mpp;
        for (int &h : hand)
            mpp[h]++;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &elem : mpp)
            pq.push(elem.first);

        while (!pq.empty()) {
            int minElem = pq.top();
            int count = mpp[minElem];

            for (int i = 0; i < groupSize; i++) {
                int nextElem = minElem + i;
                if (mpp[nextElem] < count)
                    return false;
                mpp[nextElem] -= 1;
            }

            while (!pq.empty() && mpp[pq.top()] == 0)
                pq.pop();
        }
        return true;
    }
};

/*
Usage:
Solution obj;
bool res = obj.isNStraightHand(hand, groupSize);
*/
