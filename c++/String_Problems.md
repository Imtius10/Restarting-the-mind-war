# String Algorithms - 25 Problems for Competitive Programming

> LeetCode + Codeforces | Beginner to Hard

---

## Section A: Basic String Manipulation

### Problem 5.1 - Valid Anagram (LeetCode #242)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/valid-anagram/
- **Task:** Check if two strings are anagrams.
- **Strategy:** Frequency count or sort both
- **Tags:** frequency, sorting

### Problem 5.2 - Group Anagrams (LeetCode #49)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/group-anagrams/
- **Task:** Group strings that are anagrams.
- **Strategy:** Use sorted string as key in map
- **Tags:** map, sorting

### Problem 5.3 - Valid Palindrome (LeetCode #125)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/valid-palindrome/
- **Task:** Check if string is palindrome (alphanumeric only).
- **Tags:** two pointers

### Problem 5.4 - Longest Palindromic Substring (LeetCode #5)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/longest-palindromic-substring/
- **Task:** Find longest palindromic substring.
- **Strategy:** Expand around center or Manacher's algorithm
- **Tags:** palindrome, expand around center

### Problem 5.5 - Reverse Words in String (LeetCode #151)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/reverse-words-in-a-string/
- **Task:** Reverse words in string.
- **Tags:** string manipulation

---

## Section B: Pattern Matching

### Problem 5.6 - KMP Pattern Matching (LeetCode #28)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/implement-strstr/
- **Task:** Find first occurrence of pattern in text.
- **Strategy:** KMP algorithm with LPS array
- **Tags:** KMP, pattern matching

### Problem 5.7 - Repeated Substring Pattern (LeetCode #459)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/repeated-substring-pattern/
- **Task:** Check if string is made of repeated substring.
- **Strategy:** Use KMP LPS array
- **Tags:** KMP, pattern

### Problem 5.8 - Shortest Palindrome (LeetCode #214)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/shortest-palindrome/
- **Task:** Add chars to front to make palindrome.
- **Strategy:** KMP on s + "#" + reverse(s)
- **Tags:** KMP, palindrome

### Problem 5.9 - Longest Happy Prefix (LeetCode #1392)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/longest-happy-prefix/
- **Task:** Find longest prefix which is also suffix.
- **Strategy:** KMP LPS array
- **Tags:** KMP, prefix-suffix

### Problem 5.10 - Z-Function (Pattern Matching)
- **Difficulty:** Medium
- **Task:** Compute Z-array for pattern matching.
- **Tags:** Z-algorithm, pattern matching

---

## Section C: Trie (Prefix Tree)

### Problem 5.11 - Implement Trie (LeetCode #208)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/implement-trie-prefix-tree/
- **Task:** Design trie with insert, search, startsWith.
- **Strategy:** TrieNode with children[26] and isEnd
- **Tags:** trie, design

### Problem 5.12 - Design Add and Search Words (LeetCode #211)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/design-add-and-search-words-data-structure/
- **Task:** Add words and search with '.' wildcard.
- **Strategy:** Trie with DFS for wildcard search
- **Tags:** trie, DFS

### Problem 5.13 - Word Search II (LeetCode #212)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/word-search-ii/
- **Task:** Find all words from board (backtracking + trie).
- **Tags:** trie, backtracking

### Problem 5.14 - Replace Words (LeetCode #648)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/replace-words/
- **Task:** Replace words with shortest root using trie.
- **Tags:** trie, string

### Problem 5.15 - Word Break (LeetCode #139)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/word-break/
- **Task:** Check if string can be segmented into dictionary words.
- **Strategy:** DP + Trie or HashSet
- **Tags:** trie, DP

---

## Section D: String Hashing & Rabin-Karp

### Problem 5.16 - Rabin-Karp String Matching
- **Difficulty:** Medium
- **Task:** Find all occurrences of pattern in text using rolling hash.
- **Strategy:** Rolling hash with base and mod
- **Tags:** rolling hash, pattern matching

### Problem 5.17 - Longest Duplicate Substring (LeetCode #1044)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/longest-duplicate-substring/
- **Task:** Find longest substring that appears at least twice.
- **Strategy:** Binary search + rolling hash
- **Tags:** binary search, rolling hash

### Problem 5.18 - Check If String Contains All Binary Codes (LeetCode #1461)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
- **Task:** Check if string contains all binary codes of length k.
- **Strategy:** Rolling hash or set
- **Tags:** rolling hash, bit manipulation

### Problem 5.19 - Distinct Substrings (Codeforces)
- **Difficulty:** Medium
- **Task:** Count distinct substrings of string.
- **Strategy:** Suffix array or hashing
- **Tags:** suffix array, hashing

### Problem 5.20 - Longest Common Substring (DP variant)
- **Difficulty:** Medium
- **Task:** Find longest common substring of two strings.
- **Tags:** DP, suffix

---

## Section E: Suffix Array & Advanced

### Problem 5.21 - Suffix Array Construction
- **Difficulty:** Hard
- **Task:** Build suffix array of string in O(n log n).
- **Tags:** suffix array, sorting

### Problem 5.22 - Longest Repeated Substring
- **Difficulty:** Hard
- **Task:** Find longest repeated substring using suffix array + LCP.
- **Tags:** suffix array, LCP

### Problem 5.23 - String Compression (LeetCode #443)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/string-compression/
- **Task:** Compress string in-place.
- **Tags:** two pointers, string

### Problem 5.24 - Decode String (LeetCode #394)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/decode-string/
- **Task:** Decode encoded string like "3[a2[c]]" -> "accaccacc".
- **Strategy:** Stack-based parsing
- **Tags:** stack, string parsing

### Problem 5.25 - Minimum Remove for Valid Parentheses (LeetCode #1249)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
- **Task:** Remove minimum parentheses to make string valid.
- **Strategy:** Stack to track unmatched parentheses
- **Tags:** stack, string
