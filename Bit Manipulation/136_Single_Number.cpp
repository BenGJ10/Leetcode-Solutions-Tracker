/*
136. Single Number
Link: https://leetcode.com/problems/single-number/

------------------------------------------------------
Problem Summary:
Given a **non-empty array of integers `nums`**, every element
appears **twice except for one**. Find that **single number**.

You must implement a solution with:
- Linear runtime complexity
- Constant extra space

------------------------------------------------------
Example 1:
Input:
nums = [2,2,1]

Output:
1

------------------------------------------------------
Example 2:
Input:
nums = [4,1,2,1,2]

Output:
4

------------------------------------------------------
Example 3:
Input:
nums = [1]

Output:
1

------------------------------------------------------
Key Idea (XOR Property):

XOR has important properties:

1. a ^ a = 0
2. a ^ 0 = a
3. XOR is commutative and associative

Example:
nums = [4,1,2,1,2]

Step-by-step XOR:

x = 0
x = 0 ^ 4 = 4
x = 4 ^ 1 = 5
x = 5 ^ 2 = 7
x = 7 ^ 1 = 6
x = 6 ^ 2 = 4

All duplicate numbers cancel out.

Remaining value → single number.

------------------------------------------------------
Approach:
1. Initialize `x = 0`.
2. XOR every element with `x`.
3. Duplicate numbers cancel each other.
4. The final value of `x` will be the single number.

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(n)

Space Complexity:
O(1)

------------------------------------------------------
Alternative Approach (Not implemented below):

Using a **HashSet**

1. Insert numbers into a set.
2. If number already exists → remove it.
3. The remaining element is the answer.

Time Complexity: O(n)  
Space Complexity: O(n)

But XOR is preferred since it uses **constant space**.

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int x = 0;

        for(int i = 0; i < nums.size(); i++){
            x = x ^ nums[i];
        }

        return x;
    }
};

/*
Usage:
Solution obj;
int result = obj.singleNumber(nums);
*/