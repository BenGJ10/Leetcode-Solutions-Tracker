/*
2523. Closest Prime Numbers in Range
Link: https://leetcode.com/problems/closest-prime-numbers-in-range/

------------------------------------------------------
Problem Summary:
Given two integers `left` and `right`,
return two integers representing the two prime numbers
within the range [left, right] that have the minimum difference.

If multiple pairs exist, return the pair with the smallest first number.
If no such pair exists, return {-1, -1}.

------------------------------------------------------
Example 1:
Input:
left = 10, right = 19

Output:
[11, 13]

Explanation:
Primes in range: 11, 13, 17, 19
Closest pair: (11, 13)

------------------------------------------------------
Example 2:
Input:
left = 4, right = 6

Output:
[-1, -1]

Explanation:
Only one prime (5), so no pair exists.

------------------------------------------------------
Brute Force Approach:
For each number in range:
- Check if prime using sqrt method.
- Store primes.
- Compare adjacent primes.

Time Complexity: O(n * sqrt(n))
Too slow for large ranges.

------------------------------------------------------
Optimal Approach (Sieve of Eratosthenes):
Idea:
1. Use Sieve to generate all primes up to `right`.
2. Traverse from `left` to `right`.
3. Track:
   - Previous prime
   - Minimum distance
4. Update answer whenever a smaller gap is found.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n log log n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        if (right < 2) return {-1, -1};

        vector<int> primes(right + 1, 1);
        primes[0] = primes[1] = 0;

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= right; i++) {
            if (primes[i] == 1) {
                for (int j = i * i; j <= right; j += i) {
                    primes[j] = 0;
                }
            }
        }

        int minDist = INT_MAX;
        int prevPrime = -1;
        int prime1 = -1, prime2 = -1;

        for (int i = left; i <= right; i++) {
            if (i >= 2 && primes[i] == 1) {

                if (prevPrime != -1) {
                    if (i - prevPrime < minDist) {
                        minDist = i - prevPrime;
                        prime1 = prevPrime;
                        prime2 = i;
                    }
                }

                prevPrime = i;
            }
        }

        return {prime1, prime2};
    }
};

/*
Usage:
Solution obj;
vector<int> result = obj.closestPrimes(left, right);
*/