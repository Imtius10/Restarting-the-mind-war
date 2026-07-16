# Bitmasking - 25 Problems for Competitive Programming

> LeetCode + Codeforces | Beginner to Hard

---

## Section A: Basic Bit Operations

### Problem 6.1 - Number of 1 Bits (LeetCode #191)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/number-of-1-bits/
- **Task:** Count set bits in unsigned integer.
- **Input:** `n = 11 (binary: 1011)`
- **Output:** `3`
- **Strategy:** n & (n-1) clears lowest set bit
- **Tags:** bit manipulation

### Problem 6.2 - Counting Bits (LeetCode #338)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/counting-bits/
- **Task:** Return array where count[i] = number of 1s in binary of i.
- **Strategy:** DP: count[i] = count[i >> 1] + (i & 1)
- **Tags:** DP, bit manipulation

### Problem 6.3 - Power of Two (LeetCode #231)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/power-of-two/
- **Task:** Check if number is power of two.
- **Strategy:** n > 0 && (n & (n-1)) == 0
- **Tags:** bit trick

### Problem 6.4 - Power of Three (LeetCode #326)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/power-of-three/
- **Task:** Check if number is power of three.
- **Strategy:** Use max power: 3^19 = 1162261467, check divisibility
- **Tags:** math, bit trick

### Problem 6.5 - Reverse Bits (LeetCode #190)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/reverse-bits/
- **Task:** Reverse bits of 32-bit unsigned integer.
- **Tags:** bit manipulation

---

## Section B: Single Number & Missing Number

### Problem 6.6 - Single Number (LeetCode #136)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/single-number/
- **Task:** Find element appearing once (others twice).
- **Strategy:** XOR all: a ^ a = 0, a ^ 0 = a
- **Tags:** XOR

### Problem 6.7 - Single Number II (LeetCode #137)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/single-number-ii/
- **Task:** Find element appearing once (others thrice).
- **Strategy:** Count bits at each position mod 3
- **Tags:** bit counting

### Problem 6.8 - Single Number III (LeetCode #260)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/single-number-iii/
- **Task:** Find two elements appearing once (others twice).
- **Strategy:** XOR all, find rightmost set bit, divide into two groups
- **Tags:** XOR, grouping

### Problem 6.9 - Missing Number (LeetCode #268)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/missing-number/
- **Task:** Find missing number in [0,n].
- **Strategy:** XOR all indices and values
- **Tags:** XOR

### Problem 6.10 - Find the Difference (LeetCode #389)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/find-the-difference/
- **Task:** Find char added to shuffled string.
- **Strategy:** XOR all chars
- **Tags:** XOR

---

## Section C: Subset Generation (Bitmask)

### Problem 6.11 - Subsets (LeetCode #78)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/subsets/
- **Task:** Generate all subsets of set.
- **Strategy:** Use bitmask 0 to 2^n - 1
- **Tags:** bitmask, subset

### Problem 6.12 - Subsets II (LeetCode #90)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/subsets-ii/
- **Task:** Generate all unique subsets (with duplicates).
- **Strategy:** Sort + skip duplicates
- **Tags:** bitmask, backtracking

### Problem 6.13 - Power Set (Codeforces)
- **Difficulty:** Easy
- **Task:** Print all subsets of given set.
- **Strategy:** for mask = 0 to 2^n - 1, check each bit
- **Tags:** bitmask, enumeration

### Problem 6.14 - Count Subsets with Sum K
- **Difficulty:** Medium
- **Task:** Count subsets that sum to K.
- **Strategy:** DP with bitmask or meet-in-middle
- **Tags:** bitmask, DP

### Problem 6.15 - Subset Sum Problem (DP)
- **Difficulty:** Medium
- **Task:** Check if subset with given sum exists.
- **Tags:** DP, bitmask

---

## Section D: Bitmask DP (Traveling Salesman, Assignment)

### Problem 6.16 - Traveling Salesman Problem (TSP)
- **Difficulty:** Hard
- **Task:** Visit all cities exactly once and return to start (min cost).
- **Strategy:** DP[mask][i] = min cost to visit cities in mask, ending at i
- **Tags:** bitmask DP, TSP

### Problem 6.17 - Assignment Problem
- **Difficulty:** Hard
- **Task:** N workers, N jobs. Minimize total cost.
- **Strategy:** Bitmask DP
- **Tags:** bitmask DP, assignment

### Problem 6.18 - Minimum XOR Sum of Two Arrays (LeetCode #1879)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
- **Task:** Pair elements from two arrays to minimize XOR sum.
- **Strategy:** Bitmask DP
- **Tags:** bitmask DP, optimization

### Problem 6.19 - Maximal Score After K Operations (LeetCode #2530)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/maximal-score-after-applying-k-operations/
- **Task:** Select elements with bitmask to maximize score.
- **Tags:** bitmask DP

### Problem 6.20 - Shortest Path Visiting All Nodes (LeetCode #847)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/shortest-path-visiting-all-nodes/
- **Task:** Find shortest path visiting all nodes in graph.
- **Strategy:** BFS + bitmask (state = current node, visited nodes)
- **Tags:** bitmask BFS

---

## Section E: Bit Tricks & Applications

### Problem 6.21 - Bitwise AND of Range (LeetCode #201)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/bitwise-and-of-numbers-range/
- **Task:** Find bitwise AND of all numbers in [left, right].
- **Strategy:** Find common prefix
- **Tags:** bit trick

### Problem 6.22 - XOR Queries of Subarray (LeetCode #1310)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/xor-queries-of-subarray/
- **Task:** Answer XOR queries on subarrays.
- **Strategy:** Prefix XOR
- **Tags:** prefix XOR

### Problem 6.23 - Decode XORed Permutation (LeetCode #1734)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/decode-xored-permutation/
- **Task:** Decode XORed permutation.
- **Strategy:** XOR properties
- **Tags:** XOR, permutation

### Problem 6.24 - Minimum Flips to Make a OR b Equal to c (LeetCode #1318)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
- **Task:** Find minimum bit flips for a|b = c.
- **Strategy:** Check each bit independently
- **Tags:** bit counting

### Problem 6.25 - Maximum XOR of Two Numbers (LeetCode #421)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
- **Task:** Find maximum XOR of any two numbers.
- **Strategy:** Trie on bits (greedy from MSB)
- **Tags:** trie, bit manipulation
