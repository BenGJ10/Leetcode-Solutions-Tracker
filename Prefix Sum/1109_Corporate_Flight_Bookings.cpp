/*
1109. Corporate Flight Bookings
Link: https://leetcode.com/problems/corporate-flight-bookings/

------------------------------------------------------
Problem Summary:
You are given:
- An integer `n` representing `n` flights numbered from 1 to n.
- A list `bookings`, where each booking is represented as:
    [firstFlight, lastFlight, seats]

Each booking means that `seats` seats are reserved on **every flight**
from `firstFlight` to `lastFlight` (inclusive).

Return an array `answer` of length `n`, where:
- answer[i] represents the total number of seats booked for flight `i + 1`.

------------------------------------------------------
Example:
Input:
bookings = [[1,2,10],[2,3,20],[2,5,25]]
n = 5

Output:
[10,55,45,25,25]

Explanation:
- Flights 1–2 get +10
- Flights 2–3 get +20
- Flights 2–5 get +25

------------------------------------------------------
Brute Force Approach:
For each booking:
1. Iterate from `firstFlight` to `lastFlight`.
2. Add seats to every flight in that range.

- Time Complexity: O(m * n)
- Space Complexity: O(n)

This approach causes TLE for large inputs.

------------------------------------------------------
Optimal Approach (Difference Array + Prefix Sum):
Idea:
Instead of updating each flight individually, use a **difference array**.

For a booking [f, l, s]:
- Add `s` at index `f-1`
- Subtract `s` at index `l` (if l < n)

After processing all bookings:
- Take prefix sum to get final seat counts.

Why it works:
- Difference array efficiently represents range updates.
- Prefix sum reconstructs the actual values.

Steps:
1. Initialize an array `reservedSeats` of size `n` with zeros.
2. For each booking:
   - reservedSeats[f - 1] += s
   - reservedSeats[l] -= s (if l < n)
3. Convert difference array to actual values using prefix sum.
4. Return result.

- Time Complexity: O(n + m)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> reservedSeats(n, 0);

        // Apply difference array updates
        for (auto &booking : bookings) {
            int f = booking[0];
            int l = booking[1];
            int s = booking[2];

            reservedSeats[f - 1] += s;
            if (l < n) reservedSeats[l] -= s;
        }

        // Build prefix sum to get final result
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += reservedSeats[i];
            reservedSeats[i] = prefixSum;
        }

        return reservedSeats;
    }
};

/*
Usage:
Solution obj;
vector<int> result = obj.corpFlightBookings(bookings, n);
*/
