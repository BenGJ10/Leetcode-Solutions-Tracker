# C++ Maximum Sliding Window Cheatsheet Template

## Problems Solvable Using This Template

* 3. Longest Substring Without Repeating Characters
* 159. Longest Substring with At Most Two Distinct Characters
* 340. Longest Substring with At Most K Distinct Characters
* 424. Longest Repeating Character Replacement
* 487. Max Consecutive Ones II
* 713. Subarray Product Less Than K
* 1004. Max Consecutive Ones III
* 1208. Get Equal Substrings Within Budget
* 1493. Longest Subarray of 1's After Deleting One Element
* 1695. Maximum Erasure Value
* 1838. Frequency of the Most Frequent Element
* 2009. Minimum Number of Operations to Make Array Continuous
* 2024. Maximize the Confusion of an Exam

### Also solvable using “At Most to Equal” trick (shrinkable window)

* 930. Binary Subarrays With Sum
* 992. Subarrays with K Different Integers
* 1248. Count Number of Nice Subarrays
* 2062. Count Vowel Substrings of a String

---

## Template 1: Sliding Window (Shrinkable)

Best general-purpose shrinkable sliding window pattern:

```cpp
int i = 0, j = 0, ans = 0;
for (; j < N; ++j) {
    // use A[j] to update state which might make the window invalid

    for (; invalid(); ++i) { 
        // when invalid, shrink left side until valid
        // update state using A[i]
    }

    ans = max(ans, j - i + 1);
}
return ans;
```

Key idea:
Window is **always valid after the outer loop iteration ends**.

---

### Example: Frequency of the Most Frequent Element

**State:** sum of elements in the window
**Invalid condition:**

```
(j - i + 1) * A[j] - sum > k
```

```cpp
class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, N = A.size(), ans = 1, sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += A[j];
            while ((j - i + 1) * A[j] - sum > k) sum -= A[i++];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```

#### Why O(N log N)?

Sorting is O(N log N).
Sliding window pass is O(N).

#### Why is condition valid?

To make all values equal to `A[j]`, operations required:

```
(j - i + 1) * A[j] - sum
```

It must be less than or equal to `k`.

---

## Template 2: Sliding Window (Non-shrinkable)

```cpp
int i = 0, j = 0;
for (; j < N; ++j) {
    // update state with A[j]

    if (invalid()) {
        // shrink only when invalid
        // update state using A[i]
        ++i;
    }
}
return j - i;
```

Key idea:
When valid → grow
When invalid → shift

---

### Example: Frequency of the Most Frequent Element

```cpp
class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, j = 0, N = A.size(), sum = 0;
        for (; j < N; ++j) {
            sum += A[j];
            if ((j - i + 1) * A[j] - sum > k) sum -= A[i++];
        }
        return j - i;
    }
};
```

---

# Applications to Other Problems

## 1493. Longest Subarray of 1's After Deleting One Element

### Shrinkable window

State: number of zeros
Invalid: more than one zero

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int i = 0, j = 0, N = A.size(), cnt = 0, ans = 0;
        for (; j < N; ++j) {
            cnt += A[j] == 0;
            while (cnt > 1) cnt -= A[i++] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

### Non-shrinkable window

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int i = 0, j = 0, N = A.size(), cnt = 0;
        for (; j < N; ++j) {
            cnt += A[j] == 0;
            if (cnt > 1) cnt -= A[i++] == 0;
        }
        return j - i - 1;
    }
};
```

---

## 3. Longest Substring Without Repeating Characters

### Shrinkable window

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, N = s.size(), ans = 0, cnt[128] = {};
        for (; j < N; ++j) {
            cnt[s[j]]++;
            while (cnt[s[j]] > 1) cnt[s[i++]]--;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```

### Non-shrinkable window

State addition: number of duplicate character types in window

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, N = s.size(), cnt[128] = {}, dup = 0;
        for (; j < N; ++j) {
            dup += ++cnt[s[j]] == 2;
            if (dup) dup -= --cnt[s[i++]] == 1;
        }
        return j - i;
    }
};
```

---

## 713. Subarray Product Less Than K

Shrinkable window only

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& A, int k) {
        if (k == 0) return 0;
        long i = 0, j = 0, N = A.size(), prod = 1, ans = 0;
        for (; j < N; ++j) {
            prod *= A[j];
            while (i <= j && prod >= k) prod /= A[i++];
            ans += j - i + 1;
        }
        return ans;
    }
};
```

---
