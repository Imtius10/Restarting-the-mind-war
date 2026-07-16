// ============================================================
// BINARY SEARCH - 25 Solutions (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// SECTION A: BASIC BINARY SEARCH
// ============================================================

// Problem 3.1 - Binary Search (LeetCode #704)
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// Problem 3.2 - First and Last Position (LeetCode #34)
int lowerBound(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int upperBound(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int first = lowerBound(nums, target);
    if (first == nums.size() || nums[first] != target) return {-1, -1};
    return {first, upperBound(nums, target) - 1};
}

// Problem 3.3 - Search Insert Position (LeetCode #35)
int searchInsert(vector<int>& nums, int target) {
    return lowerBound(nums, target);
}

// Problem 3.4 - Missing Number (LeetCode #268)
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int result = n;
    for (int i = 0; i < n; i++) result ^= i ^ nums[i];
    return result;
}

// ============================================================
// SECTION B: BINARY SEARCH ON ANSWER
// ============================================================

// Problem 3.6 - Square Root (LeetCode #69)
int mySqrt(int x) {
    if (x < 2) return x;
    int lo = 1, hi = x / 2;
    while (lo <= hi) {
        long mid = lo + (hi - lo) / 2;
        if (mid * mid == x) return mid;
        else if (mid * mid < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return hi;
}

// Problem 3.7 - Capacity to Ship Packages (LeetCode #1011)
int shipWithinDays(vector<int>& weights, int days) {
    int lo = *max_element(weights.begin(), weights.end());
    int hi = accumulate(weights.begin(), weights.end(), 0);

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int d = 1, curr = 0;
        for (int w : weights) {
            if (curr + w > mid) { d++; curr = 0; }
            curr += w;
        }
        if (d <= days) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// Problem 3.8 - Split Array Largest Sum (LeetCode #410)
int splitArray(vector<int>& nums, int m) {
    long lo = *max_element(nums.begin(), nums.end());
    long hi = accumulate(nums.begin(), nums.end(), 0L);

    while (lo < hi) {
        long mid = lo + (hi - lo) / 2;
        int pieces = 1, curr = 0;
        for (int n : nums) {
            if (curr + n > mid) { pieces++; curr = 0; }
            curr += n;
        }
        if (pieces <= m) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// Problem 3.9 - Magnetic Force Between Balls (LeetCode #1552)
int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int lo = 1, hi = position.back() - position.front();

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        int balls = 1, last = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= mid) { balls++; last = position[i]; }
        }
        if (balls >= m) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

// Problem 3.10 - Koko Eating Bananas (LeetCode #875)
int minEatingSpeed(vector<int>& piles, int h) {
    int lo = 1, hi = *max_element(piles.begin(), piles.end());

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        long hours = 0;
        for (int p : piles) hours += (p + mid - 1) / mid;
        if (hours <= h) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// ============================================================
// SECTION C: ROTATED SORTED ARRAY
// ============================================================

// Problem 3.11 - Search in Rotated Sorted Array (LeetCode #33)
int searchRotated(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[lo] <= nums[mid]) {
            if (target >= nums[lo] && target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {
            if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

// Problem 3.12 - Find Minimum in Rotated Sorted Array (LeetCode #153)
int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) lo = mid + 1;
        else hi = mid;
    }
    return nums[lo];
}

// Problem 3.14 - Find Peak Element (LeetCode #162)
int findPeakElement(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < nums[mid + 1]) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// Problem 3.15 - Single Element in Sorted Array (LeetCode #540)
int singleNonDuplicate(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid % 2 == 1) mid--;
        if (nums[mid] == nums[mid + 1]) lo = mid + 2;
        else hi = mid;
    }
    return nums[lo];
}

// ============================================================
// SECTION D: 2D MATRIX
// ============================================================

// Problem 3.16 - Search a 2D Matrix (LeetCode #74)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int lo = 0, hi = m * n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int val = matrix[mid / n][mid % n];
        if (val == target) return true;
        else if (val < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

// Problem 3.17 - Search a 2D Matrix II (LeetCode #240)
bool searchMatrixII(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int r = 0, c = n - 1;
    while (r < m && c >= 0) {
        if (matrix[r][c] == target) return true;
        else if (matrix[r][c] > target) c--;
        else r++;
    }
    return false;
}

// Problem 3.18 - Kth Smallest in Sorted Matrix (LeetCode #378)
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int lo = matrix[0][0], hi = matrix[n-1][n-1];

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int count = 0, j = n - 1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && matrix[i][j] > mid) j--;
            count += j + 1;
        }
        if (count < k) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// ============================================================
// SECTION E: PREFIX SUM & FREQUENCY
// ============================================================

// Problem 3.20 - Find K Closest Elements (LeetCode #658)
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int lo = 0, hi = arr.size() - k;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (x - arr[mid] > arr[mid + k] - x) lo = mid + 1;
        else hi = mid;
    }
    return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
}

// Problem 3.22 - Find the Duplicate Number (LeetCode #287)
int findDuplicate(vector<int>& nums) {
    int lo = 1, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int count = 0;
        for (int n : nums) if (n <= mid) count++;
        if (count <= mid) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// Problem 3.24 - Median of Two Sorted Arrays (LeetCode #4)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
    int m = nums1.size(), n = nums2.size();
    int lo = 0, hi = m;
    while (lo <= hi) {
        int i = lo + (hi - lo) / 2;
        int j = (m + n + 1) / 2 - i;
        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i-1];
        int minRight1 = (i == m) ? INT_MAX : nums1[i];
        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j-1];
        int minRight2 = (j == n) ? INT_MAX : nums2[j];
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 1) return max(maxLeft1, maxLeft2);
            else return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
        } else if (maxLeft1 > minRight2) hi = i - 1;
        else lo = i + 1;
    }
    return 0;
}

// Problem 3.25 - Aggressive Cows (SPOJ/CF)
bool canPlace(vector<int>& stalls, int dist, int cows) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) { count++; last = stalls[i]; }
    }
    return count >= cows;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int lo = 1, hi = stalls.back() - stalls.front();
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (canPlace(stalls, mid, cows)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

// ============================================================
// MAIN - Testing
// ============================================================
int main() {
    cout << "=== Binary Search Solutions ===" << endl;

    vector<int> nums = {-1,0,3,5,9,12};
    cout << "Search 9: " << search(nums, 9) << endl;

    vector<int> nums2 = {5,7,7,8,8,10};
    auto range = searchRange(nums2, 8);
    cout << "Range [3,4]: [" << range[0] << "," << range[1] << "]" << endl;

    cout << "Sqrt(8) = " << mySqrt(8) << endl;

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout << "Ship Capacity: " << shipWithinDays(weights, 5) << endl;

    vector<int> piles = {3,6,7,11};
    cout << "Koko Speed: " << minEatingSpeed(piles, 8) << endl;

    vector<int> rotated = {4,5,6,7,0,1,2};
    cout << "Search Rotated 0: " << searchRotated(rotated, 0) << endl;
    cout << "Find Min: " << findMin(rotated) << endl;

    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << "Search Matrix 3: " << searchMatrix(matrix, 3) << endl;

    vector<int> stalls = {1,2,8,4,9};
    cout << "Aggressive Cows: " << aggressiveCows(stalls, 3) << endl;

    return 0;
}
