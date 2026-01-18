/*
622. Design Circular Queue
Link: https://leetcode.com/problems/design-circular-queue/

------------------------------------------------------
Problem Summary:
Design a **Circular Queue** with fixed size `k`.

You need to implement the following operations:
- `enQueue(value)`  : Insert an element into the circular queue.
- `deQueue()`       : Delete an element from the circular queue.
- `Front()`         : Get the front item.
- `Rear()`          : Get the last item.
- `isEmpty()`       : Check if the queue is empty.
- `isFull()`        : Check if the queue is full.

Return true/false based on whether operations succeed.

------------------------------------------------------
Constraints & Observations:
- Queue has a fixed capacity `k`.
- FIFO order must be maintained.
- Circular behavior means reuse of freed space.
- We must handle edge cases when queue becomes empty or full.

------------------------------------------------------
Brute Force Thought:
Use an array and shift elements on dequeue.

- Time Complexity: O(n) per dequeue
- Space Complexity: O(k)

Not efficient.

------------------------------------------------------
Optimal Approach (Linked List + Capacity Counter):
Idea:
- Use a **singly linked list** with:
  - Dummy head (`left`) → simplifies dequeue
  - Tail pointer (`right`) → enables O(1) enqueue
- Maintain a `space` variable to track remaining capacity.

Key Points:
- `space == 0` → queue is full
- `left->next == nullptr` → queue is empty
- On enqueue:
  - Add node at tail
  - Decrease space
- On dequeue:
  - Remove node from head
  - Increase space
- When queue becomes empty after dequeue, reset tail.

- Time Complexity: O(1) per operation
- Space Complexity: O(k)

------------------------------------------------------
*/

class MyCircularQueue {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
    };

    int space;
    ListNode* left;   // dummy head
    ListNode* right;  // tail

    MyCircularQueue(int k) {
        space = k;
        left = new ListNode(0);
        right = left;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        ListNode* node = new ListNode(value);
        if (isEmpty()) {
            left->next = node;
            right = node;
        } else {
            right->next = node;
            right = node;
        }
        space--;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        ListNode* temp = left->next;
        left->next = left->next->next;
        delete temp;

        if (left->next == nullptr) {
            right = left;
        }
        space++;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return left->next->val;
    }

    int Rear() {
        if (isEmpty()) return -1;
        return right->val;
    }

    bool isEmpty() {
        return left->next == nullptr;
    }

    bool isFull() {
        return space == 0;
    }
};

/*
Usage:
MyCircularQueue* obj = new MyCircularQueue(k);
bool param_1 = obj->enQueue(value);
bool param_2 = obj->deQueue();
int param_3 = obj->Front();
int param_4 = obj->Rear();
bool param_5 = obj->isEmpty();
bool param_6 = obj->isFull();
*/
