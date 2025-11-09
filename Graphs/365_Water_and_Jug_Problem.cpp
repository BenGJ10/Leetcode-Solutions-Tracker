/*
365. Water and Jug Problem
Link: https://leetcode.com/problems/water-and-jug-problem/

------------------------------------------------------
Problem Summary:
You are given two jugs with capacities `x` and `y` liters, respectively.
You need to determine whether it is possible to measure exactly `target` liters of water
using the two jugs.

Operations allowed:
1. Fill any jug completely.
2. Empty any jug.
3. Pour water from one jug to the other until one becomes full or empty.

Return `true` if it is possible to measure exactly `target` liters, otherwise `false`.

------------------------------------------------------
Example 1:
Input:
x = 3, y = 5, target = 4

Output:
true

Explanation:
One possible sequence:
- Fill jug 2 (5,0)
- Pour jug 2 into jug 1 (3,2)
- Empty jug 1 (0,2)
- Pour jug 2 into jug 1 (2,0)
- Fill jug 2 (2,5)
- Pour jug 2 into jug 1 (3,4)
Now jug 2 contains exactly 4 liters.

Example 2:
Input:
x = 2, y = 6, target = 5

Output:
false

------------------------------------------------------
Brute Force Approach (BFS Simulation):
Idea:
- Each state can be represented as (a, b) where:
  - a = current water in jug 1
  - b = current water in jug 2
- From each state, you can perform one of 6 operations:
  1. Fill jug 1
  2. Fill jug 2
  3. Empty jug 1
  4. Empty jug 2
  5. Pour water from jug 1 → jug 2
  6. Pour water from jug 2 → jug 1
- Use BFS to explore all possible states until we reach one where
  `a == target`, `b == target`, or `a + b == target`.

- Time Complexity: O(x * y) — every state (a,b) is unique.
- Space Complexity: O(x * y) — to store visited states.

------------------------------------------------------
Mathematical Shortcut (Optional):
It’s also possible to solve this using Bézout’s theorem:
`target` is measurable iff `target % gcd(x, y) == 0` and `target <= x + y`.

But the BFS simulation here demonstrates an explicit state-based search.

------------------------------------------------------
*/

#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        
        set<pair<int, int>> vis;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis.insert({0, 0});

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            if (a == target || b == target || a + b == target) return true;

            vector<pair<int, int>> states;

            // Fill jug 1
            states.push_back({x, b});
            // Fill jug 2
            states.push_back({a, y});
            // Empty jug 1
            states.push_back({0, b});
            // Empty jug 2
            states.push_back({a, 0});
            // Pour jug 1 → jug 2
            int pour = min(a, y - b);
            states.push_back({a - pour, b + pour});
            // Pour jug 2 → jug 1
            pour = min(x - a, b);
            states.push_back({a + pour, b - pour});

            for (auto &state : states) {
                if (!vis.count(state)) {
                    vis.insert(state);
                    q.push(state);
                }
            }
        }
        return false;
    }
};

/*
Usage:
Solution obj;
bool result = obj.canMeasureWater(x, y, target);
*/
