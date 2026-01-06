/*
904. Fruit Into Baskets
Link: https://leetcode.com/problems/fruit-into-baskets/

------------------------------------------------------
Problem Summary:
You are given an integer array `fruits` where `fruits[i]` represents the type of fruit on the i-th tree.

You have **two baskets**, and each basket can only hold **one type** of fruit.
You may pick exactly one fruit from each tree moving from left to right,
but must stop if you encounter a third distinct fruit type.

Return the **maximum number of fruits** you can collect.

This is equivalent to:
Find the length of the **longest subarray containing at most 2 distinct values**.

------------------------------------------------------
Example:
Input:
fruits = [1,2,1]

Output:
3

Explanation:
Pick all fruits → only 2 distinct types present.

Example 2:
Input:
fruits = [0,1,2,2]

Output:
3

Explanation:
Pick from trees [1,2,2]

------------------------------------------------------
Brute Force Approach:
Check every subarray and verify if it contains ≤ 2 distinct fruit types.

- Time Complexity: O(n²)
- Space Complexity: O(n)

Too slow for large arrays.

------------------------------------------------------
Optimal Approach (Sliding Window + HashMap):
Idea:
Maintain a sliding window where:
- The window always contains at most **2 distinct fruit types**
- Expand right pointer to include fruits
- Shrink left pointer when >2 types exist

Use a map to store:
fruit → frequency in current window

Steps:
1. Expand `right` pointer and count fruit frequency.
2. If more than 2 types exist:
   - Shrink from `left` until distinct count ≤ 2.
3. Track maximum window length.

- Time Complexity: O(n)
- Space Complexity: O(1)  (map size ≤ 3)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        int maxFruits = 0;

        unordered_map<int, int> mpp; // fruit type -> count

        while (right < n) {
            mpp[fruits[right]]++;

            // shrink window if we have more than 2 types
            while (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0)
                    mpp.erase(fruits[left]);
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
            right++;
        }

        return maxFruits;
    }
};

/*
Usage:
Solution obj;
int result = obj.totalFruit(fruits);
*/
