/*

3100. Water Bottles II
Link: https://leetcode.com/problems/water-bottles-ii/description/

------------------------------------------------------
Problem Summary:
You have `numBottles` full water bottles and an exchange rule defined by `numExchange` — 
the number of empty bottles required to get one full bottle.

Each time you perform an exchange:
- You lose `numExchange` empty bottles.
- You gain 1 new full bottle.
- After drinking that bottle, you get 1 new empty bottle.

Additionally, after every exchange, the required number of bottles for the next exchange 
(`numExchange`) increases by 1.

Return the **maximum number of bottles you can drink** in total.

------------------------------------------------------
Example 1:
Input:
numBottles = 13, numExchange = 6

Output:
15

Explanation:
1. Drink 13 bottles → 13 empty bottles.
2. Exchange 6 empties → +1 full, `numExchange = 7`, empties left = 8.
3. Drink 1 more bottle → empties = 9.
4. Exchange 7 empties → +1 full, `numExchange = 8`, empties left = 3.
5. Drink 1 bottle → empties = 4.
6. Cannot exchange anymore (need 8 empties).

Total = 15 bottles drunk.

------------------------------------------------------
Brute Force Approach:
1. Simulate the process step-by-step.
2. Each iteration:
   - Drink all full bottles.
   - Add them to empty count.
   - If enough empties → exchange for one full bottle.
   - Increase `numExchange` after every exchange.
3. Stop when not enough empty bottles to exchange.

- Time Complexity: O(numBottles + number_of_exchanges)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Greedy Simulation):
Idea:
- Keep track of `totalBottles` (total drunk) and `emptyBottles` (currently available empties).
- At each step:
  - Add all current full bottles to `totalBottles`.
  - Convert them into empty bottles.
  - While `emptyBottles >= numExchange`, perform one exchange:
    - Subtract `numExchange`, increment `numBottles`, and increase `numExchange` by 1.
- Stop when not enough empties for the next exchange.

- Time Complexity: O(numBottles)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalBottles = 0, emptyBottles = 0;

        while (true) {
            totalBottles += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;

            if (emptyBottles >= numExchange) {
                emptyBottles -= numExchange;
                numExchange++;
                numBottles++;
            } else {
                break;
            }
        }
        return totalBottles;
    }
};

/*
Usage:
Solution obj;
int result = obj.maxBottlesDrunk(numBottles, numExchange);
*/
