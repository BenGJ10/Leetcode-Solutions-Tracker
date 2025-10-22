/*
621. Task Scheduler
Link: https://leetcode.com/problems/task-scheduler/

------------------------------------------------------
Problem Summary:
You are given a list of tasks represented by characters (e.g., ['A','A','B','B']) 
and an integer n representing the cooldown interval between two same tasks.  
Each task takes 1 unit of time to execute.  
Return the least number of units of time required to finish all tasks.

Example:
Input: tasks = ['A','A','A','B','B','B'], n = 2  
Output: 8  
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B

------------------------------------------------------
Brute Force Approach:
1. Keep a time counter and simulate each unit of time.
2. Pick the most frequent available task that isn’t in cooldown.
3. Use a map to track cooldown for each task.
- Time Complexity: O(n^2)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Max Heap + Cooldown Simulation):

Idea:
- Always execute the most frequent remaining task first.
- Use a max heap to pick the task with the highest frequency.
- For each cycle of (n + 1) units:
  * Pop up to (n + 1) most frequent tasks.
  * Execute them and reduce their counts.
  * Push remaining counts back to heap.
- If heap is not empty after a cycle, add idle time for remaining slots.

Steps:
1. Count frequency of each task.
2. Push all frequencies into a max heap.
3. While heap not empty:
   - Execute up to (n + 1) tasks.
   - Decrease their frequencies and store back unfinished ones.
   - Add idle time if needed (when heap not empty).

- Time Complexity: O(N log 26) ≈ O(N)
- Space Complexity: O(26) ≈ O(1)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for (char &task : tasks) {
            mpp[task]++;
        }

        priority_queue<int> pq;
        for (auto &elem : mpp) {
            pq.push(elem.second);
        }

        int time = 0;
        while (!pq.empty()) {
            int cycles = n + 1;
            vector<int> temp;

            while (!pq.empty() && cycles > 0) {
                int freq = pq.top(); pq.pop();
                freq--;
                if (freq > 0) temp.push_back(freq);
                time++;
                cycles--;
            }

            for (int f : temp) pq.push(f);

            // Add idle time if tasks are still pending
            if (!pq.empty()) time += cycles;
        }

        return time;
    }
};

/*
Usage:
Solution sol;
vector<char> tasks = {'A','A','A','B','B','B'};
int time = sol.leastInterval(tasks, 2); // Output: 8
*/
