/*
135. Candy
Link: https://leetcode.com/problems/candy/

------------------------------------------------------
Problem Summary:
There are `n` children standing in a line, each with a rating value given in the array `ratings`.

You need to distribute candies to these children following two rules:
1. Each child must have at least one candy.
2. Children with a higher rating than their immediate neighbors must get more candies.

Return the **minimum number of candies** you must give to satisfy the conditions.

------------------------------------------------------
Example 1:
Input:
ratings = [1,0,2]

Output:
5

Explanation:
You can distribute candies as [2,1,2].
- Child 0 → 2 candies (higher than next child)
- Child 1 → 1 candy
- Child 2 → 2 candies (higher than previous)

Example 2:
Input:
ratings = [1,2,2]

Output:
4

Explanation:
Candies can be distributed as [1,2,1].

------------------------------------------------------
Brute Force Approach:
1. Start by giving 1 candy to each child.
2. Repeatedly loop over the array:
   - If `ratings[i] > ratings[i-1]` and `candies[i] <= candies[i-1]`, increment `candies[i]`.
   - If `ratings[i] < ratings[i-1]` and `candies[i] >= candies[i-1]`, increment `candies[i-1]`.
3. Repeat until stable.

- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Greedy - Peak & Valley Count):
Idea:
We can visualize the ratings as a **mountain range** with rising (peak) and falling (valley) slopes.
- Each child starts with 1 candy.
- As ratings increase, give +1 candy successively.
- As ratings decrease, also give +1 successively but ensure the overlap (peak child) is not overcounted.

Steps:
1. Initialize `sum = n` (every child gets at least one candy).
2. Traverse ratings using index `i`:
   - For every **increasing slope**, count candies needed for upward children (`peak`).
   - For every **decreasing slope**, count candies needed for downward children (`valley`).
   - Subtract `min(peak, valley)` since the peak child was counted twice.
3. Return `sum`.

- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = n, i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }

            int valley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                valley++;
                sum += valley;
                i++;
            }

            sum -= min(peak, valley); // avoid double counting peak
        }

        return sum;
    }
};

/*
Usage:
Solution obj;
int result = obj.candy(ratings);
*/
