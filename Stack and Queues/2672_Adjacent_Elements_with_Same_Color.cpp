/*
2672. Number of Adjacent Elements With the Same Color
Link: https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/

------------------------------------------------------
Problem Summary:
You are given an integer `n` representing an array of size `n`,
initially filled with 0s (uncolored).

You are also given `queries`, where each query is:
[index, color]

For each query:
- Paint the element at `index` with `color`
- Return the number of **adjacent pairs with the same color**

Note:
- Only count pairs (i, i+1)
- Ignore elements with color = 0

------------------------------------------------------
Example 1:
Input:
n = 4
queries = [[0,1],[1,1],[2,2],[1,2]]

Output:
[0,1,1,0]

Explanation:

Step 1: [1,0,0,0] → 0 pairs  
Step 2: [1,1,0,0] → 1 pair (0,1)  
Step 3: [1,1,2,0] → 1 pair (0,1)  
Step 4: [1,2,2,0] → 1 pair (1,2) but (0,1) breaks → total 1  

------------------------------------------------------
Approach (Simulation + Local Adjustment):

Idea:
- Maintain a `colors` array
- Track current number of valid adjacent pairs (`adjPairs`)
- For each query:
    1. Remove contribution of old color (if exists)
    2. Apply new color
    3. Add contribution of new color

We only check **neighbors (index-1, index+1)**  
→ O(1) work per query

------------------------------------------------------
Steps:

For each query:
1. If current index already colored:
   - If it forms a pair with left → decrement
   - If it forms a pair with right → decrement

2. Update color

3. If new color forms a pair with left → increment  
4. If new color forms a pair with right → increment  

5. Store result

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(q)  
(q = number of queries)

Space Complexity:
O(n)

------------------------------------------------------
Key Insight:
Instead of recomputing all adjacent pairs after each query,
we only adjust the **local effect** of the updated index.

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {

        vector<int> colors(n, 0);
        vector<int> result;
        int adjPairs = 0;

        for(auto &query: queries){

            int index = query[0];
            int color = query[1];
            
            // Remove previous contribution
            if(colors[index] != 0){
                if(index - 1 >= 0 && colors[index] == colors[index - 1]){
                    adjPairs--;
                }
                if(index + 1 < n && colors[index] == colors[index + 1]){
                    adjPairs--;
                }
            }
            
            // Apply new color
            colors[index] = color;

            // Add new contribution
            if(colors[index] != 0){
                if(index - 1 >= 0 && colors[index] == colors[index - 1]){
                    adjPairs++;
                }
                if(index + 1 < n && colors[index] == colors[index + 1]){
                    adjPairs++;
                }
            }
            
            result.push_back(adjPairs);
        }

        return result;
    }
};

/*
Usage:
Solution obj;
vector<int> result = obj.colorTheArray(n, queries);
*/