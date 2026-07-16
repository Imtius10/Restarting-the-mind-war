// ============================================================
// PAIR - 10 Practice Problems (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem 1: Sort Pairs by First Element
// (Similar to LeetCode 1791 - Find Center of Star Graph)
// ============================================================
// Given pairs, sort them by first element, then by second.
void sortPairs() {
    vector<pair<int,int>> v = {{3,5}, {1,2}, {3,1}, {2,4}};
    sort(v.begin(), v.end());
    // Output: {1,2}, {2,4}, {3,1}, {3,5}
    for (auto &p : v)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;
}

// ============================================================
// Problem 2: Sort Pairs by Second Element (Custom Comparator)
// ============================================================
// Sort pairs by second element in descending order.
void sortBySecond() {
    vector<pair<int,int>> v = {{1,5}, {2,3}, {3,1}, {4,4}};
    sort(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;  // descending by second
    });
    // Output: {1,5}, {4,4}, {2,3}, {3,1}
    for (auto &p : v)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;
}

// ============================================================
// Problem 3: Merge Two Sorted Arrays of Pairs
// (Similar to LeetCode 88 - Merge Sorted Array)
// ============================================================
// Merge two sorted arrays of pairs into one sorted array.
vector<pair<int,int>> mergeSortedPairs(vector<pair<int,int>> &a, vector<pair<int,int>> &b) {
    vector<pair<int,int>> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    return result;
}

// ============================================================
// Problem 4: Find Pair with Given Sum
// (Similar to LeetCode 1 - Two Sum)
// ============================================================
// Find a pair that sums to target. Return indices.
pair<int,int> twoSum(vector<int> &nums, int target) {
    map<int,int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.count(complement))
            return {mp[complement], i};
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

// ============================================================
// Problem 5: Sort Pairs by Distance from Origin
// (Similar to LeetCode 973 - K Closest Points to Origin)
// ============================================================
// Sort points by distance from origin (0,0).
vector<pair<int,int>> kClosest(vector<pair<int,int>> &points, int k) {
    sort(points.begin(), points.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return (a.first*a.first + a.second*a.second) < (b.first*b.first + b.second*b.second);
    });
    return vector<pair<int,int>>(points.begin(), points.begin()+k);
}

// ============================================================
// Problem 6: Group Pairs by First Element
// ============================================================
// Group pairs by their first element.
void groupByFirst() {
    vector<pair<int,int>> v = {{1,2}, {1,3}, {2,1}, {2,4}, {3,1}};
    map<int, vector<int>> groups;
    for (auto &p : v)
        groups[p.first].push_back(p.second);

    for (auto &[key, values] : groups) {
        cout << key << ": ";
        for (int v : values) cout << v << " ";
        cout << endl;
    }
}

// ============================================================
// Problem 7: Find Maximum Second Element
// ============================================================
// Find the pair with maximum second element.
pair<int,int> maxSecond(vector<pair<int,int>> &v) {
    return *max_element(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return a.second < b.second;
    });
}

// ============================================================
// Problem 8: Count Pairs with Sum Greater Than K
// (Similar to Codeforces problems)
// ============================================================
// Count pairs where a[i] + a[j] > k.
int countPairsWithSum(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        if (nums[left] + nums[right] > k) {
            count += (right - left);
            right--;
        } else {
            left++;
        }
    }
    return count;
}

// ============================================================
// Problem 9: Pair as Map Key (Frequency Count)
// (Similar to LeetCode 1 - Two Sum pattern)
// ============================================================
// Count frequency of pairs.
void pairFrequency() {
    vector<pair<int,int>> v = {{1,2}, {3,4}, {1,2}, {5,6}, {3,4}, {1,2}};
    map<pair<int,int>, int> freq;
    for (auto &p : v)
        freq[p]++;

    for (auto &[p, count] : freq)
        cout << "(" << p.first << "," << p.second << "): " << count << endl;
    // (1,2): 3
    // (3,4): 2
    // (5,6): 1
}

// ============================================================
// Problem 10: Nested Pair Access
// ============================================================
// Work with nested pairs (e.g., triplet stored as pair<int, pair<int,int>>)
void nestedPair() {
    vector<pair<int, pair<int,int>>> v = {
        {3, {1, 2}},
        {1, {3, 4}},
        {2, {5, 6}}
    };

    // Sort by first element
    sort(v.begin(), v.end());

    // Access nested values
    for (auto &[id, coord] : v)
        cout << "ID=" << id << " (" << coord.first << "," << coord.second << ")" << endl;

    // Find element with specific nested value
    int target = 5;
    for (auto &p : v) {
        if (p.second.first == target) {
            cout << "Found: ID=" << p.first << endl;
            break;
        }
    }
}

int main() {
    cout << "=== Pair Problems ===" << endl;
    sortPairs();
    sortBySecond();
    groupByFirst();
    pairFrequency();
    nestedPair();

    vector<int> nums = {2, 7, 11, 15};
    auto [i, j] = twoSum(nums, 9);
    cout << "Two Sum indices: " << i << ", " << j << endl;

    cout << "Count pairs > 6: " << countPairsWithSum(nums, 6) << endl;
    return 0;
}
