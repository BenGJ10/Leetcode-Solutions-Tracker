/*
2220. Minimum Bit Flips to Convert Number
Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

------------------------------------------------------
Problem Summary:
Given two integers `start` and `goal`, return the **minimum number
of bit flips required** to convert `start` into `goal`.

A **bit flip** means changing a bit from:
0 → 1 or 1 → 0.

------------------------------------------------------
Example 1:
Input:
start = 10
goal = 7

Output:
3

Explanation:

start = 10 → 1010
goal  = 7  → 0111

XOR result:
1010
0111
----
1101

Number of 1's in XOR = 3 → minimum flips required.

------------------------------------------------------
Example 2:
Input:
start = 3
goal = 4

Output:
3

Explanation:

3 → 011
4 → 100

XOR → 111 → three flips needed.

------------------------------------------------------
Key Idea:
If two bits are **different**, they must be flipped.

XOR operation helps detect this.

Rules of XOR:
0 ^ 0 = 0
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1

So:
start ^ goal → gives 1 at positions where bits differ.

Therefore:
Minimum flips = number of set bits in (start ^ goal).

------------------------------------------------------
Approach:
1. Compute `xorValue = start ^ goal`.
2. Count number of set bits in `xorValue`.
3. Return the count.

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(log N)  
(We process each bit of the number.)

Space Complexity:
O(1)

------------------------------------------------------
Better Approach (Not implemented below):

Using **Brian Kernighan’s Algorithm** for faster bit counting.

Idea:
Repeatedly remove the lowest set bit.

n = n & (n - 1)

Each iteration removes one set bit.

Time Complexity:
O(number of set bits)

Which can be faster than O(log N) in practice.

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

    int minBitFlips(int start, int goal) {
        int flipsReq = count(start ^ goal);
        return flipsReq;
    }
};

/*
Usage:
Solution obj;
int result = obj.minBitFlips(start, goal);
*/