/*
1975. Maximum Matrix Sum
Link: https://leetcode.com/problems/maximum-matrix-sum/

------------------------------------------------------
Problem Summary:
You are given an n x n matrix of integers.

You are allowed to perform the following operation any number of times:
- Choose any two adjacent cells (sharing an edge)
- Multiply BOTH by -1

Goal:
Return the **maximum possible sum** of all matrix elements after any sequence of operations.

------------------------------------------------------
Key Observations:
✔ Flipping two adjacent numbers changes their signs together  
✔ The parity (even/odd) of the total number of negative values is invariant modulo operations  
✔ Therefore:
   - If the count of negative numbers is even → all can be made positive
   - If odd → exactly one number must remain negative, choose the smallest |value|

------------------------------------------------------
Example:
Input:
[[1,-1],[-1,1]]

Output:
4

Explanation:
Flip (-1,-1) pair → matrix becomes [[1,1],[1,1]]
Sum = 4 (maximum)

Example 2:
Input:
[[1,2,3],[ -1,-2,-3 ],[1,2,3]]

Output:
16

------------------------------------------------------
Brute Force Thinking (Why it fails):
Try all possible operations sequences.

However:
- Operation count is unbounded
- State space is exponential
- Hard to simulate efficiently

Not feasible.

------------------------------------------------------
Optimal Approach (Math + Greedy):
Idea:
1. Sum absolute values of all elements.
2. Count how many negative elements exist.
3. Track the **smallest absolute value** in the matrix.
4. If negative count is even:
   → We can convert all values to positive
   → Answer = sum of absolute values
5. If negative count is odd:
   → One smallest absolute value must remain negative
   → Subtract 2 * smallestAbs from total

Why?
Leaving a smallest absolute negative minimizes loss.

- Time Complexity: O(n²)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        long long negativeCount = 0;
        long long minValue = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) negativeCount++;
                sum += llabs(matrix[i][j]);
                minValue = min(minValue, llabs((long long)matrix[i][j]));
            }
        }

        if (negativeCount % 2 == 0) return sum;

        return sum - 2 * minValue;
    }
};

/*
Usage:
Solution obj;
long long result = obj.maxMatrixSum(matrix);
*/
