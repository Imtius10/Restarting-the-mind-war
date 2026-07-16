# Bitmasking - Complete Theory & Intuition Guide

> Master bit manipulation tricks and bitmask DP.

---

## 1. Why Bit Manipulation?

### Speed
- Bitwise operations are O(1) - single CPU instruction
- Much faster than loops or conditionals

### Space
- Use single integer to represent SET of elements
- n bits → can represent subsets of n elements
- 32-bit int → subset of up to 32 elements
- 64-bit long long → subset of up to 64 elements

### Parallelism
- Process multiple values simultaneously
- Check multiple conditions in one operation

---

## 2. Bit Basics - Visual Guide

### Binary Representation
```
Decimal:    42
Binary:     101010

Position:   5  4  3  2  1  0
Value:      1  0  1  0  1  0
Power:      32 16 8  4  2  1

42 = 32 + 8 + 2 = 2^5 + 2^3 + 2^1
```

### Bit Positions
```
Number: 42 = 101010

Bit 5: 1 ████
Bit 4: 0
Bit 3: 1 ████
Bit 2: 0
Bit 1: 1 ████
Bit 0: 0
```

---

## 3. Basic Bit Operations

### AND (&): Both bits must be 1
```
1010 & 1100 = 1000

Use: Check if specific bit is set
(n >> i) & 1  →  returns bit at position i
```

### OR (|): At least one bit must be 1
```
1010 | 1100 = 1110

Use: Set specific bit
n | (1 << i)  →  sets bit i to 1
```

### XOR (^): Bits must be different
```
1010 ^ 1100 = 0110

Use: Toggle specific bit
n ^ (1 << i)  →  toggles bit i
```

### NOT (~): Flips all bits
```
~1010 = ...0101 (in 2's complement)

Use: Clear specific bit
n & ~(1 << i)  →  clears bit i
```

### LEFT SHIFT (<<): Multiply by 2^n
```
1 << 3 = 8  (1 * 2^3)
5 << 2 = 20 (5 * 4)
```

### RIGHT SHIFT (>>): Divide by 2^n
```
8 >> 2 = 2  (8 / 4)
20 >> 1 = 10 (20 / 2)
```

---

## 4. Bit Tricks - The Powerful Ones

### Trick 1: Check if Power of 2
```
n & (n-1) == 0

Visual:
n = 16 = 10000
n-1 = 15 = 01111
n & (n-1) = 00000 = 0 ✓

Why? n-1 flips all bits up to and including lowest set bit
If only one bit set, result is 0
```

### Trick 2: Isolate Lowest Set Bit
```
n & (-n)

Visual:
n = 12 = 1100
-n (2's complement) = 0100
n & (-n) = 0100 = 4

Why? -n = ~n + 1 = flip all bits, add 1
This isolates the rightmost 1
```

### Trick 3: Clear Lowest Set Bit
```
n & (n-1)

Visual:
n = 12 = 1100
n-1 = 11 = 1011
n & (n-1) = 1000 = 8

Why? n-1 flips all bits from rightmost 1
AND keeps only bits that are 1 in both
```

### Trick 4: Count Set Bits (Brian Kernighan)
```
while (n) { n &= (n-1); count++; }

Visual:
n = 12 = 1100
n & (n-1) = 1000 (clear lowest 1)
n & (n-1) = 0000 (clear next 1)
Count = 2 ✓
```

### Trick 5: Check if Bit i Is Set
```
(n >> i) & 1

Visual:
n = 42 = 101010
Check bit 3: (42 >> 3) & 1 = (101) & 1 = 1 ✓
Check bit 2: (42 >> 2) & 1 = (1010) & 1 = 0 ✗
```

### Trick 6: Set Bit i
```
n | (1 << i)

Visual:
n = 42 = 101010
Set bit 2: 42 | (1 << 2) = 101010 | 000100 = 101110 = 46
```

### Trick 7: Clear Bit i
```
n & ~(1 << i)

Visual:
n = 42 = 101010
Clear bit 1: 42 & ~(1 << 1) = 101010 & 111101 = 101000 = 40
```

### Trick 8: Toggle Bit i
```
n ^ (1 << i)

Visual:
n = 42 = 101010
Toggle bit 2: 42 ^ (1 << 2) = 101010 ^ 000100 = 101110 = 46
Toggle bit 2 again: 46 ^ (1 << 2) = 101110 ^ 000100 = 101010 = 42
```

---

## 5. Subset Generation - The Key Insight

### Representing Subsets with Bitmasks
For n elements, use n-bit integer. Bit i = 1 means element i is in subset.

```
Example: {a, b, c}
000 = {} (empty set)
001 = {c} (only bit 0 set)
010 = {b} (only bit 1 set)
011 = {b, c}
100 = {a}
101 = {a, c}
110 = {a, b}
111 = {a, b, c} (full set)
```

### Visual
```
3 elements: a, b, c
Mask: 101

Bit 2: 1 → 'a' is IN subset
Bit 1: 0 → 'b' is NOT in subset
Bit 0: 1 → 'c' is IN subset

Subset = {a, c}
```

### Generating All Subsets
```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    // mask represents one subset
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // element i is in this subset
        }
    }
}
```

### Example: All subsets of {1, 2, 3}
```
mask=0: 000 → {}
mask=1: 001 → {3}
mask=2: 010 → {2}
mask=3: 011 → {2, 3}
mask=4: 100 → {1}
mask=5: 101 → {1, 3}
mask=6: 110 → {1, 2}
mask=7: 111 → {1, 2, 3}

2^3 = 8 subsets ✓
```

### Visual Flow
```
Start: mask = 000
       ↓
All combinations:
000 → 001 → 010 → 011 → 100 → 101 → 110 → 111
 ↓     ↓     ↓     ↓     ↓     ↓     ↓     ↓
 {}   {c}   {b}  {b,c}  {a}  {a,c} {a,b} {a,b,c}
```

---

## 6. Bitmask DP - Traveling Salesman

### Problem
Visit all cities exactly once, return to start (min cost).

### State
`dp[mask][i]` = min cost to visit cities in mask, ending at city i

### Transition
```
dp[mask | (1<<j)][j] = min(
    dp[mask | (1<<j)][j],
    dp[mask][i] + dist[i][j]
)
```

### Visual
```
4 cities: A, B, C, D

mask=0001 (only city 0):
  dp[0001][0] = 0 (start at city 0)

mask=0011 (cities 0,1):
  dp[0011][1] = dp[0001][0] + dist[0][1]

mask=0111 (cities 0,1,2):
  dp[0111][2] = min(
      dp[0011][1] + dist[1][2],  (came from 1)
      dp[0101][2] + dist[2][2]   (came from 2)
  )

mask=1111 (all cities):
  dp[1111][0] = min over all i of:
      dp[1110][i] + dist[i][0]  (return to start)
```

### Code
```cpp
int tsp(vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    dp[1][0] = 0;  // start at city 0
    
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int newMask = mask | (1 << v);
                dp[newMask][v] = min(
                    dp[newMask][v],
                    dp[mask][u] + dist[u][v]
                );
            }
        }
    }
    
    int result = INT_MAX;
    for (int u = 0; u < n; u++)
        result = min(result, dp[(1 << n) - 1][u] + dist[u][0]);
    return result;
}
```

---

## 7. Bitmask DP - Assignment Problem

### Problem
N workers, N jobs. Each worker-job has cost. Assign each worker to exactly one job (min cost).

### State
`dp[mask]` = min cost to assign first `popcount(mask)` workers to jobs in mask

### Transition
```
worker = popcount(mask)
for each unassigned job j:
    dp[mask | (1<<j)] = min(
        dp[mask | (1<<j)],
        dp[mask] + cost[worker][j]
    )
```

### Visual
```
3 workers, 3 jobs

mask=000 (no jobs assigned):
  dp[000] = 0

mask=001 (job 0 assigned to worker 0):
  dp[001] = cost[0][0]

mask=011 (jobs 0,1 assigned to workers 0,1):
  dp[011] = min(
      dp[001] + cost[1][1],  (worker 1 gets job 1)
      dp[010] + cost[1][0]   (worker 1 gets job 0)
  )

mask=111 (all jobs assigned):
  dp[111] = min total cost
```

### Code
```cpp
int assignmentProblem(vector<vector<int>>& cost) {
    int n = cost.size();
    vector<int> dp(1 << n, INT_MAX / 2);
    dp[0] = 0;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        int worker = __builtin_popcount(mask);
        for (int job = 0; job < n; job++) {
            if (!(mask & (1 << job))) {
                int newMask = mask | (1 << job);
                dp[newMask] = min(
                    dp[newMask],
                    dp[mask] + cost[worker][job]
                );
            }
        }
    }
    return dp[(1 << n) - 1];
}
```

---

## 8. Subset Sum with Bitmask

### Problem
Count subsets that sum to K.

### Approach 1: Brute force with bitmask (O(2^n * n))
```cpp
for each mask:
    sum = 0
    for each bit set in mask:
        sum += arr[bit]
    if sum == K: count++
```

### Approach 2: Meet in middle (O(2^(n/2)))
Split array into two halves. Generate all subset sums for each half. For each sum in first half, find complement in second half.

### Visual (Meet in Middle)
```
arr = [1, 2, 3, 4, 5, 6], K = 9

Left half: [1, 2, 3]
Sums: {}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}
      0    1    2    3     3      4      5       6

Right half: [4, 5, 6]
Sums: {}, {4}, {5}, {6}, {4,5}, {4,6}, {5,6}, {4,5,6}
      0    4    5    6     9      10     11      15

For each sum in left, check if (K - sum) in right:
0 + 9 = 9 ✓ (subset {4,5})
3 + 6 = 9 ✓ (subset {3,6})
4 + 5 = 9 ✓ (subset {1,4,5})
5 + 4 = 9 ✓ (subset {2,4,5})
6 + 3 = 9 ✓ (subset {1,2,6})

Answer: 5 subsets
```

---

## 9. Bit Tricks Summary Table

| Operation | Code | Time |
|-----------|------|------|
| Check bit i | `(n >> i) & 1` | O(1) |
| Set bit i | `n \| (1 << i)` | O(1) |
| Clear bit i | `n & ~(1 << i)` | O(1) |
| Toggle bit i | `n ^ (1 << i)` | O(1) |
| Isolate lowest set bit | `n & (-n)` | O(1) |
| Clear lowest set bit | `n & (n-1)` | O(1) |
| Check power of 2 | `n > 0 && (n & (n-1)) == 0` | O(1) |
| Count set bits | `__builtin_popcount(n)` | O(1) |
| Count trailing zeros | `__builtin_ctz(n)` | O(1) |
| Count leading zeros | `__builtin_clz(n)` | O(1) |
| Generate all subsets | `for mask=0 to 2^n - 1` | O(2^n) |
| Check subset relationship | `(mask & sub) == sub` | O(1) |

---

## 10. When to Use Bitmasking

### Use Bitmask When
1. **n ≤ 20** (can afford 2^n operations)
2. Need to represent subsets of small set
3. Need to track which elements are "used"
4. Problem involves selecting/assigning elements

### Common Problem Types
- Traveling Salesman Problem (TSP)
- Assignment problem
- Subset sum
- Hamiltonian path/cycle
- Set cover (approximation)
- Game theory (minimax with state)

### Complexity
- Bitmask DP: O(2^n * n) or O(2^n * n^2)
- Feasible when n ≤ 20 (2^20 ≈ 10^6)
