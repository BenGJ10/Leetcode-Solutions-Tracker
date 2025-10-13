# Strings Patterns Mastery

## Two-Pointer & Sliding Window

**When to use:**

* Find longest/shortest substring with certain properties.
* Contiguous characters or substring manipulations.
* Often reduces O(n²) brute-force to O(n).

**Master Tips:**

* Always track `start` and `end` pointers clearly.
* Keep a hashmap or frequency array for window properties.
* Remember sliding window + hash map = pattern/anagram problems.

**Key Problems (Master These):**

* [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
* [443. String Compression](https://leetcode.com/problems/string-compression/)
* [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
* [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)

---

## Hashing & Character Mapping

**When to use:**

* Count character frequencies or check mappings.
* Identify anagrams, patterns, or bijections.

**Master Tips:**

* Frequency arrays often beat maps for small character sets.
* For bijection: map char → char and check uniqueness.
* Can combine with sliding window for substring problems.

**Key Problems:**

* [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)
* [205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
* [890. Find and Replace Pattern](https://leetcode.com/problems/find-and-replace-pattern/)
* [451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
* [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)

---

## Prefix/Suffix & String Construction

**When to use:**

* Iterative string building or pattern generation.
* Reconstructing strings from rules (Count & Say, Roman Numerals, etc.).

**Master Tips:**

* Think “simulate step by step” rather than trying fancy math.
* For prefix problems, consider **rolling prefix sums** or **cumulative properties**.

**Key Problems:**

* [6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)
* [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/)
* [38. Count and Say](https://leetcode.com/problems/count-and-say/)
* [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)

---

## Dynamic Programming on Strings

**When to use:**

* Subsequence, edit distance, palindrome or transformations.
* Counting number of ways or optimizations on substrings.

**Master Tips:**

* Define DP state clearly (start, end, subsequence length, etc.).
* Can often reduce space from O(n²) → O(n) for sequences.
* Practice LCS, edit distance, palindrome, interleaving problems.

**Key Problems:**

* [392. Is Subsequence](https://leetcode.com/problems/is-subsequence/)
* [516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)
* [115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)
* [72. Edit Distance](https://leetcode.com/problems/edit-distance/)
* [97. Interleaving String](https://leetcode.com/problems/interleaving-string/)

---

## Advanced Search (KMP, Z-Algorithm, Rolling Hash)

**When to use:**

* Optimized substring search beyond brute force.
* Long strings or repeated pattern matching.

**Master Tips:**

* Understand **prefix function for KMP**, **Z-array**, and **rolling hash mechanics**.
* Useful in competitive programming and hard substring search problems.

**Key Problems:**

* [28. Implement strStr()](https://leetcode.com/problems/implement-strstr/)
* [214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)
* Rabin-Karp & Z-function exercises (practice from CP resources).

---

## Stack / Parsing & Mixed Problems

**When to use:**

* Nested or hierarchical parsing.
* Removing duplicates, decoding, or expression evaluation.

**Master Tips:**

* Think **stack for last-seen or dependency tracking**.
* Often combined with greedy or DP techniques.

**Key Problems:**

* [316. Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/)
* [394. Decode String](https://leetcode.com/problems/decode-string/)
* [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)
* [1209. Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)
* [227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)

---

## Mastery Tips

1. **Pattern recognition > memorization:** Map every new problem to a known technique.
2. **Time Complexity Awareness:** Always check if O(n²) can be reduced via sliding window, DP, or hashing.
3. **Edge Cases:** Empty strings, single characters, all identical characters.
4. **Practice Categories:**

   * Substrings / Windows
   * Subsequence / DP
   * Mapping / Hashing
   * Parsing / Stack
   * Advanced search / KMP

---

## Tracker of Solved Problems

| Problem                                                                                                                           | Difficulty | Technique                        | Solution                                                         |
| --------------------------------------------------------------------------------------------------------------------------------- | ---------- | -------------------------------- | ---------------------------------------------------------------- |
| [6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)                                                          | Medium     | String Construction              | [Solution](./Strings/6_Zigzag_Conversion.cpp)                    |
| [8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)                                              | Medium     | Parsing                          | [Solution](./Strings/8_String_to_Integer_%28atoi%29.cpp)         |
| [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/)                                                           | Medium     | Mapping / Greedy                 | [Solution](./Strings/12_Integer_to_Roman.cpp)                    |
| [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)                                                 | Easy       | Prefix Comparison                | [Solution](./Strings/14_Longest_Common_Prefix.cpp)               |
| [38. Count and Say](https://leetcode.com/problems/count-and-say/)                                                                 | Medium     | String Construction / Simulation | [Solution](./Strings/38_Count_and_Say.cpp)                       |
| [43. Multiply Strings](https://leetcode.com/problems/multiply-strings/)                                                           | Medium     | Simulation / Math                | [Solution](./Strings/43_Multiply_Strings.cpp)                    |
| [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)                                                               | Medium     | Hashing / Frequency Map          | [Solution](./Strings/49_Group_Anagrams.cpp)                      |
| [151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)                                        | Medium     | Two Pointers / Split & Join      | [Solution](./Strings/151_Reverse_Words_in_String.cpp)            |
| [205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)                                                      | Easy       | Character Mapping                | [Solution](./Strings/205_Isomorphic_Strings.cpp)                 |
| [290. Word Pattern](https://leetcode.com/problems/word-pattern/)                                                                  | Easy       | Hash Map / Bijective Mapping     | [Solution](./Strings/290_Word_Pattern.cpp)                       |
| [316. Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/)                                          | Medium     | Stack / Greedy                   | [Solution](./Strings/316_Remove_Duplicate_Letters.cpp)           |
| [392. Is Subsequence](https://leetcode.com/problems/is-subsequence/)                                                              | Easy       | Two Pointers / DP                | [Solution](./Strings/392_Is_Subsequence.cpp)                     |
| [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)                                | Medium     | Sliding Window + Hashing         | [Solution](./Strings/438_Find_all_Anagrams_in_String.cpp)        |
| [443. String Compression](https://leetcode.com/problems/string-compression/)                                                      | Medium     | Two Pointers / In-place          | [Solution](./Strings/443_String_Compression.cpp)                 |
| [451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)                                  | Medium     | Hashing + Sorting                | [Solution](./Strings/451_Sort_Characters_by_Frequency.cpp)       |
| [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)                                                | Medium     | Sliding Window + Hashing         | [Solution](./Strings/567_Permutation_in_Strings.cpp)             |
| [890. Find and Replace Pattern](https://leetcode.com/problems/find-and-replace-pattern/)                                          | Medium     | Hashing / Bijective Mapping      | [Solution](./Strings/890_Find_and_Replace_Pattern.cpp)           |
| [1209. Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)   | Medium     | Stack                            | [Solution](./Strings/1209_Remove_all_adjacent_Duplicates_II.cpp) |
| [3043. Find the Length of the Longest Common Prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/) | Medium     | Prefix Comparison                | [Solution](./Strings/3043_Length_of_LCP.cpp)                     |

---

## Suggested Next Problems for Complete Mastery

* [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
* [72. Edit Distance](https://leetcode.com/problems/edit-distance/)
* [1312. Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)
* [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)
* [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
* [30. Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)
* [214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)
* [28. Implement strStr() (KMP)](https://leetcode.com/problems/implement-strstr/)

---