// ============================================================
// SET & MULTISET - 10 Practice Problems (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem 1: Contains Duplicate (LeetCode #217)
// Use set to check for duplicates.
// ============================================================
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    return s.size() != nums.size();
}

// ============================================================
// Problem 2: Intersection of Two Arrays (LeetCode #349)
// Return unique common elements.
// ============================================================
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s1(nums1.begin(), nums1.end());
    vector<int> result;
    for (int n : nums2)
        if (s1.count(n)) { result.push_back(n); s1.erase(n); }
    return result;
}

// ============================================================
// Problem 3: Intersection of Two Arrays II (LeetCode #350)
// Return common elements with frequency.
// ============================================================
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int,int> freq;
    for (int n : nums1) freq[n]++;
    vector<int> result;
    for (int n : nums2)
        if (freq[n] > 0) { result.push_back(n); freq[n]--; }
    return result;
}

// ============================================================
// Problem 4: Third Maximum Number (LeetCode #414)
// Find third distinct maximum. Use set.
// ============================================================
int thirdMax(vector<int>& nums) {
    set<int> s;
    for (int n : nums) {
        s.insert(n);
        if (s.size() > 3) s.erase(s.begin());
    }
    return s.size() < 3 ? *s.rbegin() : *s.begin();
}

// ============================================================
// Problem 5: Find Duplicate Number (LeetCode #287)
// Use set to detect cycle.
// ============================================================
int findDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (int n : nums) {
        if (s.count(n)) return n;
        s.insert(n);
    }
    return -1;
}

// ============================================================
// Problem 6: Kth Largest Element in Stream (LeetCode #703)
// Use multiset to maintain sorted order.
// ============================================================
class KthLargest {
    multiset<int> s;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int n : nums) { s.insert(n); if (s.size() > k) s.erase(s.begin()); }
    }
    int add(int val) {
        s.insert(val);
        if (s.size() > k) s.erase(s.begin());
        return *s.begin();
    }
};

// ============================================================
// Problem 7: Subarray with K Different Integers (LeetCode #992)
// Use set with sliding window.
// ============================================================
int subarraysWithKDistinct(vector<int>& nums, int k) {
    auto atMost = [&](int k) {
        unordered_map<int,int> freq;
        int left = 0, result = 0;
        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            result += right - left + 1;
        }
        return result;
    };
    return atMost(k) - atMost(k-1);
}

// ============================================================
// Problem 8: Longest Consecutive Sequence (LeetCode #128)
// Use set for O(n) solution.
// ============================================================
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    for (int n : s) {
        if (!s.count(n - 1)) {
            int current = n, streak = 1;
            while (s.count(current + 1)) { current++; streak++; }
            longest = max(longest, streak);
        }
    }
    return longest;
}

// ============================================================
// Problem 9: Find Median from Data Stream (LeetCode #295)
// Use two sets (multiset) to maintain median.
// ============================================================
class MedianFinder {
    multiset<int> lo, hi;
public:
    void addNum(int num) {
        lo.insert(num);
        hi.insert(*lo.rbegin());
        lo.erase(prev(lo.end()));
        if (lo.size() < hi.size()) { lo.insert(*hi.begin()); hi.erase(hi.begin()); }
    }
    double findMedian() {
        return lo.size() > hi.size() ? *lo.rbegin() : (*lo.rbegin() + *hi.begin()) / 2.0;
    }
};

// ============================================================
// Problem 10: Minimum Index of Valid Split (LeetCode #3224)
// Use multiset to find dominator.
// ============================================================
int minIndex(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;
    int dominator = -1;
    for (auto &[val, cnt] : freq)
        if (cnt > n / 2) dominator = val;
    if (dominator == -1) return -1;

    int leftCount = 0, rightCount = freq[dominator];
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == dominator) { leftCount++; rightCount--; }
        if (leftCount > (i + 1) / 2 && rightCount > (n - i - 1) / 2)
            return i;
    }
    return -1;
}

int main() {
    cout << "=== Set & Multiset Problems ===" << endl;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    cout << "Contains Duplicate: " << containsDuplicate(nums1) << endl;

    auto inter = intersection(nums1, nums2);
    cout << "Intersection: ";
    for (int x : inter) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {4, 1, 2, 1, 2};
    cout << "Third Max: " << thirdMax(nums3) << endl;

    vector<int> nums4 = {1, 3, 4, 2, 2};
    cout << "Find Duplicate: " << findDuplicate(nums4) << endl;

    vector<int> nums5 = {1, 2, 3, 1};
    cout << "Longest Consecutive: " << longestConsecutive(nums5) << endl;

    return 0;
}
