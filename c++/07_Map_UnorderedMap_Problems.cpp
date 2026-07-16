// ============================================================
// MAP & UNORDERED_MAP - 10 Practice Problems (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem 1: Two Sum (LeetCode #1)
// Classic map problem: find pair that sums to target.
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
// Problem 2: Group Anagrams (LeetCode #49)
// Group strings that are anagrams using map.
// ============================================================
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& s : strs) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        mp[sorted].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [key, group] : mp)
        result.push_back(group);
    return result;
}

// ============================================================
// Problem 3: Top K Frequent Elements (LeetCode #347)
// Find k most frequent elements using map.
// ============================================================
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;

    vector<pair<int,int>> vec(freq.begin(), freq.end());
    sort(vec.begin(), vec.end(), [](auto& a, auto& b) { return a.second > b.second; });

    vector<int> result;
    for (int i = 0; i < k; i++) result.push_back(vec[i].first);
    return result;
}

// ============================================================
// Problem 4: Longest Substring Without Repeating Characters (LeetCode #3)
// Use map to track last index of each character.
// ============================================================
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> lastSeen;
    int maxLen = 0, left = 0;
    for (int right = 0; right < s.size(); right++) {
        if (lastSeen.count(s[right]) && lastSeen[s[right]] >= left)
            left = lastSeen[s[right]] + 1;
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// ============================================================
// Problem 5: Valid Anagram (LeetCode #242)
// Check if two strings are anagrams using map.
// ============================================================
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char,int> freq;
    for (char c : s) freq[c]++;
    for (char c : t) {
        freq[c]--;
        if (freq[c] < 0) return false;
    }
    return true;
}

// ============================================================
// Problem 6: Subarray Sum Equals K (LeetCode #560)
// Use prefix sum + map.
// ============================================================
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> prefixSum;
    prefixSum[0] = 1;
    int sum = 0, count = 0;
    for (int n : nums) {
        sum += n;
        if (prefixSum.count(sum - k))
            count += prefixSum[sum - k];
        prefixSum[sum]++;
    }
    return count;
}

// ============================================================
// Problem 7: Roman to Integer (LeetCode #13)
// Use map for symbol to value mapping.
// ============================================================
int romanToInt(string s) {
    unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},
                                   {'C',100},{'D',500},{'M',1000}};
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && mp[s[i]] < mp[s[i+1]])
            result -= mp[s[i]];
        else result += mp[s[i]];
    }
    return result;
}

// ============================================================
// Problem 8: Isomorphic Strings (LeetCode #205)
// Check if two strings have same character mapping pattern.
// ============================================================
bool isIsomorphic(string s, string t) {
    unordered_map<char,char> sToT, tToS;
    for (int i = 0; i < s.size(); i++) {
        if (sToT.count(s[i]) && sToT[s[i]] != t[i]) return false;
        if (tToS.count(t[i]) && tToS[t[i]] != s[i]) return false;
        sToT[s[i]] = t[i];
        tToS[t[i]] = s[i];
    }
    return true;
}

// ============================================================
// Problem 9: Word Frequency (LeetCode #109)
// Count word frequency using map.
// ============================================================
vector<pair<string,int>> wordFrequency(vector<string>& words) {
    unordered_map<string,int> freq;
    for (string& w : words) freq[w]++;

    vector<pair<string,int>> vec(freq.begin(), freq.end());
    sort(vec.begin(), vec.end(), [](auto& a, auto& b) { return a.second > b.second; });
    return vec;
}

// ============================================================
// Problem 10: First Unique Character in String (LeetCode #387)
// Use map to count, then find first with count 1.
// ============================================================
int firstUniqChar(string s) {
    unordered_map<char,int> freq;
    for (char c : s) freq[c]++;
    for (int i = 0; i < s.size(); i++)
        if (freq[s[i]] == 1) return i;
    return -1;
}

int main() {
    cout << "=== Map & Unordered_Map Problems ===" << endl;

    vector<int> nums = {2, 7, 11, 15};
    auto ans = twoSum(nums, 9);
    cout << "Two Sum: [" << ans[0] << ", " << ans[1] << "]" << endl;

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto groups = groupAnagrams(strs);
    cout << "Group Anagrams: " << groups.size() << " groups" << endl;

    vector<int> nums2 = {1,1,1,2,2,3};
    auto top = topKFrequent(nums2, 2);
    cout << "Top 2 Frequent: ";
    for (int x : top) cout << x << " ";
    cout << endl;

    cout << "Longest Substring: " << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "Is Anagram: " << isAnagram("anagram", "nagaram") << endl;

    vector<int> nums3 = {1,1,1};
    cout << "Subarray Sum K=2: " << subarraySum(nums3, 2) << endl;

    cout << "Roman to Int: " << romanToInt("MCMXCIV") << endl;
    cout << "Isomorphic: " << isIsomorphic("egg", "add") << endl;
    cout << "First Unique: " << firstUniqChar("leetcode") << endl;

    return 0;
}
