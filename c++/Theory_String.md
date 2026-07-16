# String Algorithms - Complete Theory & Intuition Guide

> Understand KMP, Trie, Hashing and why they work.

---

## 1. String Basics - Why Strings Are Special

### Unique Challenges
- Strings can be very long (10^5 or more)
- Pattern matching naive = O(n*m) too slow
- Need smarter algorithms

### Key Insight
Strings have structure we can exploit:
- Repeated patterns (KMP)
- Prefix-suffix relationships (LPS array)
- Hierarchical structure (Trie)
- Hash values for quick comparison

---

## 2. KMP Algorithm - Pattern Matching

### Problem
Find all occurrences of pattern P in text T.
- Naive: O(n*m) - check every position
- KMP: O(n+m) - use pattern's structure to skip

### Key Concept: LPS (Longest Proper Prefix which is also Suffix)

**What is LPS?**
For pattern "ABAB":
- "A": LPS = 0
- "AB": proper prefixes = {"A"}, suffixes = {"B"}, no match, LPS=0
- "ABA": proper prefixes = {"A","AB"}, suffixes = {"A","BA"}
  "A" matches! LPS=1
- "ABAB": proper prefixes = {"A","AB","ABA"}, suffixes = {"BAB","AB","B"}
  "AB" matches! LPS=2

**LPS array:** `[0, 0, 1, 2]`

### Why LPS Helps
```
Text:    A B A B A B A C
Pattern: A B A B A C

Naive at position 4:
After matching ABAB, mismatch at C
Try shifting by 1: compare T[1] with P[0]
This wastes work!

KMP: Use LPS!
When mismatch at pattern[4] (C), LPS[3]=2
So shift pattern so that first 2 chars align:

Text:    A B A B A B A C
Pattern:     A B A B A C
              ↑
       We know "AB" matches (from LPS)!
       No need to re-check them!
```

### Building LPS
```
pattern: A B A B A C
lps[0] = 0 (always)

i=1, len=0: P[1]='B' ≠ P[0]='A' → lps[1]=0
i=2, len=0: P[2]='A' = P[0]='A' → lps[2]=1, len=1
i=3, len=1: P[3]='B' = P[1]='B' → lps[3]=2, len=2
i=4, len=2: P[4]='A' = P[2]='A' → lps[4]=3, len=3
i=5, len=3: P[5]='C' ≠ P[3]='B' → check lps[2]=1
            P[5]='C' ≠ P[1]='B' → check lps[0]=0
            P[5]='C' ≠ P[0]='A' → lps[5]=0

LPS = [0, 0, 1, 2, 3, 0]
```

### KMP Search
```
Text:    A B A B A B A C
Pattern: A B A B A C
         ↑           ↑
         match until C vs C... wait, C=C!

Actually let's use a better example:

Text:    A B A B A B A C
Pattern: A B A B A C
         ↑           ↑
         mismatch at position 5

LPS[4]=3, so shift pattern:
Text:    A B A B A B A C
Pattern:     A B A B A C
              ↑
         Already know AB matches!
         Compare from position 2 in pattern
```

### Code
```cpp
vector<int> buildLPS(string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];  // fall back
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

int strStr(string haystack, string needle) {
    vector<int> lps = buildLPS(needle);
    int i = 0, j = 0;
    while (i < haystack.size()) {
        if (haystack[i] == needle[j]) { i++; j++; }
        if (j == needle.size()) return i - j;  // found!
        else if (i < haystack.size() && haystack[i] != needle[j]) {
            if (j) j = lps[j - 1];  // use LPS to skip
            else i++;
        }
    }
    return -1;
}
```

---

## 3. Trie (Prefix Tree)

### What is a Trie?
Tree where each node represents a character. Path from root to node = prefix of some string.

### Example: Insert "cat", "car", "dog"
```
         root
        /    \
       c      d
       |      |
       a      o
      / \     |
     t   r    g
     ↑   ↑    ↑
   "cat" "car" "dog"
```

### Why Use Trie?
- Fast prefix search: O(m) where m = word length
- No need to check all words
- Share common prefixes

### Trie Operations

**INSERT "cat":**
```
root → c → a → t (mark as end)
```

**INSERT "car":**
```
root → c → a (already exists)
       → r (new, mark as end)
```

**SEARCH "car":**
```
root → c → a → r → found! (isEnd=true)
```

**SEARCH "ca":**
```
root → c → a → end of search string
But a->isEnd = false, so "ca" not in trie
```

**STARTSWITH "ca":**
```
root → c → a → reached! return true
```

### Visual - Searching with Wildcard
Search "c.t" in trie:
```
         root
        /    \
       c      d
       |      |
       a      o
      / \     |
     t   r    g

Start at root, char = 'c'
Go to c node

Next char = '.', wild card! Try ALL children:
  Try 'a' → go to a node
    Next char = 't'
    Try 't' → found! return true
    Try 'r' → r != t, no match
  Try 'o' → no 'o' child from c

Result: found
```

### Code
```cpp
class Trie {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    } *root;

public:
    Trie() : root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};
```

---

## 4. String Hashing (Rabin-Karp)

### What is String Hashing?
Convert string to a number (hash). Compare hashes instead of characters. Same hash = probably same string (collision unlikely).

### Hash Formula
```
hash(s) = s[0]*p^(n-1) + s[1]*p^(n-2) + ... + s[n-1] mod M

p = base (e.g., 31)
M = large prime (e.g., 10^9+7)
```

### Why This Works?
- Each position contributes uniquely
- Like converting from base-p to decimal
- Different strings → different hashes (with high probability)

### Rolling Hash
Compute hash of next window from current hash.
```
hash("ABCD") → hash("BCDE")

Remove 'A': hash = hash - 'A' * p^(n-1)
Add 'E': hash = hash * p + 'E'

O(1) per shift!
```

### Visual
```
Text: "ABCAB", Pattern: "ABC"

Pattern hash: 'A'*31^2 + 'B'*31^1 + 'C'*31^0
             = 65*961 + 66*31 + 67
             = 62465 + 2046 + 67 = 64578

Window 1: "ABC" hash = 64578 ✓ Match!

Window 2: "BCA"
Rolling: remove 'A' (leftmost), add 'A' (rightmost)
hash = (64578 - 65*961) * 31 + 65
     = (64578 - 62465) * 31 + 65
     = 2113 * 31 + 65 = 65568

Window 3: "CAB"
Rolling: remove 'B', add 'B'
hash = (65568 - 66*961) * 31 + 66
     = (65568 - 63426) * 31 + 66
     = 2142 * 31 + 66 = 66468
```

### Code
```cpp
vector<int> rabinKarp(string& text, string& pattern) {
    const int base = 31, mod = 1e9 + 7;
    int n = text.size(), m = pattern.size();
    
    long long patternHash = 0, textHash = 0, power = 1;
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % mod;
        textHash = (textHash * base + text[i]) % mod;
        if (i < m - 1) power = (power * base) % mod;
    }
    
    vector<int> result;
    for (int i = m; i <= n; i++) {
        if (patternHash == textHash)
            result.push_back(i - m);
        if (i < n) {
            textHash = (textHash - text[i-m] * power % mod + mod) % mod;
            textHash = (textHash * base + text[i]) % mod;
        }
    }
    return result;
}
```

---

## 5. Z-Algorithm

### What is Z-Array?
`Z[i]` = length of longest substring starting at i that is also a prefix of the string.

### Example: s = "aabxaab"
```
Index: 0 1 2 3 4 5 6
Char:  a a b x a a b

Z[0] = 0 (by definition)
Z[1]: Compare s[1..] with s[0..]
      "aabxab" vs "aabxaab"
      Match length = 2 ("aa")
      Z[1] = 2
Z[2]: "bxab" vs "aab..."
      'b' ≠ 'a', no match
      Z[2] = 0
Z[3]: "xab" vs "aab..."
      'x' ≠ 'a', no match
      Z[3] = 0
Z[4]: "aab" vs "aab..."
      Match length = 3 ("aab")
      Z[4] = 3
Z[5]: "ab" vs "aab..."
      'a' = 'a', but 'b' ≠ 'a', match = 1
      Z[5] = 1
Z[6]: "b" vs "aab..."
      'b' ≠ 'a', no match
      Z[6] = 0

Z = [0, 2, 0, 0, 3, 1, 0]
```

### Why Z-Algorithm?
- Pattern matching: Create `s + "#" + pattern`
- If any `Z[i] = pattern.length()`, pattern found!

```
Example: Find "aab" in "xaabaab"
Combined = "aab#xaabaab"
Z-array will show Z[6]=3, match found!
```

### Code
```cpp
vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
```

---

## 6. Suffix Array (Brief Intro)

### What is Suffix Array?
Array of all suffixes sorted lexicographically.

### Example: s = "banana"
```
Suffixes:
0: banana
1: anana
2: nana
3: ana
4: na
5: a

Sorted:
5: a          (rank 0)
3: ana        (rank 1)
1: anana      (rank 2)
0: banana     (rank 3)
4: na         (rank 4)
2: nana       (rank 5)

Suffix Array = [5, 3, 1, 0, 4, 2]
```

### Why Useful?
- Longest repeated substring: max of LCP array
- Longest common substring: build SA for `s1+"#"+s2`
- Pattern matching in O(m log n)

### LCP Array (Longest Common Prefix)
`LCP[i]` = length of longest common prefix between `SA[i]` and `SA[i-1]`

```
For "banana":
SA: 5, 3, 1, 0, 4, 2
LCP: -, 1, 3, 0, 0, 2

LCP[2] = 3: "ana" and "anana" share "ana"
```

---

## 7. Common String Problems & Patterns

### Palindromes
- Expand around center: O(n²)
- Manacher's algorithm: O(n)

**Intuition:** Each character (or between characters) can be center of palindrome. Expand outward while symmetric.

### Subsequence vs Substring
- **Substring:** contiguous characters
- **Subsequence:** can skip characters

```
"abc" is substring of "xabcy"
"ac" is subsequence of "xabcy"
```

### Anagram Detection
- Sort both strings: O(m log m)
- Frequency count: O(m)
- Frequency difference: O(m)

### Word Break
- DP: `dp[i]` = can we segment `s[0..i]`?
- Trie: store dictionary, search character by character
