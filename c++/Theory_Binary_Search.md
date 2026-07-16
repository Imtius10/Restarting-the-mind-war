# Binary Search - Complete Theory & Intuition Guide

> Master the intuition behind binary search and when to apply it.

---

## 1. What is Binary Search?

### Core Idea
Divide search space in half each time. If you know which half contains the answer, eliminate the other half.

### Why It Works
- Array is **SORTED**
- If target < middle, answer is in **LEFT** half
- If target > middle, answer is in **RIGHT** half

### Visual (Basic Binary Search)
Find target = 7 in: `[1, 3, 5, 7, 9, 11, 13]`

```
Step 1: lo=0, hi=6, mid=3
[1, 3, 5, 7, 9, 11, 13]
         ↑
        mid=7 ✓ Found!
```

If target was 5:
```
Step 1: lo=0, hi=6, mid=3 (value=7)
5 < 7, so hi = mid-1 = 2

Step 2: lo=0, hi=2, mid=1 (value=3)
5 > 3, so lo = mid+1 = 2

Step 3: lo=2, hi=2, mid=2 (value=5) ✓ Found!
```

### Time Complexity
**O(log n)** - eliminates half each step
- n=1000 → ~10 steps
- n=1,000,000 → ~20 steps
- n=1,000,000,000 → ~30 steps

---

## 2. Two Variants - `lo <= hi` vs `lo < hi`

### Variant 1: `lo <= hi` (Search for exact match)
```cpp
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) lo = mid + 1;
    else hi = mid - 1;
}
return -1;  // not found
```
**When to use:** Finding specific element

### Variant 2: `lo < hi` (Search for boundary)
```cpp
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (condition(mid)) hi = mid;    // or lo = mid + 1
    else lo = mid + 1;              // or hi = mid
}
return lo;
```
**When to use:** Finding first/last position, binary search on answer

### Key Difference
| Variant | Returns | Use Case |
|---------|---------|----------|
| `lo <= hi` | When found, or -1 | Finding specific element |
| `lo < hi` | Converges to single answer | Finding boundary/answer |

---

## 3. Lower Bound & Upper Bound

### Lower Bound: First position where `arr[pos] >= target`

```
Example: arr = [1, 2, 2, 2, 3, 4], target = 2

[1, 2, 2, 2, 3, 4]
    ↑
   lower_bound = 1 (first 2)
```

```cpp
int lowerBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
```

### Upper Bound: First position where `arr[pos] > target`

```
Example: arr = [1, 2, 2, 2, 3, 4], target = 2

[1, 2, 2, 2, 3, 4]
                ↑
   upper_bound = 4 (first > 2)
```

```cpp
int upperBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
```

### Visual
```
arr = [1, 2, 2, 2, 3, 4], target = 2

Index:   0  1  2  3  4  5
Value:   1  2  2  2  3  4
         ↓        ↓     ↓
        lb       target ub
        (1)      (2)    (4)

Count of 2s = upper_bound - lower_bound = 4 - 1 = 3 ✓
```

---

## 4. Binary Search on Answer - The Powerful Pattern

### Problem Type
"Find minimum/maximum value such that some condition is true"

### Intuition
- Answer is a **NUMBER** (not index)
- We binary search on possible answer values
- For each candidate answer, check if it's feasible

### Template
```cpp
int binarySearchOnAnswer(int lo, int hi) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (isPossible(mid)) hi = mid;     // for minimum
        else lo = mid + 1;
    }
    return lo;
}
```

### Example: Koko Eating Bananas (LeetCode #875)

```
piles = [3, 6, 7, 11], h = 8 hours

Find minimum eating speed k to finish in h hours.

Search space: k ∈ [1, max(piles)] = [1, 11]

Check k = 6:
  3/6=1hr, 6/6=1hr, 7/6=2hr, 11/6=2hr → total = 6hr ≤ 8 ✓
  Try smaller k

Check k = 3:
  3/3=1hr, 6/3=2hr, 7/3=3hr, 11/3=4hr → total = 10hr > 8 ✗
  Need larger k

Binary search converges to k = 4
```

### Visual
```
k=1:  ████████████████████████████████  (27 hours) ✗
k=2:  ████████████████  (14 hours) ✗
k=3:  ██████████  (10 hours) ✗
k=4:  ████████  (8 hours) ✓ ← minimum!
k=5:  ███████  (7 hours) ✓
k=6:  ██████  (6 hours) ✓

Pattern: ✓✓✓✓✓✗✗✗✗✗
               ↑
          Find first ✓ from right
```

---

## 5. Rotated Sorted Array

### Problem
Array is sorted but rotated at some pivot.

### Example
```
[4, 5, 6, 7, 0, 1, 2]
 sorted part →     ← sorted part
                pivot
```

### Key Insight
At least **ONE half is always sorted**!

```
At any mid:
- If nums[lo] <= nums[mid]: LEFT half is sorted
- Else: RIGHT half is sorted

Then check if target lies in sorted half.
```

### Visual
```
[4, 5, 6, 7, 0, 1, 2]
 ↑        ↑        ↑
 lo      mid      hi

nums[lo]=4 <= nums[mid]=7, so LEFT is sorted
target=0: Is 4 <= 0 < 7? NO → search right

[4, 5, 6, 7, 0, 1, 2]
             ↑     ↑
            mid    hi

nums[mid]=0 <= nums[hi]=2, RIGHT is sorted
target=0: Is 0 < 0 <= 2? NO → search left
Eventually find 0!
```

### Code
```cpp
int searchRotated(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        
        if (nums[lo] <= nums[mid]) {  // left sorted
            if (target >= nums[lo] && target < nums[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        } else {  // right sorted
            if (target > nums[mid] && target <= nums[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    return -1;
}
```

---

## 6. Peak Element

### Problem
Find peak element (greater than neighbors).

### Intuition
- If `arr[mid] < arr[mid+1]`, peak is on **RIGHT**
- If `arr[mid] > arr[mid+1]`, peak is on **LEFT**

Why? Because we're climbing uphill!

### Visual
```
[1, 3, 5, 4, 2]
     ↑  ↑
    mid peak

mid=5 > mid+1=4, so peak is at mid or left

[1, 3, 5, 4, 2]
     ↑
    found peak at index 2
```

---

## 7. 2D Matrix Binary Search

### Pattern 1: Row-sorted, first element > last of previous
```
[1,  3,  5,  7]
[10, 11, 16, 20]
[23, 30, 34, 60]

Treat as 1D sorted array of size m*n
mid → row = mid/n, col = mid%n
```

### Pattern 2: Row-sorted, column-sorted (search from top-right)
```
[1,  4,  7, 11]
[2,  5,  8, 12]
[3,  6,  9, 16]

Start at top-right corner:
- If current > target: move LEFT
- If current < target: move DOWN
- If current == target: found!
```

### Visual (Top-Right Search)
```
Target = 9

[1,  4,  7, 11]     [1,  4,  7, 11]     [1,  4,  7, 11]
[2,  5,  8, 12]  →  [2,  5,  8, 12]  →  [2,  5,  8, 12]
[3,  6,  9, 16]     [3,  6,  9, 16]     [3,  6,  9, 16]
                ↑                        ↑
             11>9, left            8<9, down
                                  
                                  [1,  4,  7, 11]
                                  [2,  5,  8, 12]  → Found!
                                  [3,  6,  9, 16]
                                            ↑
```

---

## 8. Common Mistakes & Fixes

| Mistake | Wrong | Right |
|---------|-------|-------|
| Overflow in mid | `(lo + hi) / 2` | `lo + (hi - lo) / 2` |
| Infinite loop | `lo = mid` | `lo = mid + 1` |
| Wrong boundary | `lo <= hi` | `lo < hi` (for boundary) |
| Empty array | No check | Always check first |

---

## 9. Binary Search Decision Flowchart

```
START
  │
  ├─ Is array sorted?
  │   ├─ YES → Basic binary search
  │   └─ NO → Is it rotated sorted?
  │       ├─ YES → Rotated array search
  │       └─ NO → Can you binary search on answer?
  │           ├─ YES → Binary search on answer
  │           └─ NO → Consider other approaches
  │
  ├─ Need first/last occurrence?
  │   ├─ YES → Use lower_bound/upper_bound
  │   └─ NO → Use basic binary search
  │
  └─ Need to check feasibility?
      ├─ YES → Binary search on answer
      └─ NO → Binary search on array
```
