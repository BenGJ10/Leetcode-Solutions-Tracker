/*
860. Lemonade Change
Link: https://leetcode.com/problems/lemonade-change/

------------------------------------------------------
Problem Summary:
You are a lemonade seller. Each lemonade costs $5.
Customers pay with either $5, $10, or $20 bills, in the order they appear.

You must provide the correct change to each customer immediately using the bills you currently have.
Return `true` if you can provide change to every customer, otherwise return `false`.

------------------------------------------------------
Brute Force Approach:
1. Simulate each transaction keeping track of all bills.
2. When a $10 or $20 bill comes, try to form $5 or $15 change by checking possible combinations of existing bills.
3. This can become inefficient for large input sizes.

- Time Complexity: O(n²) in the worst case (if searching combinations for change)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Greedy Simulation):
Idea:
- Always prioritize using larger denominations first for change.
  - For a $10 bill → give one $5 bill.
  - For a $20 bill → prefer giving $10 + $5 (to save $5 bills).
  - If not possible, give three $5 bills.
- Keep counters for number of $5 and $10 bills.

Steps:
1. Initialize counters: `fives = 0`, `tens = 0`.
2. Traverse the `bills` array.
   - If `bills[i] == 5`: increment `fives`.
   - If `bills[i] == 10`: check if at least one $5 exists.
   - If `bills[i] == 20`: check for $10 + $5 combo; otherwise 3×$5.
3. If any transaction fails, return `false`.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                fives++;
            } 
            else if (bills[i] == 10) {
                if (fives > 0) {
                    fives--;
                    tens++;
                } else {
                    return false;
                }
            } 
            else { // bills[i] == 20
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } 
                else if (fives >= 3) {
                    fives -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
Usage:
Solution obj;
bool result = obj.lemonadeChange(bills);
*/
