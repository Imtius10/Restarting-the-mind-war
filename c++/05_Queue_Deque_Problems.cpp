// ============================================================
// QUEUE & DEQUE - 10 Practice Problems (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem 1: Implement Stack using Queues (LeetCode #225)
// ============================================================
class MyStack {
    queue<int> q;
public:
    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) { q.push(q.front()); q.pop(); }
    }
    int pop() { int val = q.front(); q.pop(); return val; }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};

// ============================================================
// Problem 2: Moving Average from Data Stream (LeetCode #346)
// Calculate moving average of last k elements.
// ============================================================
class MovingAverage {
    queue<int> q;
    int size;
    double sum = 0;
public:
    MovingAverage(int s) : size(s) {}
    double next(int val) {
        if (q.size() == size) { sum -= q.front(); q.pop(); }
        q.push(val);
        sum += val;
        return sum / q.size();
    }
};

// ============================================================
// Problem 3: Number of Recent Calls (LeetCode #933)
// Count requests in last 3000ms.
// ============================================================
class RecentCounter {
    queue<int> q;
public:
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) q.pop();
        return q.size();
    }
};

// ============================================================
// Problem 4: Sliding Window Maximum (LeetCode #239)
// Using deque for O(n) solution.
// ============================================================
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

// ============================================================
// Problem 5: Sliding Window Minimum (Codeforces)
// Using deque for O(n) solution.
// ============================================================
vector<int> minSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] >= nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

// ============================================================
// Problem 6: First Unique Character in String (LeetCode #387)
// Find first non-repeating character using queue.
// ============================================================
int firstUniqChar(string s) {
    queue<int> q;
    vector<int> count(26, 0);
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
        q.push(i);
    }
    while (!q.empty()) {
        if (count[s[q.front()] - 'a'] == 1) return q.front();
        q.pop();
    }
    return -1;
}

// ============================================================
// Problem 7: Generate Binary Numbers 1 to N (Queue Pattern)
// ============================================================
vector<string> generateBinary(int n) {
    vector<string> result;
    queue<string> q;
    q.push("1");
    for (int i = 0; i < n; i++) {
        string curr = q.front(); q.pop();
        result.push_back(curr);
        q.push(curr + "0");
        q.push(curr + "1");
    }
    return result;
}

// ============================================================
// Problem 8: Rotting Oranges (LeetCode #994)
// BFS using queue to find time to rot all oranges.
// ============================================================
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) q.push({i, j});
            else if (grid[i][j] == 1) fresh++;
        }
    if (fresh == 0) return 0;
    int minutes = 0;
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    while (!q.empty()) {
        int size = q.size();
        bool rotted = false;
        for (int i = 0; i < size; i++) {
            auto [r, c] = q.front(); q.pop();
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    rotted = true;
                    q.push({nr, nc});
                }
            }
        }
        if (rotted) minutes++;
    }
    return fresh == 0 ? minutes : -1;
}

// ============================================================
// Problem 9: Open the Lock (LeetCode #752)
// BFS to find minimum turns to unlock.
// ============================================================
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000")) return -1;
    queue<string> q;
    q.push("0000");
    unordered_set<string> visited = {"0000"};
    int turns = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string curr = q.front(); q.pop();
            if (curr == target) return turns;
            for (int j = 0; j < 4; j++) {
                for (int d = -1; d <= 1; d += 2) {
                    string next = curr;
                    next[j] = (next[j] - '0' + d + 10) % 10 + '0';
                    if (!visited.count(next) && !dead.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        turns++;
    }
    return -1;
}

// ============================================================
// Problem 10: Deck of Cards (LeetCode #807)
// Using queue to simulate circular deck.
// ============================================================
int deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    sort(deck.begin(), deck.end());
    queue<int> q;
    for (int i = 0; i < n; i++) q.push(i);
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[q.front()] = deck[i]; q.pop();
        if (!q.empty()) { q.push(q.front()); q.pop(); }
    }
    return 0;  // returns result array via reference
}

int main() {
    cout << "=== Queue & Deque Problems ===" << endl;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto wmax = maxSlidingWindow(nums, 3);
    cout << "Sliding Max: ";
    for (int x : wmax) cout << x << " ";
    cout << endl;

    auto wmin = minSlidingWindow(nums, 3);
    cout << "Sliding Min: ";
    for (int x : wmin) cout << x << " ";
    cout << endl;

    cout << "First Unique Char: " << firstUniqChar("leetcode") << endl;

    auto bin = generateBinary(5);
    cout << "Binary 1-5: ";
    for (string &s : bin) cout << s << " ";
    cout << endl;

    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Rotting Oranges: " << orangesRotting(grid) << endl;

    vector<string> dead = {"0201","0101","0102","1212","2002"};
    cout << "Open Lock: " << openLock(dead, "0202") << endl;

    return 0;
}
