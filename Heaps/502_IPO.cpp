/*
502. IPO
Link: https://leetcode.com/problems/ipo/

------------------------------------------------------
Problem Summary:
You are given `k` (the maximum number of projects you can complete) and `w`
(your initial capital). You are also given two integer arrays:
- `profits[i]`: the profit from completing the i-th project
- `capital[i]`: the minimum capital required to start the i-th project

You can start any project for which you have enough capital.
After completing a project, you gain its profit and add it to your total capital.
Return the maximum capital you can accumulate after completing at most `k` projects.

------------------------------------------------------
Example:
Input:
k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]

Output:
4

Explanation:
- Initially, capital = 0 → can start projects requiring ≤ 0.
- Pick project with profit = 1 (capital = 0 → now 1).
- Next, can start projects requiring ≤ 1 → pick project with profit = 3.
- Total capital = 4.

------------------------------------------------------
Brute Force Approach:
1. For each project, check which ones are affordable.
2. Pick the project with the maximum profit.
3. Repeat k times or until no more affordable projects.
- Time Complexity: O(k * n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Sorting + Max-Heap):
Idea:
- Pair up each project’s (capital, profit).
- Sort projects by required capital.
- Maintain a max-heap of profits for projects affordable with current capital `w`.
- Iteratively:
    - Push all projects whose capital ≤ w into the max-heap.
    - Pop the most profitable project and add its profit to w.
    - Repeat k times or until no more projects can be chosen.

Steps:
1. Create vector of (capital, profit) pairs.
2. Sort by capital ascending.
3. Maintain a max-heap for profits.
4. For up to k iterations:
   - Add all affordable projects to heap.
   - Choose the one with max profit and update capital.
5. Return final capital.

- Time Complexity: O(n log n + k log n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> affordable;
        for (int i = 0; i < n; i++) {
            affordable.push_back({capital[i], profits[i]});
        }
        sort(affordable.begin(), affordable.end());

        priority_queue<int> pq;
        int i = 0;
        
        while (k--) {
            while (i < n && affordable[i].first <= w) {
                pq.push(affordable[i].second);
                i++;
            }
            if (pq.empty()) break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};

/*
Usage:
Solution obj;
int result = obj.findMaximizedCapital(k, w, profits, capital);
*/
