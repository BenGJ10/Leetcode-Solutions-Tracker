/*
179. Largest Number
Link: https://leetcode.com/problems/largest-number/

------------------------------------------------------
Problem Summary:
Given a list of non-negative integers `nums`, arrange them such that 
they form the **largest possible number** and return it as a string.

Note:
- The result may be very large, so you need to return it as a string, not an integer.

------------------------------------------------------
Example:
Input:
nums = [3,30,34,5,9]

Output:
"9534330"

------------------------------------------------------
Brute Force Approach:
1. Generate all permutations of the array.
2. For each permutation, concatenate numbers and check which gives the largest numeric value.
3. Return the maximum concatenation.

- Time Complexity: O(n! × n)
- Space Complexity: O(n)

------------------------------------------------------
Optimal Approach (Custom Sort Comparator):
Idea:
- Convert all numbers to strings.
- Sort them based on which concatenation gives a larger combined string:
  - For strings `a` and `b`, compare `a + b` and `b + a`.
  - If `a + b` > `b + a`, `a` should come before `b`.
- After sorting, concatenate all strings.

Steps:
1. Convert each number in `nums` to a string.
2. Sort using a custom comparator `a + b > b + a`.
3. Handle edge case: if the largest element is "0", return "0".
4. Concatenate all strings to get the final result.

- Time Complexity: O(n log n)
- Space Complexity: O(n)

------------------------------------------------------
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(string str1, string str2) {
        return str1 + str2 > str2 + str1;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int &num : nums) arr.push_back(to_string(num));
        sort(arr.begin(), arr.end(), compare);

        if (arr[0] == "0") return "0";

        string ans = "";
        for (auto &str : arr) ans += str;
        return ans;
    }
};

/*
Usage:
Solution obj;
string result = obj.largestNumber(nums);
*/
