// ============================================================
// TWO POINTERS - 25 Solutions (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ============================================================
// SECTION A: OPPOSITE DIRECTION TWO POINTERS
// ============================================================

// Problem 4.1 - Two Sum II (LeetCode #167)
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

// Problem 4.2 - 3Sum (LeetCode #15)
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
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

// Problem 4.3 - 3Sum Closest (LeetCode #16)
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; i++) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closest - target)) closest = sum;
            if (sum < target) left++;
            else if (sum > target) right--;
            else return target;
        }
    }
    return closest;
}

// Problem 4.4 - 4Sum (LeetCode #18)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i + 1; j < nums.size() - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue;
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++; right--;
                } else if (sum < target) left++;
                else right--;
            }
        }
    }
    return result;
}

// Problem 4.5 - Container With Most Water (LeetCode #11)
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;
    while (left < right) {
        int water = min(height[left], height[right]) * (right - left);
        maxWater = max(maxWater, water);
        if (height[left] < height[right]) left++;
        else right--;
    }
    return maxWater;
}

// Problem 4.6 - Trapping Rain Water (LeetCode #42)
int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) leftMax = height[left];
            else water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax) rightMax = height[right];
            else water += rightMax - height[right];
            right--;
        }
    }
    return water;
}

// Problem 4.7 - Valid Palindrome (LeetCode #125)
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

// Problem 4.8 - Palindrome Number (LeetCode #9)
bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return x == reversed || x == reversed / 10;
}

// ============================================================
// SECTION B: SLIDING WINDOW
// ============================================================

// Problem 4.9 - Longest Substring Without Repeating (LeetCode #3)
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

// Problem 4.10 - Minimum Window Substring (LeetCode #76)
string minWindow(string s, string t) {
    unordered_map<char, int> tCount, windowCount;
    for (char c : t) tCount[c]++;

    int left = 0, minLen = INT_MAX, minStart = 0;
    int formed = 0, required = tCount.size();

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        windowCount[c]++;
        if (tCount.count(c) && windowCount[c] == tCount[c]) formed++;

        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            char lc = s[left];
            windowCount[lc]--;
            if (tCount.count(lc) && windowCount[lc] < tCount[lc]) formed--;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

// Problem 4.11 - Longest Repeating Character Replacement (LeetCode #424)
int characterReplacement(string s, int k) {
    vector<int> count(26, 0);
    int left = 0, maxCount = 0, maxLen = 0;
    for (int right = 0; right < s.size(); right++) {
        count[s[right] - 'A']++;
        maxCount = max(maxCount, count[s[right] - 'A']);
        while (right - left + 1 - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// Problem 4.12 - Permutation in String (LeetCode #567)
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<int> count1(26, 0), count2(26, 0);
    for (int i = 0; i < s1.size(); i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }
    if (count1 == count2) return true;
    for (int i = s1.size(); i < s2.size(); i++) {
        count2[s2[i] - 'a']++;
        count2[s2[i - s1.size()] - 'a']--;
        if (count1 == count2) return true;
    }
    return false;
}

// Problem 4.13 - Minimum Size Subarray Sum (LeetCode #209)
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, sum = 0, minLen = INT_MAX;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

// Problem 4.14 - Max Consecutive Ones III (LeetCode #1004)
int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeros = 0, maxLen = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeros++;
        while (zeros > k) {
            if (nums[left] == 0) zeros--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// Problem 4.15 - Subarray Product Less Than K (LeetCode #713)
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int left = 0, product = 1, count = 0;
    for (int right = 0; right < nums.size(); right++) {
        product *= nums[right];
        while (product >= k) product /= nums[left++];
        count += right - left + 1;
    }
    return count;
}

// ============================================================
// SECTION C: FAST & SLOW POINTERS
// ============================================================

// Problem 4.16 - Linked List Cycle (LeetCode #141)
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Problem 4.17 - Linked List Cycle II (LeetCode #142)
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) { slow = slow->next; fast = fast->next; }
            return slow;
        }
    }
    return nullptr;
}

// Problem 4.18 - Happy Number (LeetCode #202)
int digitSquareSum(int n) {
    int sum = 0;
    while (n) { int d = n % 10; sum += d * d; n /= 10; }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = digitSquareSum(n);
    while (slow != fast) {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(digitSquareSum(fast));
    }
    return slow == 1;
}

// Problem 4.19 - Find Duplicate Number (LeetCode #287)
int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do { slow = nums[slow]; fast = nums[nums[fast]]; } while (slow != fast);
    slow = nums[0];
    while (slow != fast) { slow = nums[slow]; fast = nums[fast]; }
    return slow;
}

// Problem 4.20 - Middle of Linked List (LeetCode #876)
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    return slow;
}

// ============================================================
// SECTION D: SORTING BASED
// ============================================================

// Problem 4.21 - Sort Colors (LeetCode #75)
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}

// Problem 4.22 - Move Zeroes (LeetCode #283)
void moveZeroes(vector<int>& nums) {
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] != 0) swap(nums[left++], nums[right]);
    }
}

// Problem 4.23 - Remove Duplicates (LeetCode #26)
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int left = 0;
    for (int right = 1; right < nums.size(); right++)
        if (nums[right] != nums[left]) nums[++left] = nums[right];
    return left + 1;
}

// Problem 4.24 - Remove Element (LeetCode #27)
int removeElement(vector<int>& nums, int val) {
    int left = 0;
    for (int right = 0; right < nums.size(); right++)
        if (nums[right] != val) nums[left++] = nums[right];
    return left;
}

// Problem 4.25 - Merge Sorted Array (LeetCode #88)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
    while (j >= 0) nums1[k--] = nums2[j--];
}

// ============================================================
// MAIN - Testing
// ============================================================
int main() {
    cout << "=== Two Pointers Solutions ===" << endl;

    vector<int> nums = {2,7,11,15};
    auto ts = twoSum(nums, 9);
    cout << "Two Sum: [" << ts[0] << "," << ts[1] << "]" << endl;

    vector<int> nums2 = {-1,0,1,2,-1,-4};
    auto triplets = threeSum(nums2);
    cout << "3Sum count: " << triplets.size() << endl;

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Max Area: " << maxArea(height) << endl;

    vector<int> trapArr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trap Rain: " << trap(trapArr) << endl;

    cout << "Longest Substring: " << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "Min Window: " << minWindow("ADOBECODEBANC", "ABC") << endl;

    cout << "Sort Colors: ";
    vector<int> colors = {2,0,2,1,1,0};
    sortColors(colors);
    for (int c : colors) cout << c << " ";
    cout << endl;

    cout << "Happy Number: " << isHappy(19) << endl;

    return 0;
}
