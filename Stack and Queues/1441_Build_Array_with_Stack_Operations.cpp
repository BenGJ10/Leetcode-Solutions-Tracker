/*
1441. Build an Array With Stack Operations
Link: https://leetcode.com/problems/build-an-array-with-stack-operations/

------------------------------------------------------
Problem Summary:
You are given a strictly increasing array `target` and an integer `n`.
You must build the array `target` using the following stack operations applied 
on numbers from 1 to n (in order):

Operations allowed:
- "Push": push the current number into the array.
- "Pop": remove the last pushed number (only valid if the stack is not empty).

You must return the **list of operations** needed to build the target array.

------------------------------------------------------
Example 1:
Input:
target = [1,3], n = 3

Output:
["Push","Push","Pop","Push"]

Explanation:
- Read 1 → Push
- Read 2 → Push, Pop (since 2 not in target)
- Read 3 → Push

------------------------------------------------------
Example 2:
Input:
target = [1,2,3], n = 3

Output:
["Push","Push","Push"]

------------------------------------------------------
Brute Force Approach:
1. For each number from 1 to n:
   - Push the number.
   - If it is not in the target, perform a Pop.
   - Stop once we’ve constructed the entire target.
2. This uses extra checks to match numbers with the target array.

- Time Complexity: O(n)
- Space Complexity: O(1) (excluding output list)

------------------------------------------------------
Optimal Approach (Direct Simulation):
Idea:
- We only need to simulate operations from 1 up to `target.back()`.
- For each number `i`:
  - Push it.
  - If `i` is not equal to the next required number in `target`, Pop it.
  - Otherwise, keep it and move to the next target element.

Steps:
1. Initialize `j = 0` as target pointer.
2. Loop `i` from 1 → target.last():
   - Push.
   - If `i == target[j]`, increment `j`.
   - Else Pop.
3. Return the list of operations.

- Time Complexity: O(target.back())
- Space Complexity: O(target.back())

------------------------------------------------------
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> resultStack;
        int j = 0;

        for (int i = 1; i <= target.back(); i++) {
            resultStack.push_back("Push");

            if (i == target[j]) {
                j++;
            } else {
                resultStack.push_back("Pop");
            }
        }
        return resultStack;
    }
};

/*
Usage:
Solution obj;
vector<string> ops = obj.buildArray(target, n);
*/
