/*
204. Count Primes
Link: https://leetcode.com/problems/count-primes/

------------------------------------------------------
Problem Summary:
Given an integer `n`, return the number of prime numbers
that are strictly less than `n`.

A prime number is a number greater than 1 that has no
positive divisors other than 1 and itself.

------------------------------------------------------
Example 1:
Input:
n = 10

Output:
4

Explanation:
Primes less than 10 → 2, 3, 5, 7

------------------------------------------------------
Example 2:
Input:
n = 0

Output:
0

------------------------------------------------------
Brute Force Approach:
For every number from 2 to n-1:
- Check if it is prime by testing divisibility up to sqrt(num).

- Time Complexity: O(n * sqrt(n))
- Space Complexity: O(1)

Too slow for large n.

------------------------------------------------------
Optimal Approach (Sieve of Eratosthenes):
Idea:
1. Assume all numbers are prime initially.
2. Start from 2.
3. For each prime number `i`:
   - Mark all multiples of `i` (starting from i*i) as non-prime.
4. Count remaining prime numbers.

Key Optimization:
- Start marking from i * i (since smaller multiples were already marked).
- Iterate only while i * i < n.

------------------------------------------------------
Time & Space Complexity:
- Time Complexity: O(n log log n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<int> primes(n, 1);
        primes[0] = primes[1] = 0;

        for (int i = 2; i * i < n; i++) {
            if (primes[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    primes[j] = 0;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (primes[i] == 1)
                count++;
        }

        return count;
    }
};

/*
Usage:
Solution obj;
int result = obj.countPrimes(n);
*/