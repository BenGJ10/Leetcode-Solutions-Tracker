/*
23. Merge k Sorted Lists
Link: https://leetcode.com/problems/merge-k-sorted-lists/

------------------------------------------------------
Problem Summary:
You are given an array of `k` linked-lists, each sorted in ascending order.
Merge all the linked-lists into one sorted linked list and return it.

------------------------------------------------------
Example:
Input:
lists = [[1,4,5],[1,3,4],[2,6]]

Output:
[1,1,2,3,4,4,5,6]

Explanation:
Merging the linked lists produces a single sorted list.

------------------------------------------------------
Brute Force Approach:
1. Traverse all linked lists and collect all values into a single array.
2. Sort the array.
3. Create a new linked list using sorted values.
- Time Complexity: O(N log N)  (N = total number of nodes)
- Space Complexity: O(N)

------------------------------------------------------
Optimal Approach (Min-Heap / Priority Queue):
Idea:
- Use a min-heap to efficiently retrieve the smallest current node across k lists.
- Initially, push the head of each non-empty list into the heap.
- Continuously pop the smallest node, add it to the merged list, 
  and push its next node (if any) into the heap.

Steps:
1. Create a min-heap comparing node values.
2. Push all list heads into the heap.
3. Pop the smallest node and attach it to the result list.
4. Push the next node from that list into the heap.
5. Repeat until the heap is empty.

- Time Complexity: O(N log k)
  (Each node insertion/deletion takes log k; total N nodes)
- Space Complexity: O(k)
  (Heap stores at most k nodes)

------------------------------------------------------

*/

#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct Compare {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto &list : lists) {
            if (list) pq.push(list);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            curr->next = node;
            curr = curr->next;

            if (node->next != nullptr)
                pq.push(node->next);
        }
        
        return dummy->next;
    }
};

/*
Usage:
Solution obj;
ListNode* res = obj.mergeKLists(lists);
*/
