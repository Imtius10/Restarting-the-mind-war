// ============================================================
// C++ STL COMPLETE GUIDE - All Concepts with Syntax & Examples
// ============================================================
// Topics: pair, vector, stack, queue, deque, set, multiset,
//         map, unordered_map, unordered_set, priority_queue,
//         bitset, string, algorithms
// ============================================================

#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 1. PAIR
// ============================================================
// Stores two values together. First element is primary key.
/*
Syntax:
    pair<int, int> p;              // {0, 0}
    pair<int, int> p(1, 2);        // {1, 2}
    pair<int, int> p = {1, 2};     // {1, 2}

    // Access
    p.first    // 1
    p.second   // 2

    // Nested pair
    pair<int, pair<int, int>> p = {1, {2, 3}};
    p.second.first  // 2

    // Vector of pairs
    vector<pair<int, int>> v;
    v.push_back({1, 2});
    v.push_back(make_pair(3, 4));

    // Sorting pairs: sorts by first, then by second
    sort(v.begin(), v.end());

    // Comparison: pair compares lexicographically (first then second)
    // {1,5} < {2,3}  because 1 < 2
    // {1,2} < {1,5}  because first equal, 2 < 5

    // Useful for: storing coordinates, mapping two values,
    //             returning multiple values from function
*/

void pairExample() {
    pair<int, string> p = {1, "hello"};
    cout << p.first << " " << p.second << endl;

    // Nested pair
    pair<int, pair<int, int>> np = {1, {2, 3}};
    cout << np.second.first << endl; // 2

    // Vector of pairs
    vector<pair<int, int>> v = {{3,1}, {1,2}, {2,3}};
    sort(v.begin(), v.end());
    // v = {{1,2}, {2,3}, {3,1}}
}

// ============================================================
// 2. VECTOR (Dynamic Array)
// ============================================================
// Resizable array. Contiguous memory. Amortized O(1) push_back.
/*
Syntax:
    vector<int> v;                  // empty
    vector<int> v(5);               // 5 elements, all 0
    vector<int> v(5, 10);           // 5 elements, all 10
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v(arr, arr+n);      // from array

    // Functions
    v.push_back(x)      // add x to end - O(1) amortized
    v.pop_back()        // remove last - O(1)
    v.size()            // number of elements
    v.empty()           // true if empty
    v.clear()           // remove all - O(n)
    v.insert(v.begin()+i, x)  // insert x at index i - O(n)
    v.erase(v.begin()+i)      // remove element at i - O(n)
    v.erase(v.begin()+i, v.begin()+j) // remove range [i, j)
    v.front()           // first element
    v.back()            // last element
    v[i]                // access at index i (no bounds check)
    v.at(i)             // access at index i (throws if out of bounds)

    // Iterators
    v.begin()           // iterator to first element
    v.end()             // iterator to past-the-end
    v.rbegin()          // reverse begin
    v.rend()            // reverse end

    // 2D Vector
    vector<vector<int>> grid(m, vector<int>(n, 0));

    // Emplace (avoids copy)
    v.emplace_back(x);  // constructs in-place

    // Resize
    v.resize(n);        // resize to n elements

    // Swap
    v1.swap(v2);        // swap two vectors

    // Shrink to fit
    v.shrink_to_fit();  // reduce capacity to size

    // Time Complexity:
    // push_back/pop_back: O(1) amortized
    // insert/erase at position: O(n)
    // access by index: O(1)
    // search: O(n)
*/

void vectorExample() {
    vector<int> v = {5, 3, 1, 4, 2};

    // Sort
    sort(v.begin(), v.end());                    // {1,2,3,4,5}
    sort(v.begin(), v.end(), greater<int>());    // {5,4,3,2,1}

    // Reverse
    reverse(v.begin(), v.end());

    // Binary search (must be sorted)
    bool found = binary_search(v.begin(), v.end(), 3);

    // Lower/Upper bound
    auto lb = lower_bound(v.begin(), v.end(), 3); // >= 3
    auto ub = upper_bound(v.begin(), v.end(), 3); // > 3

    // Remove duplicates (must be sorted)
    v.erase(unique(v.begin(), v.end()), v.end());

    // Count
    int cnt = count(v.begin(), v.end(), 3);

    // Find
    auto it = find(v.begin(), v.end(), 3);

    // Min/Max element
    auto mn = min_element(v.begin(), v.end());
    auto mx = max_element(v.begin(), v.end());

    // Accumulate
    int sum = accumulate(v.begin(), v.end(), 0);

    // Prefix sum
    vector<int> prefix(v.size());
    partial_sum(v.begin(), v.end(), prefix.begin());
}

// ============================================================
// 3. STACK (LIFO - Last In First Out)
// ============================================================
/*
Syntax:
    stack<int> s;

    s.push(x)          // add to top - O(1)
    s.emplace(x)       // construct in-place - O(1)
    s.pop()            // remove top - O(1)
    s.top()            // get top element - O(1)
    s.size()           // number of elements
    s.empty()           // true if empty
    s.swap(s2)         // swap two stacks

    // Underlying container: deque by default
    // Can use vector or list as underlying container:
    // stack<int, vector<int>> s;
    // stack<int, list<int>> s;

    // Time Complexity:
    // push/pop/top: O(1)
    // search: O(n) - no direct search

    // Use Cases:
    // - Balanced parentheses
    // - Undo operations
    // - DFS traversal
    // - Expression evaluation (infix to postfix)
    // - Next greater/smaller element
    // - Largest rectangle in histogram
*/

void stackExample() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    // Stack: [10, 20, 30] (top = 30)

    cout << s.top() << endl;  // 30
    s.pop();                   // remove 30
    cout << s.top() << endl;  // 20
    cout << s.size() << endl; // 2
    cout << s.empty() << endl; // false
}

// ============================================================
// 4. QUEUE (FIFO - First In First Out)
// ============================================================
/*
Syntax:
    queue<int> q;

    q.push(x)          // add to back - O(1)
    q.emplace(x)       // construct in-place - O(1)
    q.pop()            // remove front - O(1)
    q.front()          // get front element - O(1)
    q.back()           // get back element - O(1)
    q.size()
    q.empty()

    // Use Cases:
    // - BFS traversal
    // - Sliding window maximum/minimum
    // - Process scheduling
    // - Order processing (FIFO)
*/

// ============================================================
// 5. DEQUE (Double-Ended Queue)
// ============================================================
/*
Syntax:
    deque<int> dq;

    // All queue operations PLUS:
    dq.push_front(x)   // add to front - O(1)
    dq.push_back(x)    // add to back - O(1)
    dq.pop_front()     // remove from front - O(1)
    dq.pop_back()      // remove from back - O(1)
    dq[i]              // random access - O(1)
    dq.at(i)           // bounds-checked access

    // Also supports: insert, erase, begin, end, etc.

    // Time Complexity:
    // push_front/push_back: O(1)
    // pop_front/pop_back: O(1)
    // random access: O(1)
    // insert/erase middle: O(n)

    // Use Cases:
    // - Sliding window problems
    // - Implementing queue with front operations
    // - Monotonic deque
*/

void dequeExample() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(0);
    // dq = {0, 1, 2}

    dq.pop_front();  // dq = {1, 2}
    dq.pop_back();   // dq = {1}

    cout << dq.front() << endl; // 1
    cout << dq.back() << endl;  // 1
}

// ============================================================
// 6. SET (Sorted, Unique Elements)
// ============================================================
/*
Syntax:
    set<int> s;          // ascending order (default)
    set<int, greater<int>> s;  // descending order

    s.insert(x)         // add element - O(log n)
    s.emplace(x)        // construct in-place - O(log n)
    s.erase(x)          // remove by value - O(log n)
    s.erase(it)         // remove by iterator - O(1) amortized
    s.find(x)           // returns iterator to x, or end() - O(log n)
    s.count(x)          // returns 1 if present, 0 otherwise - O(log n)
    s.lower_bound(x)    // iterator to first >= x - O(log n)
    s.upper_bound(x)    // iterator to first > x - O(log n)
    s.size()
    s.empty()
    s.clear()

    // Iterators
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    // Reverse iterators
    for (auto it = s.rbegin(); it != s.rend(); ++it)

    // Set is always sorted. Underlying: Red-Black Tree (balanced BST).
    // All operations O(log n) except erase(iterator) O(1) amortized.

    // Use Cases:
    // - Fast lookup with sorted order
    // - Finding closest element (lower_bound/upper_bound)
    // - Removing duplicates from unsorted data
    // - maintaining sliding window minimum/maximum
*/

void setExample() {
    set<int> s = {3, 1, 4, 1, 5, 9};
    // s = {1, 3, 4, 5, 9} (duplicates removed, sorted)

    s.insert(2);        // s = {1, 2, 3, 4, 5, 9}
    s.erase(4);         // s = {1, 2, 3, 5, 9}

    if (s.count(3)) cout << "found" << endl;

    auto it = s.lower_bound(4); // iterator to 5 (first >= 4)
    auto it2 = s.upper_bound(3); // iterator to 5 (first > 3)
}

// =================================================_MULTISET
// 7. MULTISET (Sorted, Allows Duplicates)
// ============================================================
/*
Syntax:
    multiset<int> ms;

    // Same as set, but:
    // - count(x) returns actual count of x
    // - erase(x) removes ALL occurrences of x
    // - erase(ms.find(x)) removes ONE occurrence
    // - insert(x) always succeeds

    ms.insert(x)        // O(log n)
    ms.erase(ms.find(x)) // remove one occurrence - O(log n)
    ms.count(x)         // returns count of x - O(log n + count)
    ms.lower_bound(x)   // iterator to first >= x
    ms.upper_bound(x)   // iterator to first > x
    ms.equal_range(x)   // pair of {lower_bound, upper_bound}

    // Use Cases:
    // - Frequency counting with sorted order
    // - Maintaining sorted list with duplicates
    // - Finding kth smallest/largest
*/

void multisetExample() {
    multiset<int> ms = {1, 1, 2, 2, 2, 3};
    // ms = {1, 1, 2, 2, 2, 3}

    cout << ms.count(2) << endl;  // 3

    // Remove one occurrence of 2
    auto it = ms.find(2);
    if (it != ms.end()) ms.erase(it);
    // ms = {1, 1, 2, 2, 3}

    // Remove all occurrences of 1
    ms.erase(1);
    // ms = {2, 2, 3}

    // Equal range
    auto range = ms.equal_range(2);
    for (auto i = range.first; i != range.second; ++i)
        cout << *i << " ";  // 2 2
}

// ============================================================
// 8. MAP (Sorted Key-Value Pairs)
// ============================================================
/*
Syntax:
    map<int, string> m;           // sorted by key (ascending)
    map<int, string, greater<int>> m;  // descending

    m[key] = value                // insert or update - O(log n)
    m.insert({key, value})        // insert only if key not exists
    m.emplace(key, value)         // construct in-place
    m.erase(key)                  // remove by key - O(log n)
    m.find(key)                   // iterator to pair, or end()
    m.count(key)                  // 1 if key exists, 0 otherwise
    m.lower_bound(key)            // iterator to first >= key
    m.upper_bound(key)            // iterator to first > key
    m.size()
    m.empty()

    // Iteration
    for (auto &p : m)
        cout << p.first << " : " << p.second << endl;

    // Accessing with [] creates default entry if key doesn't exist!
    // Use count() or find() first to check existence.

    // Underlying: Red-Black Tree (balanced BST)
    // All operations O(log n)

    // Use Cases:
    // - Frequency counting
    // - Dictionary/lookup table
    // - Sorted data by key
    // - Two-pointer + map problems
*/

void mapExample() {
    map<string, int> m;
    m["alice"] = 90;
    m["bob"] = 85;
    m["charlie"] = 95;
    // m = {{"alice",90}, {"bob",85}, {"charlie",95}} (sorted by key)

    cout << m["alice"] << endl;  // 90

    // Check before accessing
    if (m.count("david"))
        cout << m["david"] << endl;

    // Iteration (sorted by key)
    for (auto &[key, value] : m)
        cout << key << ": " << value << endl;
}

// =================================================UNORDERED_MAP
// 9. UNORDERED_MAP (Hash Map - Average O(1))
// ============================================================
/*
Syntax:
    unordered_map<int, string> um;

    // Same API as map, but:
    // - No sorted order
    // - Average O(1) for insert, delete, search
    // - Worst case O(n) (hash collisions)
    // - Uses hash table internally

    um[key] = value       // O(1) average
    um.insert({key, value})
    um.erase(key)         // O(1) average
    um.find(key)          // O(1) average
    um.count(key)         // O(1) average

    // When to use:
    // - Need fast lookup, don't care about order
    // - Frequency counting
    // - Two sum type problems

    // unordered_set: same but only keys (no values)

    // Use Cases:
    // - Two Sum, Four Sum
    // - Anagram grouping
    // - Frequency counting
    // - Caching / memoization
*/

void unorderedMapExample() {
    unordered_map<string, int> um;
    um["apple"] = 3;
    um["banana"] = 5;

    cout << um["apple"] << endl;  // 3

    // Faster than map for pure lookup
}

// ============================================================
// 10. PRIORITY QUEUE (Max-Heap / Min-Heap)
// ============================================================
/*
Syntax:
    // Max-Heap (default) - largest element on top
    priority_queue<int> pq;

    // Min-Heap - smallest element on top
    priority_queue<int, vector<int>, greater<int>> pq;

    // Max-Heap of pairs (sorts by first, then second)
    priority_queue<pair<int, int>> pq;

    pq.push(x)           // O(log n)
    pq.emplace(x)        // O(log n)
    pq.pop()             // remove top - O(log n)
    pq.top()             // get top element - O(1)
    pq.size()
    pq.empty()

    // NO iteration, NO erase by value, NO find
    // Only top access.

    // Use Cases:
    // - Kth largest/smallest element
    // - Merge K sorted arrays/lists
    // - Top K frequent elements
    // - Dijkstra's shortest path
    // - Huffman coding
    // - Task scheduling by priority
    // - Median finding (using two heaps)
*/

void priorityQueueExample() {
    // Max-heap
    priority_queue<int> maxPQ;
    maxPQ.push(3);
    maxPQ.push(1);
    maxPQ.push(4);
    cout << maxPQ.top() << endl;  // 4

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(3);
    minPQ.push(1);
    minPQ.push(4);
    cout << minPQ.top() << endl;  // 1

    // Custom comparator (min-heap of pairs)
    auto cmp = [](pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second; // min-heap by second
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
}

// ============================================================
// 11. BITSET (Fixed-size bit array)
// ============================================================
/*
Syntax:
    bitset<8> b;              // 00000000
    bitset<8> b(42);          // 00101010
    bitset<8> b("101010");    // 00101010

    b.set()           // set all to 1
    b.set(i)          // set bit i to 1
    b.reset()         // set all to 0
    b.reset(i)        // set bit i to 0
    b.flip()          // flip all bits
    b.flip(i)         // flip bit i
    b.test(i)         // check if bit i is 1
    b.count()         // number of 1s
    b.size()          // total bits
    b.any()           // any bit set?
    b.none()          // no bits set?
    b.to_ulong()      // convert to unsigned long
    b.to_string()     // convert to string

    // Time Complexity: O(1) per operation (fixed size)

    // Use Cases:
    // - Subset generation (bitmask DP)
    // - Fast set operations (union, intersection)
    // - Sieve of Eratosthenes
    // - Tracking visited states
    // - Bit manipulation problems
*/

void bitsetExample() {
    bitset<10> b;
    b.set(3);    // bit 3 is 1
    b.set(7);    // bit 7 is 1
    cout << b.count() << endl;  // 2
    cout << b.test(3) << endl;  // 1 (true)
    cout << b.to_string() << endl;
}

// ============================================================
// 12. STRING (Enhanced string handling)
// ============================================================
/*
Syntax:
    string s = "hello";

    // Functions
    s.length() / s.size()   // length
    s.empty()               // check empty
    s.clear()               // clear
    s.append(" world")      // concatenate
    s += "!"                // concatenate
    s.substr(pos, len)      // substring from pos, length len
    s.find("lo")            // find substring, returns index or npos
    s.rfind("l")            // find from end
    s.erase(pos, len)       // erase len chars from pos
    s.insert(pos, "xy")     // insert at pos
    s.replace(pos, len, "abc") // replace len chars with "abc"
    s.compare("hello")      // compare
    s.c_str()               // C-style string

    // Sorting
    sort(s.begin(), s.end());

    // Reverse
    reverse(s.begin(), s.end());

    // Character checking
    isalpha(c)    // is letter?
    isdigit(c)    // is digit?
    isalnum(c)    // is letter or digit?
    tolower(c)    // convert to lowercase
    toupper(c)    // convert to uppercase

    // Conversion
    stoi(s)       // string to int
    to_string(n)  // int to string

    // Use Cases:
    // - Palindrome checking
    // - Anagram problems
    // - String matching
    // - Substring problems
    // - Tokenization
*/

void stringExample() {
    string s = "hello world";
    cout << s.substr(0, 5) << endl;  // "hello"
    cout << s.find("world") << endl; // 6

    // Split by space
    stringstream ss(s);
    string token;
    while (ss >> token)
        cout << token << endl;
}

// ============================================================
// 13. COMMON ALGORITHMS SUMMARY
// ============================================================
/*
Sorting:
    sort(v.begin(), v.end());                    // O(n log n)
    sort(v.begin(), v.end(), greater<int>());    // descending
    stable_sort(v.begin(), v.end());             // stable sort
    partial_sort(v.begin(), v.begin()+k, v.end()); // top k
    nth_element(v.begin(), v.begin()+k, v.end()); // kth element

Searching:
    binary_search(v.begin(), v.end(), x)  // O(log n) - bool
    lower_bound(v.begin(), v.end(), x)    // O(log n) - iterator to >= x
    upper_bound(v.begin(), v.end(), x)    // O(log n) - iterator to > x

Other:
    reverse(v.begin(), v.end())
    rotate(v.begin(), v.begin()+k, v.end())
    next_permutation(v.begin(), v.end())
    prev_permutation(v.begin(), v.end())
    accumulate(v.begin(), v.end(), 0)
    count(v.begin(), v.end(), x)
    find(v.begin(), v.end(), x)
    min_element(v.begin(), v.end())
    max_element(v.begin(), v.end())
    unique(v.begin(), v.end())  // remove consecutive duplicates
    __gcd(a, b)                 // GCD
    __builtin_popcount(x)       // count set bits
    __builtin_clz(x)            // count leading zeros
    __builtin_ctz(x)            // count trailing zeros
*/

// ============================================================
// 14. BIT MANIPULATION (Essential for Competitive Programming)
// ============================================================
/*
Basics:
    a & b          // AND
    a | b          // OR
    a ^ b          // XOR
    a << n         // Left shift (multiply by 2^n)
    a >> n         // Right shift (divide by 2^n)
    ~a             // NOT (bitwise complement)

    // Check if bit i is set
    (n >> i) & 1

    // Set bit i
    n | (1 << i)

    // Clear bit i
    n & ~(1 << i)

    // Toggle bit i
    n ^ (1 << i)

    // Check if n is power of 2
    n > 0 && (n & (n-1)) == 0

    // Count set bits
    __builtin_popcount(n)

    // Generate all subsets of n elements
    for (int mask = 0; mask < (1 << n); mask++) {
        // Process subset represented by mask
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                // element i is in subset
            }
        }
    }
*/

int main() {
    cout << "=== C++ STL Complete Guide ===" << endl;
    cout << "Read each section above for syntax and examples." << endl;
    cout << "See problem files for practice problems." << endl;
    return 0;
}
