// ============================================================
// VECTOR - 10 Practice Problems (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem 1: Two Sum (LeetCode #1)
// Given array and target, return indices of two numbers that add up to target.
// ============================================================
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];
        if (mp.count(comp)) return {mp[comp], i};
        mp[nums[i]] = i;
    }
    return {};
}

// ============================================================
// Problem 2: Best Time to Buy and Sell Stock (LeetCode #121)
// Find max profit from one buy and one sell.
// ============================================================
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int p : prices) {
        minPrice = min(minPrice, p);
        maxProfit = max(maxProfit, p - minPrice);
    }
    return maxProfit;
}

// ============================================================
// Problem 3: Contains Duplicate (LeetCode #217)
// Check if any value appears twice.
// ============================================================
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    return s.size() != nums.size();
}

// ============================================================
// Problem 4: Maximum Subarray (LeetCode #53)
// Find contiguous subarray with maximum sum (Kadane's Algorithm).
// ============================================================
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], curSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        curSum = max(nums[i], curSum + nums[i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

// ============================================================
// Problem 5: Merge Sorted Arrays (LeetCode #88)
// Merge nums2 into nums1 in-place.
// ============================================================
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
    while (j >= 0) nums1[k--] = nums2[j--];
}

// ============================================================
// Problem 6: Rotate Array (LeetCode #189)
// Rotate array to the right by k steps.
// ============================================================
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// ============================================================
// Problem 7: Single Number (LeetCode #136)
// Find element that appears once (others appear twice).
// ============================================================
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int n : nums) result ^= n;
    return result;
}

// ============================================================
// Problem 8: Product of Array Except Self (LeetCode #238)
// Return array where each element is product of all others.
// ============================================================
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    int left = 1, right = 1;
    for (int i = 0; i < n; i++) {
        result[i] *= left;
        left *= nums[i];
    }
    for (int i = n-1; i >= 0; i--) {
        result[i] *= right;
        right *= nums[i];
    }
    return result;
}

// ============================================================
// Problem 9: Maximum Product Subarray (LeetCode #152)
// Find contiguous subarray with maximum product.
// ============================================================
int maxProduct(vector<int>& nums) {
    int maxProd = nums[0], minProd = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) swap(maxProd, minProd);
        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);
        result = max(result, maxProd);
    }
    return result;
}

// ============================================================
// Problem 10: Sliding Window Maximum (LeetCode #239)
// Return max of each sliding window of size k.
// ============================================================
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}

int main() {
    cout << "=== Vector Problems ===" << endl;

    vector<int> nums1 = {2, 7, 11, 15};
    auto ans = twoSum(nums1, 9);
    cout << "Two Sum: [" << ans[0] << ", " << ans[1] << "]" << endl;

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl;

    vector<int> nums2 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max Subarray Sum: " << maxSubArray(nums2) << endl;

    vector<int> nums3 = {1, 2, 3, 0, 0, 0};
    vector<int> nums4 = {2, 5, 6};
    merge(nums3, 3, nums4, 3);
    cout << "Merged: ";
    for (int x : nums3) cout << x << " ";
    cout << endl;

    vector<int> nums5 = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums5, 3);
    cout << "Rotated: ";
    for (int x : nums5) cout << x << " ";
    cout << endl;

    vector<int> nums6 = {4, 1, 2, 1, 2};
    cout << "Single Number: " << singleNumber(nums6) << endl;

    return 0;
}
