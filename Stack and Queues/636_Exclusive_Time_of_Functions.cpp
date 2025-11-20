/*
636. Exclusive Time of Functions
Link: https://leetcode.com/problems/exclusive-time-of-functions/

------------------------------------------------------
Problem Summary:
You are given `n` functions identified by IDs from `0` to `n-1`, and a list of logs
where each log entry is in the form:
    "function_id:start_or_end:timestamp"

Each function may call other functions (nested calls).  
You must compute the **exclusive time** of each function, meaning the total time spent 
executing that function **excluding** the time spent in its subcalls.

Return an array where `result[i]` is the exclusive time of function `i`.

------------------------------------------------------
Example:
Input:
n = 2
logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]

Output:
[3,4]

Explanation:
Function 0:
- Executes from [0,1] → 2 units
- Paused because function 1 starts
- Resumes from [6,6] → 1 unit
Total = 3

Function 1:
- Executes from [2,5]
Total = 4

------------------------------------------------------
Brute Force Approach:
1. Simulate the execution timeline second-by-second.
2. Track which function is executing at each time.
3. Count durations individually.

- Time Complexity: O(T) where T = total timestamps
- Space Complexity: O(T)

Not feasible for large timestamps.

------------------------------------------------------
Optimal Approach (Stack + Time Tracking):
Idea:
- Use a stack to simulate function call behavior.
- When a function starts:
  - Add the gap (current_time - prevTime) to the function currently on the stack.
  - Push the new function on the stack.
- When a function ends:
  - Add (current_time - prevTime + 1) to the function on top.
  - Pop it.
  - Move prevTime to (current_time + 1).

Key logic:
- `prevTime` tracks when the last meaningful event happened.
- End timestamps are inclusive, so we add `+1`.

Steps:
1. Initialize `result[n]`, `stack`, and `prevTime = 0`.
2. Parse each log into: `id`, `type`, `time`.
3. Apply the above stack rules.
4. Return `result`.

- Time Complexity: O(n + logs)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (string &log : logs) {
            int pos1 = log.find(':');
            int pos2 = log.find(':', pos1 + 1);

            int id = stoi(log.substr(0, pos1));
            string type = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int time = stoi(log.substr(pos2 + 1));

            if (type == "start") {
                if (!st.empty()) {
                    result[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } else { // "end"
                result[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return result;
    }
};

/*
Usage:
Solution obj;
vector<int> result = obj.exclusiveTime(n, logs);
*/
