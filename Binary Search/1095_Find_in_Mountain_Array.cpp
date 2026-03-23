/*
1095. Find in Mountain Array
Link: https://leetcode.com/problems/find-in-mountain-array/

------------------------------------------------------
Problem Summary:
You are given a **MountainArray** where:
- Elements strictly increase up to a peak
- Then strictly decrease

Your task is to find the **index of target** in the array.
If not found, return -1.

Constraint:
- You can only access elements using:
    mountainArr.get(index)
- Minimize number of calls to `get()`

------------------------------------------------------
Example:
Input:
target = 3
array = [1,2,3,4,5,3,1]

Output:
2

Explanation:
Target 3 appears at index 2.

------------------------------------------------------
Approach (Binary Search on 3 Parts):

Idea:
1. Find the **peak index**
2. Binary search on **increasing part**
3. Binary search on **decreasing part**

------------------------------------------------------
Step 1: Find Peak Element

We use binary search:
- If mid is increasing → move right
- If mid is decreasing → move left
- Peak satisfies:
    arr[mid-1] < arr[mid] > arr[mid+1]

------------------------------------------------------
Step 2: Search in Left (Increasing) Part

Standard binary search:
- If value < target → go right
- Else → go left

------------------------------------------------------
Step 3: Search in Right (Decreasing) Part

Modified binary search:
- If value > target → go right
- Else → go left

(Since array is in descending order)

------------------------------------------------------
Time & Space Complexity:

Time Complexity:
O(log n)

Space Complexity:
O(1)

------------------------------------------------------
Important Note:
Minimize calls to `mountainArr.get()` as it is costly.

------------------------------------------------------
Better Approach (Optimization - Not implemented below):

- Cache values of `get(mid)` to avoid repeated API calls
- Use a more standard peak-finding binary search:
    if get(mid) < get(mid + 1) → move right
    else → move left

This avoids fetching 3 values every iteration.

------------------------------------------------------
*/

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int low = 1;
        int high = mountainArr.length() - 2;
        int peak = 0;

        // Step 1: Find peak
        while(low <= high){

            int m = low + (high - low) / 2;
            
            int left = mountainArr.get(m - 1);
            int mid = mountainArr.get(m);
            int right = mountainArr.get(m + 1);

            if(left < mid && mid > right){
                peak = m;
                break;
            }
            else if(left < mid && mid < right){
                low = m + 1;
            }
            else{
                high = m - 1;
            }
        }

        // Step 2: Search in increasing part
        low = 0;
        high = peak - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        // Step 3: Search in decreasing part
        low = peak;
        high = mountainArr.length() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;
    }
};

/*
Usage:
Solution obj;
int result = obj.findInMountainArray(target, mountainArr);
*/