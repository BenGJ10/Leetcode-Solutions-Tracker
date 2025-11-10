/*
841. Keys and Rooms
Link: https://leetcode.com/problems/keys-and-rooms/

------------------------------------------------------
Problem Summary:
You are given a list of rooms, where each room contains keys to other rooms.
- `rooms[i]` is a list of keys you can use to open room `i`.
- You start in room `0`, which is already unlocked.
Your goal is to determine whether you can visit **all** the rooms.

Return `true` if all rooms can be visited, otherwise return `false`.

------------------------------------------------------
Example:
Input:
rooms = [[1],[2],[3],[]]

Output:
true

Explanation:
- Start at room 0 → key to room 1
- Enter room 1 → key to room 2
- Enter room 2 → key to room 3
- Enter room 3 → no keys
Visited all rooms.

Example 2:
Input:
rooms = [[1,3],[3,0,1],[2],[0]]

Output:
false

------------------------------------------------------
Brute Force Approach:
1. Keep checking unlocked rooms repeatedly.
2. Each time, add new rooms that can be visited.
3. Stop when no new rooms can be reached.

- Time Complexity: O(n²)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (BFS Traversal):
Idea:
- Treat each room as a node in a graph.
- Keys represent edges leading to other nodes.
- Use BFS starting from room 0.
- Track visited rooms using a set.
- Add new rooms to the queue only if they haven't been visited.

Steps:
1. Push room 0 into a queue.
2. Keep popping from queue and visit the room.
3. For each key in the current room, if not visited, push it into queue.
4. Continue until queue is empty.
5. Check if visited rooms == total rooms.

- Time Complexity: O(n + total_keys)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int room = q.front(); q.pop();
            visited.insert(room);
            
            for (int &key : rooms[room]) {
                if (visited.find(key) == visited.end()) {
                    q.push(key);
                }
            }
        }
        return visited.size() == rooms.size();
    }
};

/*
Usage:
Solution obj;
bool result = obj.canVisitAllRooms(rooms);
*/
