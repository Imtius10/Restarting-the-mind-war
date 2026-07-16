# C++ STL Problem Set - 70 Problems for Practice

> LeetCode + Codeforces | Organized by STL Container

## How to Use
1. Pick a category
2. Solve each problem on LeetCode/Codeforces
3. Check solution in the corresponding `*_Problems.cpp` file
4. Time yourself - aim for 20-30 min per problem

---

## Category 1: PAIR (10 Problems)

### Problem 1.1 - Sort Pairs
- **Difficulty:** Easy
- **Task:** Given N pairs of integers, sort them first by the first element, then by the second element.
- **Input:** `[(3,5), (1,2), (3,1), (2,4)]`
- **Output:** `[(1,2), (2,4), (3,1), (3,5)]`
- **Tags:** sorting, pair

### Problem 1.2 - Sort by Second Element
- **Difficulty:** Easy
- **Task:** Given N pairs, sort them by the second element in descending order.
- **Input:** `[(1,5), (2,3), (3,1), (4,4)]`
- **Output:** `[(1,5), (4,4), (2,3), (3,1)]`
- **Tags:** sorting, custom comparator

### Problem 1.3 - Merge Two Sorted Arrays of Pairs
- **Difficulty:** Medium
- **Task:** Given two arrays of pairs (each sorted by first element), merge them into a single sorted array.
- **Input:** `a = [(1,2), (3,4)], b = [(1,3), (2,5)]`
- **Output:** `[(1,2), (1,3), (2,5), (3,4)]`
- **Tags:** merging, two pointers

### Problem 1.4 - Two Sum (LeetCode #1)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/two-sum/
- **Task:** Given an array of integers and a target, return indices of two numbers that add up to the target.
- **Input:** `nums = [2,7,11,15], target = 9`
- **Output:** `[0,1]`
- **Tags:** hash map, pair

### Problem 1.5 - K Closest Points to Origin (LeetCode #973)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/k-closest-points-to-origin/
- **Task:** Given N points and integer K, return K closest points to origin (0,0).
- **Input:** `points = [[3,3],[5,-1],[-2,4]], k = 2`
- **Output:** `[[3,3],[-2,4]]`
- **Tags:** sorting, pair, distance

### Problem 1.6 - Group Pairs by First Element
- **Difficulty:** Medium
- **Task:** Given N pairs, group all pairs by their first element.
- **Input:** `[(1,2), (1,3), (2,1), (2,4), (3,1)]`
- **Output:** `{1: [2,3], 2: [1,4], 3: [1]}`
- **Tags:** grouping, map, pair

### Problem 1.7 - Find Pair with Maximum Second Element
- **Difficulty:** Easy
- **Task:** Given N pairs, find the pair with the maximum second element.
- **Input:** `[(1,5), (2,3), (3,1), (4,4)]`
- **Output:** `(1,5)`
- **Tags:** max element, pair

### Problem 1.8 - Count Pairs with Sum Greater Than K
- **Difficulty:** Medium
- **Task:** Given sorted array and integer K, count pairs (i,j) where i < j and nums[i] + nums[j] > K.
- **Input:** `nums = [1,2,3,4,5], K = 6`
- **Output:** `7`
- **Tags:** two pointers, counting

### Problem 1.9 - Frequency of Pairs
- **Difficulty:** Easy
- **Task:** Given N pairs, count the frequency of each unique pair.
- **Input:** `[(1,2), (3,4), (1,2), (5,6), (3,4), (1,2)]`
- **Output:** `{(1,2): 3, (3,4): 2, (5,6): 1}`
- **Tags:** frequency, map, pair

### Problem 1.10 - Nested Pair Access
- **Difficulty:** Medium
- **Task:** Given vector of pairs where second element is also a pair, sort by first element, then find element with specific nested value.
- **Tags:** nested pair, searching

---

## Category 2: VECTOR (10 Problems)

### Problem 2.1 - Two Sum (LeetCode #1)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/two-sum/
- **Task:** Find indices of two numbers that add up to target.
- **Tags:** vector, hash map

### Problem 2.2 - Best Time to Buy and Sell Stock (LeetCode #121)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
- **Task:** Find maximum profit from one buy and one sell.
- **Tags:** vector, greedy

### Problem 2.3 - Contains Duplicate (LeetCode #217)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/contains-duplicate/
- **Task:** Check if any value appears at least twice.
- **Tags:** vector, set

### Problem 2.4 - Maximum Subarray (LeetCode #53)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/maximum-subarray/
- **Task:** Find contiguous subarray with largest sum (Kadane's Algorithm).
- **Tags:** vector, dynamic programming

### Problem 2.5 - Merge Sorted Array (LeetCode #88)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/merge-sorted-array/
- **Task:** Merge nums2 into nums1 in-place.
- **Tags:** vector, merging, two pointers

### Problem 2.6 - Rotate Array (LeetCode #189)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/rotate-array/
- **Task:** Rotate array to the right by K steps.
- **Tags:** vector, rotation, reversal

### Problem 2.7 - Single Number (LeetCode #136)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/single-number/
- **Task:** Find element that appears once (others appear twice).
- **Tags:** vector, bit manipulation, XOR

### Problem 2.8 - Product of Array Except Self (LeetCode #238)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/product-of-array-except-self/
- **Task:** Return array where each element is product of all others (no division).
- **Tags:** vector, prefix/suffix

### Problem 2.9 - Maximum Product Subarray (LeetCode #152)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/maximum-product-subarray/
- **Task:** Find contiguous subarray with maximum product.
- **Tags:** vector, dynamic programming

### Problem 2.10 - Sliding Window Maximum (LeetCode #239)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/sliding-window-maximum/
- **Task:** Return max value in each sliding window of size K.
- **Tags:** vector, deque, sliding window

---

## Category 3: STACK (10 Problems)

### Problem 3.1 - Valid Parentheses (LeetCode #20)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/valid-parentheses/
- **Task:** Check if string of brackets `()[]{}` is valid.
- **Tags:** stack, matching

### Problem 3.2 - Min Stack (LeetCode #155)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/min-stack/
- **Task:** Design stack supporting push, pop, top, getMin all in O(1).
- **Tags:** stack, design

### Problem 3.3 - Reverse a String Using Stack
- **Difficulty:** Easy
- **Task:** Reverse a string using only stack operations.
- **Tags:** stack, string

### Problem 3.4 - Next Greater Element (LeetCode #496)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/next-greater-element-i/
- **Task:** For each element, find next greater element to its right.
- **Tags:** stack, monotonic stack

### Problem 3.5 - Daily Temperatures (LeetCode #739)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/daily-temperatures/
- **Task:** For each day, how many days until a warmer temperature?
- **Tags:** stack, monotonic stack

### Problem 3.6 - Largest Rectangle in Histogram (LeetCode #84)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/largest-rectangle-in-histogram/
- **Task:** Find area of largest rectangle in histogram.
- **Tags:** stack, monotonic stack

### Problem 3.7 - Implement Queue using Stacks (LeetCode #232)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/implement-queue-using-stacks/
- **Task:** Implement FIFO queue using only two stacks.
- **Tags:** stack, queue, design

### Problem 3.8 - Evaluate Reverse Polish Notation (LeetCode #150)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/evaluate-reverse-polish-notation/
- **Task:** Evaluate arithmetic expression in postfix notation.
- **Tags:** stack, expression evaluation

### Problem 3.9 - Simplify Path (LeetCode #71)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/simplify-path/
- **Task:** Convert absolute path to simplified canonical path.
- **Tags:** stack, string parsing

### Problem 3.10 - Next Smaller Element (Codeforces Pattern)
- **Difficulty:** Medium
- **Task:** For each element, find next smaller element to its right.
- **Tags:** stack, monotonic stack

---

## Category 4: QUEUE & DEQUE (10 Problems)

### Problem 4.1 - Implement Stack using Queues (LeetCode #225)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/implement-stack-using-queues/
- **Task:** Implement LIFO stack using only two queues.
- **Tags:** queue, stack, design

### Problem 4.2 - Moving Average from Data Stream (LeetCode #346)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/moving-average-from-data-stream/
- **Task:** Calculate moving average of last K elements.
- **Tags:** queue, sliding window

### Problem 4.3 - Number of Recent Calls (LeetCode #933)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/number-of-recent-calls/
- **Task:** Count requests in last 3000ms.
- **Tags:** queue, binary search

### Problem 4.4 - Sliding Window Maximum (LeetCode #239)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/sliding-window-maximum/
- **Task:** Return max value in each sliding window of size K using deque.
- **Tags:** deque, sliding window, monotonic deque

### Problem 4.5 - Sliding Window Minimum (Codeforces)
- **Difficulty:** Medium
- **Task:** Return min value in each sliding window of size K using deque.
- **Tags:** deque, sliding window

### Problem 4.6 - First Unique Character in String (LeetCode #387)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/first-unique-character-in-a-string/
- **Task:** Find index of first non-repeating character.
- **Tags:** queue, frequency counting

### Problem 4.7 - Generate Binary Numbers 1 to N
- **Difficulty:** Medium
- **Task:** Generate binary representation of numbers 1 to N using queue.
- **Tags:** queue, BFS

### Problem 4.8 - Rotting Oranges (LeetCode #994)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/rotting-oranges/
- **Task:** Find minimum minutes until all fresh oranges rot (BFS).
- **Tags:** queue, BFS, matrix

### Problem 4.9 - Open the Lock (LeetCode #752)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/open-the-lock/
- **Task:** Find minimum turns to reach target from "0000" avoiding deadends.
- **Tags:** queue, BFS, string

### Problem 4.10 - Deck of Cards (LeetCode #807)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/reveal-cards-in-increasing-order/
- **Task:** Find order to reveal cards to get increasing sequence.
- **Tags:** queue, simulation

---

## Category 5: SET & MULTISET (10 Problems)

### Problem 5.1 - Contains Duplicate (LeetCode #217)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/contains-duplicate/
- **Task:** Check if any value appears at least twice in array.
- **Tags:** set, hash

### Problem 5.2 - Intersection of Two Arrays (LeetCode #349)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/intersection-of-two-arrays/
- **Task:** Return unique common elements between two arrays.
- **Tags:** set

### Problem 5.3 - Intersection of Two Arrays II (LeetCode #350)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/intersection-of-two-arrays-ii/
- **Task:** Return common elements with their frequency.
- **Tags:** multiset, frequency

### Problem 5.4 - Third Maximum Number (LeetCode #414)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/third-maximum-number/
- **Task:** Find third distinct maximum number.
- **Tags:** set, ordered

### Problem 5.5 - Find Duplicate Number (LeetCode #287)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/find-the-duplicate-number/
- **Task:** Find single duplicate in array (1 to n-1 range).
- **Tags:** set, detection

### Problem 5.6 - Kth Largest Element in Stream (LeetCode #703)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/kth-largest-element-in-a-stream/
- **Task:** Design class to find Kth largest in stream of integers.
- **Tags:** multiset, heap

### Problem 5.7 - Subarray with K Different Integers (LeetCode #992)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/subarrays-with-k-different-integers/
- **Task:** Count subarrays with exactly K distinct integers.
- **Tags:** sliding window, set, map

### Problem 5.8 - Longest Consecutive Sequence (LeetCode #128)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/longest-consecutive-sequence/
- **Task:** Find length of longest consecutive elements sequence.
- **Tags:** set, O(n) solution

### Problem 5.9 - Find Median from Data Stream (LeetCode #295)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/find-median-from-data-stream/
- **Task:** Design class to add numbers and find median dynamically.
- **Tags:** multiset, two heaps

### Problem 5.10 - Minimum Index of Valid Split (LeetCode #3224)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/minimum-index-of-a-valid-split/
- **Task:** Find minimum index where both halves have same dominator.
- **Tags:** multiset, frequency

---

## Category 6: MAP & UNORDERED_MAP (10 Problems)

### Problem 6.1 - Two Sum (LeetCode #1)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/two-sum/
- **Task:** Find indices of two numbers that add up to target.
- **Tags:** hash map

### Problem 6.2 - Group Anagrams (LeetCode #49)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/group-anagrams/
- **Task:** Group strings that are anagrams of each other.
- **Tags:** map, string, sorting

### Problem 6.3 - Top K Frequent Elements (LeetCode #347)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/top-k-frequent-elements/
- **Task:** Find K most frequent elements.
- **Tags:** map, frequency, sorting

### Problem 6.4 - Longest Substring Without Repeating Characters (LeetCode #3)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/longest-substring-without-repeating-characters/
- **Task:** Find length of longest substring without repeating characters.
- **Tags:** map, sliding window

### Problem 6.5 - Valid Anagram (LeetCode #242)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/valid-anagram/
- **Task:** Check if two strings are anagrams.
- **Tags:** map, frequency

### Problem 6.6 - Subarray Sum Equals K (LeetCode #560)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/subarray-sum-equals-k/
- **Task:** Count continuous subarrays whose sum equals K.
- **Tags:** map, prefix sum

### Problem 6.7 - Roman to Integer (LeetCode #13)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/roman-to-integer/
- **Task:** Convert Roman numeral to integer.
- **Tags:** map, string

### Problem 6.8 - Isomorphic Strings (LeetCode #205)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/isomorphic-strings/
- **Task:** Check if two strings have same character mapping pattern.
- **Tags:** map, bijective mapping

### Problem 6.9 - Word Frequency (LeetCode #109)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/word-frequency/
- **Task:** Count frequency of each word, return top K frequent.
- **Tags:** map, frequency counting

### Problem 6.10 - First Unique Character in String (LeetCode #387)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/first-unique-character-in-a-string/
- **Task:** Find index of first non-repeating character.
- **Tags:** map, frequency, string

---

## Category 7: PRIORITY QUEUE / HEAP (10 Problems)

### Problem 7.1 - Kth Largest Element in Array (LeetCode #215)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/kth-largest-element-in-an-array/
- **Task:** Find Kth largest element in unsorted array.
- **Tags:** heap, min-heap

### Problem 7.2 - Top K Frequent Elements (LeetCode #347)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/top-k-frequent-elements/
- **Task:** Find K most frequent elements.
- **Tags:** heap, frequency

### Problem 7.3 - Merge K Sorted Lists (LeetCode #23)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/merge-k-sorted-lists/
- **Task:** Merge K sorted linked lists into one sorted list.
- **Tags:** heap, linked list, merging

### Problem 7.4 - K Closest Points to Origin (LeetCode #973)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/k-closest-points-to-origin/
- **Task:** Find K closest points to origin.
- **Tags:** heap, distance

### Problem 7.5 - Find Median from Data Stream (LeetCode #295)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/find-median-from-data-stream/
- **Task:** Design class to add numbers and find median dynamically.
- **Tags:** two heaps, design

### Problem 7.6 - Task Scheduler (LeetCode #621)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/task-scheduler/
- **Task:** Find least intervals to complete all tasks with cooldown.
- **Tags:** heap, greedy, simulation

### Problem 7.7 - Kth Smallest Element in Sorted Matrix (LeetCode #378)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
- **Task:** Find Kth smallest element in N x N sorted matrix.
- **Tags:** heap, matrix

### Problem 7.8 - Reorganize String (LeetCode #767)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/reorganize-string/
- **Task:** Rearrange string so no two adjacent characters are same.
- **Tags:** heap, greedy

### Problem 7.9 - Meeting Rooms II (LeetCode #253)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/meeting-rooms-ii/
- **Task:** Find minimum number of meeting rooms required.
- **Tags:** heap, interval scheduling

### Problem 7.10 - Super Ugly Number (LeetCode #313)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/super-ugly-number/
- **Task:** Find Nth ugly number with given prime factors.
- **Tags:** heap, dynamic programming

---

## Quick Reference - STL Cheat Sheet

| Container | Insert | Delete | Search | Ordered? |
|-----------|--------|--------|--------|----------|
| vector | O(n) | O(n) | O(n) | No |
| stack | O(1) | O(1) | O(n) | No (LIFO) |
| queue | O(1) | O(1) | O(n) | No (FIFO) |
| deque | O(1) | O(1) | O(n) | No |
| set | O(log n) | O(log n) | O(log n) | Yes |
| multiset | O(log n) | O(log n) | O(log n) | Yes |
| map | O(log n) | O(log n) | O(log n) | Yes |
| unordered_set | O(1) avg | O(1) avg | O(1) avg | No |
| unordered_map | O(1) avg | O(1) avg | O(1) avg | No |
| priority_queue | O(log n) | O(log n) | O(n) | No (heap) |

**Useful Functions:**
- `sort(v.begin(), v.end())`
- `binary_search(v.begin(), v.end(), x)`
- `lower_bound(v.begin(), v.end(), x)`
- `upper_bound(v.begin(), v.end(), x)`
- `reverse(v.begin(), v.end())`
- `accumulate(v.begin(), v.end(), 0)`
- `count(v.begin(), v.end(), x)`
- `find(v.begin(), v.end(), x)`
- `unique(v.begin(), v.end())`
- `next_permutation(v.begin(), v.end())`
