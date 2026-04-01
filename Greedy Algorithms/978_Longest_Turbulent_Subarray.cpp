/*
978. Longest Turbulent Subarray
Link: https://leetcode.com/problems/longest-turbulent-subarray/

------------------------------------------------------
Problem Summary:
Given an integer array `arr`, return the length of the
**longest turbulent subarray**.

A subarray is turbulent if:
- arr[i-1] < arr[i] > arr[i+1] < arr[i+2] ...
OR
- arr[i-1] > arr[i] < arr[i+1] > arr[i+2] ...

In simple terms:
Comparisons must **alternate between < and >**

------------------------------------------------------
Example 1:
Input:
arr = [9,4,2,10,7,8,8,1,9]

Output:
5

Explanation:
Longest turbulent subarray:
[4,2,10,7,8]

------------------------------------------------------
Example 2:
Input:
arr = [4,8,12,16]

Output:
2

------------------------------------------------------
Example 3:
Input:
arr = [100]

Output:
1

------------------------------------------------------
Approach (Sliding Window):

Idea:
- Maintain a window [left, right]
- Track previous comparison sign (`<` or `>`)
- Expand window if alternating condition holds
- Otherwise reset window

------------------------------------------------------
Steps:

1. Initialize:
   left = 0, right = 1
   prevSign = ' ' (no previous comparison)

2. Traverse:
   - If arr[right-1] < arr[right] AND prevSign != '<'
        → valid extension
   - If arr[right-1] > arr[right] AND prevSign != '>'
        → valid extension
   - Else:
        → reset window

3. Special case:
   - If equal elements → reset fully

4. Track max length

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(n)

Space Complexity:
O(1)

------------------------------------------------------
Better Approach (Not implemented below):

Use DP with two arrays:
- up[i] → length ending at i where last comparison was <
- down[i] → length ending at i where last comparison was >

Transition:
if arr[i] > arr[i-1]:
    up[i] = down[i-1] + 1
if arr[i] < arr[i-1]:
    down[i] = up[i-1] + 1

Space can be optimized to O(1).

------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int n = arr.size();
        if(n == 1) return 1;

        int left = 0;
        int right = 1;
        int maxLen = 1;

        char prevSign = ' ';
        
        while(right < n){

            if(arr[right - 1] < arr[right] && prevSign != '<'){
                maxLen = max(maxLen, right - left + 1);
                right++;
                prevSign = '<';
            }
            else if(arr[right - 1] > arr[right] && prevSign != '>'){
                maxLen = max(maxLen, right - left + 1);
                right++;
                prevSign = '>';
            }
            else{

                if(arr[right - 1] == arr[right]){
                    left = right;
                    right = right + 1;
                    prevSign = ' ';
                }
                else{
                    left = right - 1;
                    prevSign = ' ';
                }
            }
        }        

        return maxLen;
    }
};

/*
Usage:
Solution obj;
int result = obj.maxTurbulenceSize(arr);
*/