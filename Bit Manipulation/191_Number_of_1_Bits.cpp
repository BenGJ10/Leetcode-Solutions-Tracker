/*
191. Number of 1 Bits
Link: https://leetcode.com/problems/number-of-1-bits/

------------------------------------------------------
Problem Summary:
Given a positive integer `n`, return the **number of set bits**
(1's) present in its binary representation.

This is also known as the **Hamming Weight** of a number.

------------------------------------------------------
Example 1:
Input:
n = 11

Output:
3

Explanation:
11 → binary = 1011  
Number of 1's = 3

------------------------------------------------------
Example 2:
Input:
n = 128

Output:
1

Explanation:
128 → binary = 10000000  
Number of 1's = 1

------------------------------------------------------
Example 3:
Input:
n = 2147483645

Output:
30

------------------------------------------------------
Approach:
We repeatedly check the **least significant bit (LSB)**.

Steps:
1. If `(n & 1)` is 1 → increment count.
2. Right shift the number using `n >> 1`.
3. Repeat until number becomes 0.

Explanation:
- `n & 1` extracts the last bit.
- `n >> 1` removes the last bit.

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(log n)  
We process each bit of the number.

Space Complexity:
O(1)

------------------------------------------------------
Better Approach (Not implemented below):

Use **Brian Kernighan’s Algorithm**:

n = n & (n - 1)

Each operation removes the **lowest set bit**.

Example:
n = 101100
n-1 = 101011
AND = 101000

Time Complexity:
O(number of set bits)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int count(int num){
        int ones = 0;

        while(num > 1){
            ones += num & 1;
            num = num >> 1;
        }

        if(num == 1)
            ones++;

        return ones;
    }

    int hammingWeight(int n) {
        return count(n);
    }
};

/*
Usage:
Solution obj;
int result = obj.hammingWeight(n);
*/
