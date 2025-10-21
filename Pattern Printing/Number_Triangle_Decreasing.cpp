/*
Problem Statement:
------------------
Print a number triangle pattern of 'n' rows based on a specific decreasing rule.

Pattern Logic:
- Each row starts with a computed value (stored in 'nums').
- For each row 'i' (0-indexed), you print (i+1) numbers.
- The first number in a row is stored in a temporary variable 'num' initialized to 'nums'.
- Each subsequent number in the row is computed by subtracting (n - j) from 'num', where 'j' is the current index in the row.
- After printing a row, update 'nums' by adding (n - i) to prepare for the next row.

Example (n = 5):
Output:
1
6 1
10 5 1
13 8 4 1
15 10 6 3 1

Constraints:
- 1 <= n <= 1000

Write a function `printNumberTriangle(int n)` that prints the pattern as described above.
*/

#include <iostream>
using namespace std;

class Solution{
public:
    void printNumberTriangle(int n){
        int nums = 1;

        for(int i = 0; i < n; i++){
            int num = nums;
            for(int j = 0; j <= i; j++){
                cout << num << " ";
                num -= (n - j);
            }
            cout << endl;
            nums += (n - i);
        }
    }
};

int main(){

    int num;
    cin >> num;

    Solution sol;
    sol.printNumberTriangle(num);
    return 0;
}