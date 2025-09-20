# Linked Lists – Complete Patterns

Linked Lists are fundamental data structures consisting of **nodes** connected via pointers. Each node contains data and a reference to the next node. Unlike arrays, they offer **O(1) insertion/deletion** at known positions but **O(n) access** by index. Understanding linked list manipulation is crucial for interviews, as they test pointer handling, memory management, and edge case awareness.

The key idea:  
- Maintain a `head` pointer to the first node.  
- Traverse using `curr = curr->next` until `nullptr`.  
- Manipulate by updating `next` pointers carefully to avoid memory leaks or cycles.  
- Handle edge cases: empty list (`head == nullptr`), single node, or cycles.  

---

## Patterns in Linked Lists

### 1. Basic Traversal and Node Creation

Traverse a list, create nodes, or count length.

#### Idea and Approach
- Start from `head` and iterate with `curr = curr->next`.  
- For creation: Allocate new nodes with `new Node(val)` and link via `next`.  
- Use dummy nodes for simplified insertion/deletion at the head.  

#### Algorithm (Length Calculation)
1. Initialize `length = 0`, `curr = head`.  
2. While `curr != nullptr`:  
   - `length++`.  
   - `curr = curr->next`.  
3. Return `length`.  

#### C++ Example
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getLength(ListNode* head) {
    int length = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }
    return length;
}

// Creating a list: 1 -> 2 -> 3
ListNode* createList(vector<int>& vals) {
    ListNode* head = nullptr;
    for (int val : vals) {
        ListNode* newNode = new ListNode(val);
        if (!head) head = newNode;
        else {
            ListNode* tail = head;
            while (tail->next) tail = tail->next;
            tail->next = newNode;
        }
    }
    return head;
}
```

#### Important Problems

- [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) (builds on traversal)

- [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) (modified traversal)

---

### 2. Insertion and Deletion

Insert/delete nodes at head, tail, or specific positions.

#### Idea and Approach

- **Insertion**: Update pointers to include new node; use dummy for head ops.  

- **Deletion**: Find prev node, then `prev->next = curr->next`; handle head/tail.  

- Time: O(1) if position known; O(n) to find position.  

#### C++ Example
```cpp
// Insert at head
ListNode* insertHead(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    return newNode;
}

// Delete node with given value (first occurrence)
ListNode* deleteNode(ListNode* head, int val) {
    if (!head) return nullptr;
    if (head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    ListNode* curr = head;
    while (curr->next && curr->next->val != val) {
        curr = curr->next;
    }
    if (curr->next) {
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
    return head;
}
```

#### Important Problems

- [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

- [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

- [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

---

### 3. Reversal (Iterative and Recursive)

Reverse the entire list or a sublist.

#### Idea and Approach

- **Iterative**: Use three pointers (prev, curr, next) to flip `next` pointers.  

- **Recursive**: Reverse tail first, then adjust head's next to point back.  

- Preserve head by returning new head.  

#### C++ Example
```cpp
// Iterative reversal
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Recursive reversal
ListNode* reverseListRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

#### Important Problems

- [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

- [92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)

- [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

---

### 4. Cycle Detection and Removal

Detect cycles using Floyd's algorithm; remove cycles by finding start.

#### Idea and Approach

- **Detection**: Slow/fast pointers (tortoise/hare); meet if cycle exists.  

- **Removal**: Reset fast, move both one step; meeting point is cycle start.  

- Unlink by setting `start->next = nullptr`.  

#### C++ Example
```cpp
bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Find and remove cycle start (assumes cycle exists)
ListNode* detectAndRemoveCycle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return head; // No cycle
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = nullptr; // Remove cycle
    return head;
}
```

#### Important Problems

- [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

- [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

- [287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) (cycle in array)

---

### 5. Merging and Sorting

Merge two sorted lists or sort a list.

#### Idea and Approach

- **Merge**: Use dummy head; compare nodes and link smaller.  

- **Sorting**: Merge-based (bottom-up or quicksort-like); O(n log n).  

#### C++ Example
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Merge sort skeleton (divide and conquer)
ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* mid = findMiddle(head);
    ListNode* right = mergeSort(mid->next);
    mid->next = nullptr;
    return mergeTwoLists(mergeSort(head), right);
}

ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

#### Important Problems

- [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

- [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

- [148. Sort List](https://leetcode.com/problems/sort-list/)

---

### More Important Linked List Problems

Here's a list of additional must-practice problems that apply Linked List patterns in different ways:

- [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)  
- [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)  
- [24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)  
- [61. Rotate List](https://leetcode.com/problems/rotate-list/)  
- [82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)  
- [86. Partition List](https://leetcode.com/problems/partition-list/)  
- [143. Reorder List](https://leetcode.com/problems/reorder-list/)  
- [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)  
- [203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)  
- [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)  
- [430. Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)  
- [708. Insert into a Sorted Circular Linked List](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/)  

---