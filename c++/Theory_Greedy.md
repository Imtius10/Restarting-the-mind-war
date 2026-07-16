# Greedy - Complete Theory & Intuition Guide

> Understand WHEN and WHY greedy works, not just the pattern.

---

## 1. What is Greedy Algorithm?

### Definition
Make the locally optimal choice at each step, hoping to find a global optimum.

### Key Question
"Can I make the best choice RIGHT NOW without regret?"

### Visual Thinking
```
┌─────────────────────────────────────────────────┐
│  Problem State                                  │
│  ┌─────┬─────┬─────┬─────┬─────┐              │
│  │  A  │  B  │  C  │  D  │  E  │  Choices     │
│  └─────┴─────┴─────┴─────┴─────┘              │
│      ↓                                         │
│  Pick BEST option now (greedy choice)          │
│      ↓                                         │
│  Problem reduces to smaller subproblem         │
│      ↓                                         │
│  Repeat until done                             │
└─────────────────────────────────────────────────┘
```

---

## 2. When Does Greedy Work?

### Two Key Properties

**1. Greedy Choice Property:**
"Making the locally optimal choice leads to global optimum"

**2. Optimal Substructure:**
"Optimal solution contains optimal solutions to subproblems"

### When Greedy Fails

**Coin change with non-canonical denominations:**
```
Coins: [1, 3, 4], Amount: 6
Greedy: 4+1+1 = 3 coins (WRONG!)
Optimal: 3+3 = 2 coins (need DP)
```

---

## 3. Interval Scheduling - The Classic Greedy

### Problem
Given intervals, select maximum non-overlapping ones.

### Why Sort by End Time?

Consider two intervals that overlap:
```
A: [1, 5]  and  B: [3, 7]

Option 1: Pick A (ends at 5)
- Can still pick anything starting at 5+
- Leaves more room for future intervals

Option 2: Pick B (ends at 7)
- Blocks more time
- Fewer opportunities for other intervals

GREEDY CHOICE: Always pick the one that ends earliest!
```

### Step by Step Example

Intervals: `[(1,4), (3,5), (0,6), (5,7), (3,9), (5,9), (6,10), (8,11)]`

```
Step 1: Sort by end time
[(1,4), (3,5), (0,6), (5,7), (3,9), (5,9), (6,10), (8,11)]

Step 2: Pick first (1,4), last_end = 4

Step 3: Check (3,5): 3 < 4? YES, skip

Step 4: Check (0,6): 0 < 4? YES, skip

Step 5: Check (5,7): 5 >= 4? YES, pick it! last_end = 7

Step 6: Check (3,9): 3 < 7? YES, skip

Step 7: Check (5,9): 5 < 7? YES, skip

Step 8: Check (6,10): 6 < 7? YES, skip

Step 9: Check (8,11): 8 >= 7? YES, pick it! last_end = 11

RESULT: 3 intervals [(1,4), (5,7), (8,11)]
```

### Visual
```
Time: 0  1  2  3  4  5  6  7  8  9  10 11
      |  |  |  |  |  |  |  |  |  |  |  |
A:    [-----------]
B:       [-----------]
C: [-------------------]
D:                [---------]
E:       [---------------------]
F:             [---------------------]
G:                   [-------------------]
H:                         [--------------]

PICKED: A, D, H ✓
```

---

## 4. Coin Change - Greedy vs DP

### Canonical Coin System (Greedy works)
```
Coins: [1, 5, 10, 25]

Make 41 cents:
Greedy: 25 + 10 + 5 + 1 = 4 coins ✓
Why? Larger coins are always multiples of smaller ones

VISUAL:
41 = 25 + 10 + 5 + 1
     ██ + ██ + ██ + █
     The greedy choice (25) is always part of optimal solution
```

### Non-Canonical (Greedy fails)
```
Coins: [1, 3, 4], Amount: 6

Greedy: 4 + 1 + 1 = 3 coins ✗
Optimal: 3 + 3 = 2 coins ✓

WHY? 4 is not a "clean" multiple of 3

VISUAL:
6 = 4 + 1 + 1  (greedy picks big coin first)
  = 3 + 3      (better to use two medium coins)
```

---

## 5. Jump Game - Reachability Greedy

### Problem
Can you reach the last index?

### Intuition
Track the farthest we can reach

```
nums = [2, 3, 1, 1, 4]

Step by step:
i=0: maxReach = max(0, 0+2) = 2
     Can reach indices 0,1,2

i=1: maxReach = max(2, 1+3) = 4
     Can reach indices 0,1,2,3,4 ← reached end!

i=2: maxReach = max(4, 2+1) = 4 (no change)
```

### Visual
```
Index: 0  1  2  3  4
Value: 2  3  1  1  4
       →  →
          →  →  →  →
             →
                →

At i=0, can jump 2 steps
At i=1, can jump 3 steps (farthest!)
Reach index 4 ✓
```

### Code Pattern
```cpp
int maxReach = 0;
for (int i = 0; i < n; i++) {
    if (i > maxReach) return false;  // stuck!
    maxReach = max(maxReach, i + nums[i]);
}
return true;
```

---

## 6. Task Scheduling - Frequency Greedy

### Problem
Complete tasks with cooldown n. Minimize total time.

### Intuition
1. Do the most frequent task first (reduces idle time)
2. Fill idle slots with other tasks
3. If no tasks left, just wait

### Example
```
tasks = [A,A,A,B,B,B], n = 2

Step 1: Count frequency
A: 3, B: 3

Step 2: Arrange with cooldown
A _ _ A _ _ A    (cooldown of 2 between A's)

Step 3: Fill gaps with B
A B _ A B _ A    (B fills some gaps)

Step 4: Complete B
A B B A B B A    (B can be adjacent if no cooldown)

Total: 8 time units
```

### Visual
```
Time: 1  2  3  4  5  6  7  8
      A  B  _  A  B  _  A  B
      ↓     ↓     ↓     ↓
    task  idle  task  idle

Formula: (maxFreq - 1) * (n + 1) + countOfMaxFreq

maxFreq = 3, countOfMax = 2 (A and B both have freq 3)
(3-1) * (2+1) + 2 = 2*3 + 2 = 8 ✓
```

---

## 7. Candy Distribution - Two Pass Greedy

### Problem
Give candies so higher rated kids get more than neighbors.

### Why Two Passes?
- Left-to-right: Ensure right neighbor gets more if rating higher
- Right-to-left: Ensure left neighbor gets more if rating higher

### Example
```
ratings = [1, 3, 2, 2, 1]

Pass 1 (Left to Right):
ratings: 1  3  2  2  1
candies: 1  2  1  1  1
         ↓  ↓  ↓  ↓  ↓
         1  2  1  1  1
         (3>1 so 2, rest stay 1)

Pass 2 (Right to Left):
ratings: 1  3  2  2  1
candies: 1  2  1  1  1
         ↓  ↓  ↓  ↓  ↓
         1  2  2  2  1
         (2>1 so 2, 2>=2 so no change, 2>1 so 2)

Final: [1, 2, 2, 2, 1] = 8 candies
```

### Visual
```
Rating:  1   3   2   2   1
         ↓   ↓   ↓   ↓   ↓
Candy:   1   2   2   2   1

Check: 1<2✓ 2<3✓ 2=2✓ 2>1✓
```

---

## 8. Largest Number - Custom Comparator

### Problem
Arrange numbers to form largest number.

### Intuition
Compare "which ordering is better": ab or ba?

```
Example: nums = [3, 30, 34, 5, 9]

Compare 3 and 30:
"330" vs "303" → 330 > 303, so 3 should come first

Compare 3 and 34:
"334" vs "343" → 334 < 343, so 34 should come first

Sort with custom comparator: a+b > b+a means a should come first
```

### Result
```
Sorted: [9, 5, 34, 3, 30]
Output: "9534330"
```

---

## 9. Meeting Rooms II - Minimum Rooms

### Problem
Find minimum rooms needed for all meetings.

### Intuition
- Track when meetings START and END
- If a meeting starts before another ends, need extra room

### Example
```
meetings = [[0,30], [5,10], [15,20]]

Sort starts: [0, 5, 15]
Sort ends:   [10, 20, 30]

Timeline:
Time: 0  5  10 15 20 30
      |  |  |  |  |  |
M1:   [--------------------]
M2:      [-----]
M3:                [-----]

At time 5: M1 and M2 overlap → need 2 rooms
At time 15: M1 and M3 overlap → need 2 rooms
```

---

## 10. Greedy Checklist - When to Use

### Ask Yourself

1. **"Can I sort the input?"**
   - Sort by some criterion
   - Make greedy choice based on sorted order

2. **"Does the problem have intervals?"**
   - Sort by END time for non-overlapping
   - Sort by START time for merging
   - Use heap for "how many overlap at once"

3. **"Am I making local optimal choices?"**
   - If each choice doesn't affect future choices → Greedy
   - If choices affect future → DP

4. **"Can I prove greedy works?"**
   - Exchange argument: swapping choices doesn't improve
   - Greedy stays ahead: greedy is always at least as good

### Common Greedy Patterns

| Pattern | When to Use |
|---------|-------------|
| Sort + Pick | Sort by criterion, greedily pick |
| Two Pointers | Sort array, pointers from ends |
| Priority Queue | Dynamic selection, always pick best |
| Two Pass | Handle one direction, then opposite |
