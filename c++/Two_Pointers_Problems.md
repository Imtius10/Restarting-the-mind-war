# Two Pointers - 25 Problems for Competitive Programming

> LeetCode + Codeforces | Beginner to Hard

---

## Section A: Opposite Direction Two Pointers (Sorted Array)

### Problem 4.1 - Two Sum II (LeetCode #167)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
- **Task:** Find two numbers in sorted array that add to target.
- **Input:** `numbers = [2,7,11,15], target = 9`
- **Output:** `[1, 2]`
- **Strategy:** left=0, right=n-1, move based on sum
- **Tags:** two pointers, sorted

### Problem 4.2 - 3Sum (LeetCode #15)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/3sum/
- **Task:** Find all unique triplets that sum to zero.
- **Input:** `nums = [-1,0,1,2,-1,-4]`
- **Output:** `[[-1,-1,2],[-1,0,1]]`
- **Strategy:** Sort, fix one element, two pointers for rest
- **Tags:** two pointers, sorting

### Problem 4.3 - 3Sum Closest (LeetCode #16)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/3sum-closest/
- **Task:** Find triplet with sum closest to target.
- **Tags:** two pointers, optimization

### Problem 4.4 - 4Sum (LeetCode #18)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/4sum/
- **Task:** Find all unique quadruplets that sum to target.
- **Tags:** two pointers, nested loops

### Problem 4.5 - Container With Most Water (LeetCode #11)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/container-with-most-water/
- **Task:** Find two lines that together with x-axis form container holding most water.
- **Input:** `height = [1,8,6,2,5,4,8,3,7]`
- **Output:** `49`
- **Strategy:** Move pointer with smaller height
- **Tags:** two pointers, optimization

### Problem 4.6 - Trapping Rain Water (LeetCode #42)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/trapping-rain-water/
- **Task:** Calculate water trapped between bars.
- **Strategy:** Two pointers tracking max left/right heights
- **Tags:** two pointers, stack variant

### Problem 4.7 - Valid Palindrome (LeetCode #125)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/valid-palindrome/
- **Task:** Check if string is palindrome (alphanumeric only).
- **Tags:** two pointers, string

### Problem 4.8 - Palindrome Number (LeetCode #9)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/palindrome-number/
- **Task:** Check if integer is palindrome without converting to string.
- **Tags:** two pointers, math

---

## Section B: Same Direction Two Pointers (Sliding Window)

### Problem 4.9 - Longest Substring Without Repeating Characters (LeetCode #3)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/longest-substring-without-repeating-characters/
- **Task:** Find length of longest substring without repeating chars.
- **Strategy:** Sliding window + hash set
- **Tags:** sliding window, hash set

### Problem 4.10 - Minimum Window Substring (LeetCode #76)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/minimum-window-substring/
- **Task:** Find minimum window in s containing all chars of t.
- **Strategy:** Sliding window + frequency map
- **Tags:** sliding window, hash map

### Problem 4.11 - Longest Repeating Character Replacement (LeetCode #424)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/longest-repeating-character-replacement/
- **Task:** Find longest substring with at most k character replacements.
- **Strategy:** Sliding window, track max frequency
- **Tags:** sliding window, frequency

### Problem 4.12 - Permutation in String (LeetCode #567)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/permutation-in-string/
- **Task:** Check if s2 contains permutation of s1.
- **Strategy:** Sliding window of size s1.length()
- **Tags:** sliding window, frequency

### Problem 4.13 - Minimum Size Subarray Sum (LeetCode #209)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/minimum-size-subarray-sum/
- **Task:** Find minimal length subarray with sum >= target.
- **Tags:** sliding window

### Problem 4.14 - Max Consecutive Ones III (LeetCode #1004)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/max-consecutive-ones-iii/
- **Task:** Find max consecutive 1s with at most k zeros flipped.
- **Tags:** sliding window

### Problem 4.15 - Subarray Product Less Than K (LeetCode #713)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/subarray-product-less-than-k/
- **Task:** Count subarrays with product less than k.
- **Tags:** sliding window, product

---

## Section C: Fast & Slow Pointers (Cycle Detection)

### Problem 4.16 - Linked List Cycle (LeetCode #141)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/linked-list-cycle/
- **Task:** Check if linked list has cycle.
- **Strategy:** Slow moves 1 step, fast moves 2 steps
- **Tags:** fast-slow pointer, cycle

### Problem 4.17 - Linked List Cycle II (LeetCode #142)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/linked-list-cycle-ii/
- **Task:** Find node where cycle begins.
- **Strategy:** After meeting, move one pointer to head, both move 1 step
- **Tags:** fast-slow pointer, Floyd's algorithm

### Problem 4.18 - Happy Number (LeetCode #202)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/happy-number/
- **Task:** Check if number is happy (sum of squares converges to 1).
- **Strategy:** Fast-slow pointer to detect cycle
- **Tags:** fast-slow pointer, math

### Problem 4.19 - Find the Duplicate Number (LeetCode #287)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/find-the-duplicate-number/
- **Task:** Find duplicate in array [1,n].
- **Strategy:** Treat as linked list cycle detection
- **Tags:** fast-slow pointer, Floyd's

### Problem 4.20 - Middle of Linked List (LeetCode #876)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/middle-of-the-linked-list/
- **Task:** Find middle node of linked list.
- **Strategy:** Fast reaches end, slow is at middle
- **Tags:** fast-slow pointer

---

## Section D: Sorting Based Two Pointers

### Problem 4.21 - Sort Colors (LeetCode #75)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/sort-colors/
- **Task:** Sort array of 0s, 1s, 2s in-place (Dutch National Flag).
- **Strategy:** Three pointers (low, mid, high)
- **Tags:** three pointers, partitioning

### Problem 4.22 - Move Zeroes (LeetCode #283)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/move-zeroes/
- **Task:** Move all zeros to end while maintaining order.
- **Strategy:** Two pointers, swap non-zero elements
- **Tags:** two pointers, in-place

### Problem 4.23 - Remove Duplicates from Sorted Array (LeetCode #26)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/remove-duplicates-from-sorted-array/
- **Task:** Remove duplicates in-place, return new length.
- **Strategy:** Slow pointer for unique, fast for scanning
- **Tags:** two pointers, in-place

### Problem 4.24 - Remove Element (LeetCode #27)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/remove-element/
- **Task:** Remove all occurrences of val in-place.
- **Tags:** two pointers, in-place

### Problem 4.25 - Merge Sorted Array (LeetCode #88)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/merge-sorted-array/
- **Task:** Merge nums2 into nums1 in-place.
- **Strategy:** Merge from end to avoid overwriting
- **Tags:** two pointers, merging
