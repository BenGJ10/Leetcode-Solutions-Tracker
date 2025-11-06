/*
134. Gas Station
Link: https://leetcode.com/problems/gas-station/

------------------------------------------------------
Problem Summary:
There are `n` gas stations arranged in a circle, where:
- `gas[i]` is the amount of gas available at station `i`.
- `cost[i]` is the cost of gas to travel from station `i` to station `(i + 1)`.

You want to find the **starting gas station index** from which you can travel around the circle once,
if you start with an empty tank. Return the index if possible; otherwise, return `-1`.

------------------------------------------------------
Example 1:
Input:
gas = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output:
3

Explanation:
Start at station 3:
- Gas gained = 4 - 1 = +3
- Move to station 4 → +5 - 2 = +6
- Move to station 0 → +1 - 3 = +4
- Move to station 1 → +2 - 4 = +2
- Move to station 2 → +3 - 5 = 0 (successfully completed circle)

------------------------------------------------------
Example 2:
Input:
gas = [2,3,4]
cost = [3,4,3]

Output:
-1

Explanation:
No valid starting point exists.

------------------------------------------------------
Brute Force Approach:
1. For each index `i`, try starting from station `i`.
2. Simulate the entire circle.
3. If gas never drops below 0, return `i`.

- Time Complexity: O(n²)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Greedy Approach:
Idea:
- If total gas < total cost → impossible to complete the circuit.
- Otherwise, there exists exactly one valid starting station.
- Use a greedy approach:
  - Track `currGas = gas[i] - cost[i]`.
  - If `currGas` becomes negative, reset it and move the start index to `i + 1`.
  - The idea: all previous stations can’t be starting points if `currGas` < 0.

Steps:
1. Compute total gas and total cost.
2. Traverse the array:
   - Add `(gas[i] - cost[i])` to `currGas`.
   - If `currGas` < 0, reset `currGas = 0` and move `startIndex = i + 1`.
3. After loop:
   - If totalGas < totalCost → return -1.
   - Else → return `startIndex`.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int currGas = 0, startIndex = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currGas += (gas[i] - cost[i]);

            if (currGas < 0) {
                currGas = 0;
                startIndex = i + 1; // next station becomes potential start
            }
        }

        return totalCost > totalGas ? -1 : startIndex;
    }
};

/*
Usage:
Solution obj;
int result = obj.canCompleteCircuit(gas, cost);
*/
