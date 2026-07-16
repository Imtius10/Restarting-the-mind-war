# Binary Search - 25 Problems for Competitive Programming

> LeetCode + Codeforces | Beginner to Hard

---

## Section A: Basic Binary Search

### Problem 3.1 - Binary Search (LeetCode #704)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/binary-search/
- **Task:** Search for target in sorted array. Return index or -1.
- **Input:** `nums = [-1,0,3,5,9,12], target = 9`
- **Output:** `4`
- **Tags:** binary search, basic

### Problem 3.2 - First and Last Position (LeetCode #34)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
- **Task:** Find first and last position of target in sorted array.
- **Input:** `nums = [5,7,7,8,8,10], target = 8`
- **Output:** `[3, 4]`
- **Tags:** lower_bound, upper_bound

### Problem 3.3 - Search Insert Position (LeetCode #35)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/search-insert-position/
- **Task:** Find index where target should be inserted.
- **Tags:** lower_bound

### Problem 3.4 - Missing Number (LeetCode #268)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/missing-number/
- **Task:** Find missing number in array [0 to n].
- **Tags:** binary search, xor

### Problem 3.5 - Guess Number (LeetCode #374)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/guess-number-higher-or-lower/
- **Task:** Guess number with API guess(n), return picked number.
- **Tags:** binary search, interactive

---

## Section B: Binary Search on Answer

### Problem 3.6 - Square Root (LeetCode #69)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/sqrtx/
- **Task:** Compute integer square root of x.
- **Tags:** binary search on answer

### Problem 3.7 - Capacity to Ship Packages (LeetCode #1011)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
- **Task:** Find minimum capacity to ship all packages in D days.
- **Strategy:** Binary search on capacity [max(weights), sum(weights)]
- **Tags:** binary search on answer

### Problem 3.8 - Split Array Largest Sum (LeetCode #410)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/split-array-largest-sum/
- **Task:** Split array into m subarrays, minimize largest sum.
- **Strategy:** Binary search on max sum
- **Tags:** binary search, DP

### Problem 3.9 - Magnetic Force Between Balls (LeetCode #1552)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/magnetic-force-between-two-balls/
- **Task:** Place m balls to maximize minimum magnetic force.
- **Strategy:** Binary search on force
- **Tags:** binary search, sorting

### Problem 3.10 - Koko Eating Bananas (LeetCode #875)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/koko-eating-bananas/
- **Task:** Find minimum eating speed to finish all piles in H hours.
- **Strategy:** Binary search on speed [1, max(piles)]
- **Tags:** binary search on answer

---

## Section C: Binary Search with Rotated/Unique Arrays

### Problem 3.11 - Search in Rotated Sorted Array (LeetCode #33)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/search-in-rotated-sorted-array/
- **Task:** Search target in rotated sorted array.
- **Tags:** binary search, rotated array

### Problem 3.12 - Find Minimum in Rotated Sorted Array (LeetCode #153)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
- **Task:** Find minimum element in rotated sorted array.
- **Tags:** binary search, rotated array

### Problem 3.13 - Search in Rotated Sorted Array II (LeetCode #81)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
- **Task:** Search in rotated array with duplicates.
- **Tags:** binary search, duplicates

### Problem 3.14 - Find Peak Element (LeetCode #162)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/find-peak-element/
- **Task:** Find index of peak element (greater than neighbors).
- **Tags:** binary search

### Problem 3.15 - Single Element in Sorted Array (LeetCode #540)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/single-element-in-sorted-array/
- **Task:** Find single element in sorted array where others appear twice.
- **Tags:** binary search, XOR

---

## Section D: Binary Search on 2D Matrix

### Problem 3.16 - Search a 2D Matrix (LeetCode #74)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/search-a-2d-matrix/
- **Task:** Search target in row-sorted, column-sorted matrix.
- **Tags:** 2D binary search

### Problem 3.17 - Search a 2D Matrix II (LeetCode #240)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/search-a-2d-matrix-ii/
- **Task:** Search in matrix sorted row-wise and column-wise.
- **Tags:** staircase search

### Problem 3.18 - Kth Smallest in Sorted Matrix (LeetCode #378)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
- **Task:** Find kth smallest element in sorted matrix.
- **Tags:** binary search, counting

### Problem 3.19 - Maximal Square (LeetCode #221)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/maximal-square/
- **Task:** Find largest square containing only 1s in binary matrix.
- **Tags:** DP, binary search variant

---

## Section E: Binary Search with Prefix Sum / Frequency

### Problem 3.20 - Find K Closest Elements (LeetCode #658)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/find-k-closest-elements/
- **Task:** Find k closest integers to x in sorted array.
- **Tags:** binary search, sliding window

### Problem 3.21 - Minimum Size Subarray Sum (LeetCode #209)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/minimum-size-subarray-sum/
- **Task:** Find minimal length subarray with sum >= target.
- **Tags:** sliding window, prefix sum

### Problem 3.22 - Find the Duplicate Number (LeetCode #287)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/find-the-duplicate-number/
- **Task:** Find duplicate in array of n+1 integers [1,n].
- **Strategy:** Binary search on value, count elements <= mid
- **Tags:** binary search, pigeonhole

### Problem 3.23 - Ugly Number II (LeetCode #264)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/ugly-number-ii/
- **Task:** Find nth ugly number (factors only 2, 3, 5).
- **Tags:** DP, heap, binary search

### Problem 3.24 - Median of Two Sorted Arrays (LeetCode #4)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/median-of-two-sorted-arrays/
- **Task:** Find median of two sorted arrays in O(log(min(m,n))).
- **Tags:** binary search, partition

### Problem 3.25 - Aggressive Cows (Codeforces / SPOJ)
- **Difficulty:** Medium
- **Task:** Place C cows in N stalls to maximize minimum distance.
- **Strategy:** Binary search on distance
- **Tags:** binary search, greedy
