# Two Pointers - Complete Theory & Intuition Guide

> Master the 4 main two-pointer patterns and when to use each.

---

## 1. What is Two Pointers?

### Definition
Use two indices (pointers) to traverse data structure, usually from different positions or at different speeds.

### Why It Works
- Reduces O(n²) brute force to O(n)
- Exploits structure in data (sorted, linked list, etc.)

### Visual Concept
```
One pointer →                ← Other pointer
[   ·   ·   ·   ·   ·   ·   ·   ·   ]
↑                                   ↑
left                              right

Both pointers move based on some condition
```

---

## 2. Pattern 1: Opposite Direction (Sorted Array)

### When to Use
- Array is sorted (or can be sorted)
- Finding pair with specific sum/difference
- Two elements that satisfy some condition

### How It Works
1. Start with `left=0`, `right=n-1`
2. Calculate some value from `arr[left]` and `arr[right]`
3. Move left if value too small, move right if too large

### Example: Two Sum II (LeetCode #167)
```
arr = [2, 7, 11, 15], target = 9

Step 1: left=0, right=3
[2, 7, 11, 15]
 ↑           ↑
 2+15=17 > 9, move right ←

Step 2: left=0, right=2
[2, 7, 11, 15]
 ↑        ↑
 2+11=13 > 9, move right ←

Step 3: left=0, right=1
[2, 7, 11, 15]
 ↑     ↑
 2+7=9 = 9 ✓ FOUND!
```

### Why Move Right When Sum Too Large?
```
arr is sorted ascending
If arr[left] + arr[right] > target
Then arr[left] + arr[smaller_right] might work
So move right leftward
```

### Code
```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) return {left + 1, right + 1};
        else if (sum < target) left++;
        else right--;
    }
    return {};
}
```

---

## 3. Pattern 2: 3SUM / 4SUM (Fix One, Two Pointers for Rest)

### Intuition
- Sort array
- Fix first element (loop)
- Use two pointers for remaining two elements

**Reduces O(n³) to O(n²)**

### 3SUM Visual
```
nums = [-1, 0, 1, 2, -1, -4]
After sort: [-4, -1, -1, 0, 1, 2]

Fix i=0 (value -4):
[-4, -1, -1, 0, 1, 2]
  ↑  ↑              ↑
  i  left        right

-4 + (-1) + 2 = -3 < 0, move left →

[-4, -1, -1, 0, 1, 2]
  ↑     ↑           ↑
  i   left      right

-4 + (-1) + 2 = -3 < 0, move left →

[-4, -1, -1, 0, 1, 2]
  ↑        ↑        ↑
  i      left    right

-4 + 0 + 2 = -2 < 0, move left →

[-4, -1, -1, 0, 1, 2]
  ↑           ↑     ↑
  i         left  right

-4 + 1 + 2 = -1 < 0, move left →

left >= right, done with i=0

Fix i=1 (value -1):
[-4, -1, -1, 0, 1, 2]
     ↑  ↑           ↑
     i left     right

-1 + (-1) + 2 = 0 = target ✓ FOUND!
Add [-1, -1, 2] to result
```

### Code
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;  // skip duplicates
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                left++; right--;
            } else if (sum < 0) left++;
            else right--;
        }
    }
    return result;
}
```

---

## 4. Pattern 3: Sliding Window (Substring/Subarray)

### When to Use
- Finding subarray/substring with specific property
- Contiguous elements
- Can use hash map/set to track window contents

### How It Works
1. Expand window by moving right pointer
2. When window is invalid, shrink from left
3. Update answer at each valid window

### Template
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // 1. Add element at right to window
    
    // 2. While window is invalid, shrink
    while (window_invalid) {
        // Remove element at left from window
        left++;
    }
    
    // 3. Update answer
}
```

### Example: Longest Substring Without Repeating (LeetCode #3)
```
s = "abcabcbb"

right=0: 'a' → window = {a}, len=1, max=1
right=1: 'b' → window = {a,b}, len=2, max=2
right=2: 'c' → window = {a,b,c}, len=3, max=3
right=3: 'a' → 'a' exists! shrink:
           remove 'a' at left, left=1
           window = {b,c,a}, len=3, max=3
right=4: 'b' → 'b' exists! shrink:
           remove 'b' at left, left=2
           window = {c,a,b}, len=3, max=3
right=5: 'c' → 'c' exists! shrink:
           remove 'c' at left, left=3
           window = {a,b,c}, len=3, max=3
right=6: 'b' → 'b' exists! shrink:
           remove 'a' at left, left=4
           remove 'b' at left, left=5
           window = {c,b}, len=2
right=7: 'b' → 'b' exists! shrink:
           remove 'c' at left, left=6
           remove 'b' at left, left=7
           window = {b}, len=1

VISUAL:
s = a b c a b c b b
    ↑     ↑
    left  right=3 (duplicate 'a')
    
    move left to remove 'a'
```

### Code
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int maxLen = 0, left = 0;
    for (int right = 0; right < s.size(); right++) {
        if (lastSeen.count(s[right]) && lastSeen[s[right]] >= left)
            left = lastSeen[s[right]] + 1;
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

---

## 5. Pattern 4: Fast & Slow Pointers (Cycle Detection)

### When to Use
- Linked list cycle detection
- Finding middle of linked list
- Finding cycle start point

### How It Works
- Slow pointer: moves 1 step
- Fast pointer: moves 2 steps
- If there's a cycle, they **WILL** meet

### Visual (Cycle Detection)
```
1 → 2 → 3 → 4
        ↑   ↓
        7 ← 6 ← 5

Step 0: slow=1, fast=1
Step 1: slow=2, fast=3
Step 2: slow=3, fast=5
Step 3: slow=4, fast=7
Step 4: slow=5, fast=3
Step 5: slow=6, fast=5
Step 6: slow=7, fast=7 → MEET! Cycle exists
```

### Visual (Find Middle)
```
1 → 2 → 3 → 4 → 5

Step 0: slow=1, fast=1
Step 1: slow=2, fast=3
Step 2: slow=3, fast=5
fast.next = NULL, stop
slow is at middle (3)
```

### Why Fast Moves 2 Steps?
- They get closer by 1 step each iteration
- In a cycle, they must eventually meet
- Time to meet = length of cycle

### Code (Cycle Detection)
```cpp
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

### Code (Find Cycle Start)
```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // cycle start
        }
    }
    return nullptr;
}
```

---

## 6. Pattern 5: Dutch National Flag (3-Way Partition)

### When to Use
- Sort array with only 3 distinct values (0, 1, 2)
- Partition into 3 groups

### How It Works
Three pointers:
- `low`: boundary for 0s
- `mid`: current element
- `high`: boundary for 2s

### Example: Sort `[2, 0, 2, 1, 1, 0]`

```
Initial:
[2, 0, 2, 1, 1, 0]
 ↑           ↑
low=0      high=5
    ↑
   mid=0

Step 1: mid=0, arr[mid]=2
2 should go to high section
swap(arr[mid], arr[high])
high--, mid++
[0, 0, 2, 1, 1, 2]
 ↑        ↑     ↑
low    mid   high

Step 2: mid=1, arr[mid]=0
0 should go to low section
swap(arr[low], arr[mid])
low++, mid++
[0, 0, 2, 1, 1, 2]
    ↑  ↑        ↑
   low mid    high

Step 3: mid=2, arr[mid]=2
swap(arr[mid], arr[high])
high--, mid++
[0, 0, 1, 1, 2, 2]
    ↑     ↑     ↑
   low  mid   high

Step 4: mid=3, arr[mid]=1
1 is in correct place, just mid++
[0, 0, 1, 1, 2, 2]
    ↑        ↑
   low      high
         ↑
        mid (past high, done!)
```

### Code
```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}
```

---

## 7. Rainwater Trapping - Two Pointers Optimized

### Problem
Calculate water trapped between bars.

### Intuition
Water at index i = `min(max_left, max_right) - height[i]`

Two pointers approach:
- Track `max_left` and `max_right`
- Move the pointer with smaller max
- Water is determined by the smaller max

### Visual
```
height = [0,1,0,2,1,0,1,3,2,1,2,1]

Index:   0  1  2  3  4  5  6  7  8  9 10 11
Height:  0  1  0  2  1  0  1  3  2  1  2  1

Water at i=2: min(1, 3) - 0 = 1
Water at i=4: min(2, 3) - 1 = 1
Water at i=5: min(2, 3) - 0 = 2
Water at i=6: min(2, 3) - 1 = 1
Water at i=9: min(3, 2) - 1 = 1
Water at i=10: min(3, 2) - 2 = 0
Water at i=11: min(3, 1) - 1 = 0

Total: 1+1+2+1+1 = 6
```

---

## 8. Two Pointers Decision Flowchart

```
START
  │
  ├─ Is array sorted?
  │   ├─ YES → Opposite direction (two sum, container)
  │   └─ NO → Sort first? If yes, sort then two pointers
  │
  ├─ Finding subarray/substring?
  │   ├─ YES → Sliding window
  │   └─ NO → Continue
  │
  ├─ Has linked list?
  │   ├─ YES → Fast & slow pointers
  │   └─ NO → Continue
  │
  ├─ Need to partition into groups?
  │   ├─ YES → Dutch National Flag
  │   └─ NO → Consider other approaches
  │
  └─ Finding triplet/quadruplet?
      ├─ YES → Fix one, two pointers for rest
      └─ NO → May not need two pointers
```

---

## Summary Table

| Pattern | When to Use | Time |
|---------|-------------|------|
| Opposite Direction | Sorted array, pair sum | O(n) |
| Fix One + Two Pointers | 3Sum, 4Sum | O(n²) |
| Sliding Window | Substring/subarray property | O(n) |
| Fast & Slow | Cycle detection, middle | O(n) |
| Dutch National Flag | 3-way partition | O(n) |
