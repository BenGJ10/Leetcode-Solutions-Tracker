/*
3043. Find the Length of the Longest Common Prefix
Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

------------------------------------------------------
Problem Summary:
You are given two integer arrays `arr1` and `arr2`.
You need to find the **length of the longest common prefix** between 
any number in `arr1` and any number in `arr2`.

Example:
arr1 = [123, 456, 789]
arr2 = [124, 457]
=> Longest common prefix: "12" (length = 2)

------------------------------------------------------
Brute Force Approach:
1. Convert each number in `arr1` and `arr2` to strings.
2. Compare every pair `(num1, num2)` to find their common prefix.
3. Keep track of the longest prefix length.
- Time Complexity: O(N * M * L), where L = max digit length.

------------------------------------------------------
Optimal Approach (Prefix Hashing with HashMap):

Idea:
- Store all prefixes of each number in `arr1` inside a hash map.
- For each number in `arr2`, build prefixes and check if they exist in the map.
- Keep track of the maximum prefix length found.

Steps:
1. For each number in `arr1`, generate all its prefixes and store them in a map.
2. For each number in `arr2`, check all prefixes against the map.
3. Update `maxLen` if a match is found.

- Time Complexity: O(N * L + M * L),  
  where N = size of arr1, M = size of arr2, L = average number length.
- Space Complexity: O(N * L) for storing prefixes.

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mpp;
        
        for (int num : arr1) {
            string numStr = to_string(num);
            string prefix = "";
            for (char ch : numStr) {
                prefix += ch;
                mpp[prefix]++;
            }
        }

        int maxLen = 0;
        for (int num : arr2) {
            string numStr = to_string(num);
            string prefix = "";
            for (char ch : numStr) {
                prefix += ch;
                if (mpp.find(prefix) != mpp.end()) {
                    maxLen = max(maxLen, (int)prefix.length());
                }
            }
        }
        return maxLen;
    }
};

/*
Usage:
Solution sol;
vector<int> arr1 = {123, 456, 789};
vector<int> arr2 = {124, 457};
int res = sol.longestCommonPrefix(arr1, arr2); // Output: 2
*/
