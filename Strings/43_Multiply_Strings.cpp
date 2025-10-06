/*
43. Multiply Strings
Link: https://leetcode.com/problems/multiply-strings/

------------------------------------------------------
Problem Summary:
Given two non-negative integers `num1` and `num2` represented as strings,
return the product as a string. 
- You must not use built-in big integer libraries.
- You must not convert inputs directly to integers.

------------------------------------------------------
Brute Force Approach:
1. Convert num1 and num2 to integers (e.g., using stoi).
2. Multiply the two integers.
3. Convert the result back to a string.
⚠️ Not valid here due to problem constraints (large numbers may overflow).

------------------------------------------------------
Optimal Approach (Simulated Manual Multiplication):

Idea:
- Perform multiplication the way it's done by hand.
- Use a result vector of size (n + m), where n and m are lengths of num1 and num2.
- Traverse digits from right to left:
    * Multiply each digit of num1 with each digit of num2.
    * Add product to correct position in result array.
    * Carry over extra values to next position.
- Convert the result array into a string, skipping leading zeros.

Steps:
1. Initialize result vector with size n+m (max possible digits).
2. Nested loop: multiply each digit of num1 with num2 and accumulate into result.
3. Handle carry automatically by adding into result[i+j].
4. Convert final result vector to string, skipping leading zeros.

- Time Complexity: O(n * m), where n and m are lengths of input strings.
- Space Complexity: O(n + m) for result storage.

------------------------------------------------------
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.length(), m = num2.length();
        vector<int> result(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mult = (num1[i] - '0') * (num2[j] - '0');
                int sum = mult + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string ans = "";
        for (int num : result) {
            if (!(ans.empty() && num == 0)) {
                ans.push_back(num + '0');
            }
        }
        return ans.empty() ? "0" : ans;
    }
};

/*
Usage:
Solution sol;
string prod = sol.multiply("123", "456"); // Output: "56088"
*/
