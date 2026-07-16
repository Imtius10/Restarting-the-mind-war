// ============================================================
// PRIORITY QUEUE - 10 Practice Problems (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem 1: Kth Largest Element in Array (LeetCode #215)
// Use min-heap of size k.
// ============================================================
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int n : nums) {
        minHeap.push(n);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

// ============================================================
// Problem 2: Top K Frequent Elements (LeetCode #347)
// Use min-heap to keep top k frequent elements.
// ============================================================
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    for (auto& [num, count] : freq) {
        minHeap.push({count, num});
        if (minHeap.size() > k) minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) { result.push_back(minHeap.top().second); minHeap.pop(); }
    return result;
}

// ============================================================
// Problem 3: Merge K Sorted Lists (LeetCode #23)
// Use min-heap to merge k sorted linked lists.
// ============================================================
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

    for (ListNode* l : lists)
        if (l) pq.push(l);

    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (!pq.empty()) {
        tail->next = pq.top(); pq.pop();
        tail = tail->next;
        if (tail->next) pq.push(tail->next);
    }
    return dummy.next;
}

// ============================================================
// Problem 4: K Closest Points to Origin (LeetCode #973)
// Use max-heap to keep k closest points.
// ============================================================
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto dist = [](vector<int>& p) { return p[0]*p[0] + p[1]*p[1]; };
    priority_queue<pair<int,vector<int>>> maxHeap;

    for (auto& p : points) {
        maxHeap.push({dist(p), p});
        if (maxHeap.size() > k) maxHeap.pop();
    }

    vector<vector<int>> result;
    while (!maxHeap.empty()) { result.push_back(maxHeap.top().second); maxHeap.pop(); }
    return result;
}

// ============================================================
// Problem 5: Find Median from Data Stream (LeetCode #295)
// Use two heaps: max-heap for lower half, min-heap for upper half.
// ============================================================
class MedianFinder {
    priority_queue<int> maxHeap;  // lower half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // upper half
public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top()); maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) { maxHeap.push(minHeap.top()); minHeap.pop(); }
    }
    double findMedian() {
        return maxHeap.size() > minHeap.size() ?
            maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

// ============================================================
// Problem 6: Task Scheduler (LeetCode #621)
// Use max-heap and greedy approach.
// ============================================================
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char c : tasks) freq[c - 'A']++;

    priority_queue<int> maxHeap;
    for (int f : freq) if (f > 0) maxHeap.push(f);

    int time = 0;
    while (!maxHeap.empty()) {
        vector<int> temp;
        for (int i = 0; i <= n; i++) {
            if (!maxHeap.empty()) { temp.push_back(maxHeap.top() - 1); maxHeap.pop(); }
        }
        for (int f : temp) if (f > 0) maxHeap.push(f);
        time += maxHeap.empty() ? temp.size() : n + 1;
    }
    return time;
}

// ============================================================
// Problem 7: Kth Smallest Element in Sorted Matrix (LeetCode #378)
// Use min-heap with sorted property.
// ============================================================
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            minHeap.push(matrix[i][j]);
            if (minHeap.size() > k) minHeap.pop();
        }
    return minHeap.top();
}

// ============================================================
// Problem 8: Reorganize String (LeetCode #767)
// Use max-heap to rearrange characters.
// ============================================================
string reorganizeString(string s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    priority_queue<pair<int,char>> maxHeap;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0) maxHeap.push({freq[i], (char)('a' + i)});

    string result = "";
    pair<int,char> prev = {-1, '#'};
    while (!maxHeap.empty()) {
        auto [count, ch] = maxHeap.top(); maxHeap.pop();
        result += ch;
        if (prev.first > 0) maxHeap.push(prev);
        prev = {count - 1, ch};
    }
    return result.size() == s.size() ? result : "";
}

// ============================================================
// Problem 9: Meeting Rooms II (LeetCode #253)
// Use min-heap to track concurrent meetings.
// ============================================================
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (auto& interval : intervals) {
        if (!minHeap.empty() && minHeap.top() <= interval[0])
            minHeap.pop();
        minHeap.push(interval[1]);
    }
    return minHeap.size();
}

// ============================================================
// Problem 10: Super Ugly Number (LeetCode #313)
// Use min-heap with prime factors.
// ============================================================
int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> result(n);
    result[0] = 1;
    vector<int> indices(primes.size(), 0);
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (int p : primes) minHeap.push(p);

    for (int i = 1; i < n; i++) {
        result[i] = minHeap.top(); minHeap.pop();
        while (minHeap.top() == result[i]) minHeap.pop();
        for (int j = 0; j < primes.size(); j++) {
            if (result[indices[j]] * primes[j] == result[i]) {
                indices[j]++;
                minHeap.push((long long)result[indices[j]] * primes[j]);
            }
        }
    }
    return result[n - 1];
}

int main() {
    cout << "=== Priority Queue Problems ===" << endl;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << "Kth Largest (k=2): " << findKthLargest(nums, 2) << endl;

    vector<int> nums2 = {1,1,1,2,2,3};
    auto top = topKFrequent(nums2, 2);
    cout << "Top 2 Frequent: ";
    for (int x : top) cout << x << " ";
    cout << endl;

    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    auto closest = kClosest(points, 2);
    cout << "K Closest Points: ";
    for (auto& p : closest) cout << "[" << p[0] << "," << p[1] << "] ";
    cout << endl;

    vector<vector<int>> meetings = {{0,30},{5,10},{15,20}};
    cout << "Min Meeting Rooms: " << minMeetingRooms(meetings) << endl;

    vector<char> tasks = {'A','A','A','B','B','B'};
    cout << "Task Scheduler: " << leastInterval(tasks, 2) << endl;

    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    cout << "Kth Smallest (k=8): " << kthSmallest(matrix, 8) << endl;

    cout << "Reorganize String: " << reorganizeString("aab") << endl;

    return 0;
}
