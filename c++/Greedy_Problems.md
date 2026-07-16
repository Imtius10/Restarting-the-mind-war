# Greedy - 25 Problems for Competitive Programming

> LeetCode + Codeforces | Beginner to Hard

---

## Section A: Easy Greedy

### Problem 2.1 - Maximum Units on a Truck (LeetCode #1710)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/maximum-units-on-a-truck/
- **Task:** Given boxes with types (boxes, unitsPerBox) and truck size, maximize units loaded.
- **Input:** `boxes = [[1,3],[2,2],[3,1]], truckSize = 4`
- **Output:** `8`
- **Strategy:** Sort by unitsPerBox descending, greedily pick max units
- **Tags:** sorting, greedy

### Problem 2.2 - Assign Cookies (LeetCode #455)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/assign-cookies/
- **Task:** Each child i has greed g[i], each cookie j has size s[j]. Maximize content children.
- **Input:** `g = [1,2,3], s = [1,1]`
- **Output:** `1`
- **Strategy:** Sort both, try to satisfy smallest greed first
- **Tags:** two pointers, greedy

### Problem 2.3 - Best Time to Buy and Sell Stock II (LeetCode #122)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
- **Task:** Maximize profit with unlimited transactions.
- **Input:** `prices = [7,1,5,3,6,4]`
- **Output:** `7`
- **Strategy:** Collect all positive differences
- **Tags:** greedy, array

### Problem 2.4 - Lemonade Change (LeetCode #860)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/lemonade-change/
- **Task:** Each lemonade costs $5. Customers pay $5, $10, or $20. Can you give change?
- **Input:** `bills = [5,5,5,10,20]`
- **Output:** `true`
- **Strategy:** Always give largest bill first
- **Tags:** greedy, simulation

### Problem 2.5 - Array Partition (LeetCode #561)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/array-partition-i/
- **Task:** Partition into pairs, maximize sum of min of each pair.
- **Input:** `nums = [1,4,3,2]`
- **Output:** `4`
- **Strategy:** Sort, pair adjacent elements
- **Tags:** sorting, greedy

---

## Section B: Interval Scheduling & Activity Selection

### Problem 2.6 - Non-overlapping Intervals (LeetCode #435)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/non-overlapping-intervals/
- **Task:** Find minimum intervals to remove to make rest non-overlapping.
- **Input:** `intervals = [[1,2],[2,3],[3,4],[1,3]]`
- **Output:** `1`
- **Strategy:** Sort by end time, greedily keep earliest ending
- **Tags:** interval, greedy

### Problem 2.7 - Minimum Number of Arrows (LeetCode #452)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
- **Task:** Find minimum arrows to burst all balloons (intervals).
- **Input:** `points = [[10,16],[2,8],[1,6],[7,12]]`
- **Output:** `2`
- **Strategy:** Sort by end, count overlapping groups
- **Tags:** interval, greedy

### Problem 2.8 - Merge Intervals (LeetCode #56)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/merge-intervals/
- **Task:** Merge all overlapping intervals.
- **Input:** `intervals = [[1,3],[2,6],[8,10],[15,18]]`
- **Output:** `[[1,6],[8,10],[15,18]]`
- **Strategy:** Sort by start, merge if overlap
- **Tags:** interval, sorting

### Problem 2.9 - Insert Interval (LeetCode #57)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/insert-interval/
- **Task:** Insert new interval and merge if necessary.
- **Tags:** interval, merging

### Problem 2.10 - Meeting Rooms II (LeetCode #253)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/meeting-rooms-ii/
- **Task:** Find minimum meeting rooms required.
- **Input:** `intervals = [[0,30],[5,10],[15,20]]`
- **Output:** `2`
- **Strategy:** Sort starts/ends, count overlaps
- **Tags:** interval, heap

---

## Section C: Job Scheduling & Optimization

### Problem 2.11 - Job Sequencing Problem
- **Difficulty:** Medium
- **Task:** Given jobs with (id, deadline, profit), maximize profit.
- **Strategy:** Sort by profit descending, assign latest possible slot
- **Tags:** scheduling, disjoint set

### Problem 2.12 - Minimum Platforms
- **Difficulty:** Medium
- **Task:** Find minimum platforms needed for train schedule.
- **Strategy:** Sort arrival/departure, track concurrent trains
- **Tags:** interval, sorting

### Problem 2.13 - Course Schedule III (LeetCode #630)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/course-schedule-iii/
- **Task:** Given courses (duration, lastDay), maximize courses taken.
- **Strategy:** Sort by end time, use max-heap for durations
- **Tags:** heap, greedy

---

## Section D: Coin Change & Distribution

### Problem 2.14 - Coin Change (Greedy version)
- **Difficulty:** Medium
- **Task:** Find minimum coins to make amount (canonical coin system).
- **Input:** `coins = [1,5,10,25], amount = 30`
- **Output:** `2` (25 + 5)
- **Strategy:** Pick largest coin first
- **Tags:** coin change, greedy

### Problem 2.15 - Minimum Coins (Codeforces)
- **Difficulty:** Medium
- **Task:** Find minimum coins for given amount with denominations.
- **Tags:** coin change, dp vs greedy

### Problem 2.16 - Distribute Candies (LeetCode #575)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/distribute-candies/
- **Task:** Distribute candies evenly between brother and sister.
- **Tags:** set, greedy

### Problem 2.17 - Minimum Cost to Hire K Workers (LeetCode #857)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
- **Task:** Hire K workers minimizing cost ratio.
- **Strategy:** Sort by wage/quality ratio, use max-heap
- **Tags:** heap, ratio sorting

---

## Section E: String & Miscellaneous Greedy

### Problem 2.18 - Largest Number (LeetCode #179)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/largest-number/
- **Task:** Arrange numbers to form largest number.
- **Input:** `nums = [3,30,34,5,9]`
- **Output:** `"9534330"`
- **Strategy:** Custom comparator: a+b > b+a
- **Tags:** sorting, custom comparator

### Problem 2.19 - Reorganize String (LeetCode #767)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/reorganize-string/
- **Task:** Rearrange string so no two adjacent are same.
- **Strategy:** Use max-heap, alternate most frequent characters
- **Tags:** heap, greedy

### Problem 2.20 - Task Scheduler (LeetCode #621)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/task-scheduler/
- **Task:** Find minimum intervals to complete tasks with cooldown n.
- **Strategy:** Max frequency first, fill cooldowns
- **Tags:** heap, simulation

### Problem 2.21 - Candy (LeetCode #135)
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/candy/
- **Task:** Distribute candies where higher rated gets more candies.
- **Strategy:** Two passes (left-to-right, right-to-left)
- **Tags:** two passes, greedy

### Problem 2.22 - Jump Game (LeetCode #55)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/jump-game/
- **Task:** Can you reach the last index?
- **Strategy:** Track max reachable index
- **Tags:** greedy, reachability

### Problem 2.23 - Jump Game II (LeetCode #45)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/jump-game-ii/
- **Task:** Find minimum jumps to reach end.
- **Strategy:** BFS-like greedy, track current/max reach
- **Tags:** greedy, BFS

### Problem 2.24 - Gas Station (LeetCode #134)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/gas-station/
- **Task:** Find starting gas station to complete circular tour.
- **Strategy:** If total gas >= total cost, solution exists
- **Tags:** circular, greedy

### Problem 2.25 - Hand of Straights (LeetCode #846)
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/hand-of-straights/
- **Task:** Can hand be divided into groups of consecutive cards?
- **Strategy:** Sort, greedily form groups from smallest
- **Tags:** map, greedy
