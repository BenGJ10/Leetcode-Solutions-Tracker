/*
1411. Number of Ways to Paint N × 3 Grid
Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/

------------------------------------------------------
Problem Summary:
You are painting an n x 3 grid, where each cell can be one of 3 colors:
- red
- yellow
- green

Rules:
- No two adjacent cells in the same row may have the same color.
- No two adjacent cells in the same column may have the same color.

Return the **number of valid ways** to paint the grid, modulo 1e9+7.

------------------------------------------------------
Example:
Input:
n = 1

Output:
12

Explanation:
For one row:
- 6 ways where all 3 colors are distinct (ABC permutations)
- 6 ways where exactly 2 colors are used (AAB pattern arrangements)
Total = 12

------------------------------------------------------
Brute Force Approach:
Try all possible colorings and validate constraints.

- Total states = 3^(3n)
- Time Complexity: O(3^(3n))
- Space Complexity: O(1)

This approach is infeasible for n up to 5000.

------------------------------------------------------
Optimal Approach (Dynamic Programming with State Compression Insight):
Observation:

For each row, there are only 2 valid pattern types:

1. **Type A (threeColorCombo)**  
   → All 3 colors different  
   → Count per row: 6   (ABC permutations)

2. **Type B (twoColorCombo)**  
   → Exactly 2 colors used (like AAB, ABA, BAA)  
   → Count per row: 6

Transitions between rows:

Let:
- `threeColorCombo` = number of ways current row is Type A
- `twoColorCombo`   = number of ways current row is Type B

From previous row:

Type A → next Type A: 2 ways  
Type A → next Type B: 2 ways  
Type B → next Type A: 2 ways  
Type B → next Type B: 3 ways  

Recurrence:

threeColorCombo' = 2*A + 2*B  
twoColorCombo'   = 2*A + 3*B  

Initialize for n = 1:

A = 6  
B = 6  

Iterate up to n, always mod 1e9+7.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long threeColorCombo = 6; // ABC permutations
        long twoColorCombo = 6;   // AAB-style permutations

        for (int i = 2; i <= n; i++) {
            long temp = threeColorCombo;

            threeColorCombo = (2 * threeColorCombo + 2 * twoColorCombo) % MOD;
            twoColorCombo   = (3 * twoColorCombo + 2 * temp) % MOD;
        }

        return (threeColorCombo + twoColorCombo) % MOD;
    }
};

/*
Usage:
Solution obj;
int result = obj.numOfWays(n);
*/

