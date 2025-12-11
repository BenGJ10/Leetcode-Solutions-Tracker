/*
2352. Equal Row and Column Pairs
Link: https://leetcode.com/problems/equal-row-and-column-pairs/

------------------------------------------------------
Problem Summary:
You are given an n × n integer matrix `grid`.

A pair `(r, c)` is considered **equal** if:
- Row `r` is identical to column `c`.

Your task is to count how many such pairs exist.

------------------------------------------------------
Example:
Input:
grid = [
  [3,2,1],
  [1,7,6],
  [2,7,7]
]

Output:
1

Explanation:
Only row 0 matches column 0 → [3,2,1].

------------------------------------------------------
Brute Force Approach:
For every row, for every column:
- Compare the entire row with the column.
- If all values match, count it.

- Time Complexity: O(n³)
- Space Complexity: O(n)

Too slow for large n.

------------------------------------------------------
Optimal Approach (Hashing Vectors):
Idea:
- Hash each row and store in a map: freq[row]++
- For each column, build its vector representation.
- Lookup column vector in the map:
    If exists, add its frequency to `pairs`.

Why this works:
- A column that matches k identical rows contributes exactly k matching pairs.

Steps:
1. Build a map `mpp` storing frequency of every row.
2. For each column index:
   - Construct the column as a vector.
   - If exists in map, add mpp[column] to the answer.
3. Return total count.

- Time Complexity: O(n²)
- Space Complexity: O(n²)

------------------------------------------------------
*/

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int pairs = 0;

        map<vector<int>, int> mpp;

        // Store frequency of all rows
        for (int i = 0; i < n; i++) {
            mpp[grid[i]]++;
        }

        // For each column, form its vector and compare
        for (int col = 0; col < n; col++) {
            vector<int> colVec;
            for (int row = 0; row < n; row++) {
                colVec.push_back(grid[row][col]);
            }
            if (mpp.find(colVec) != mpp.end()) {
                pairs += mpp[colVec];
            }
        }

        return pairs;
    }
};

/*
Usage:
Solution obj;
int result = obj.equalPairs(grid);
*/
