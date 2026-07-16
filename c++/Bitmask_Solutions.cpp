// ============================================================
// BITMASKING - 25 Solutions (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// SECTION A: BASIC BIT OPERATIONS
// ============================================================

// Problem 6.1 - Number of 1 Bits (LeetCode #191)
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) { n &= (n - 1); count++; }
    return count;
}

// Problem 6.2 - Counting Bits (LeetCode #338)
vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        dp[i] = dp[i >> 1] + (i & 1);
    return dp;
}

// Problem 6.3 - Power of Two (LeetCode #231)
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Problem 6.4 - Power of Three (LeetCode #326)
bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}

// Problem 6.5 - Reverse Bits (LeetCode #190)
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

// ============================================================
// SECTION B: SINGLE NUMBER & MISSING
// ============================================================

// Problem 6.6 - Single Number (LeetCode #136)
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int n : nums) result ^= n;
    return result;
}

// Problem 6.7 - Single Number II (LeetCode #137)
int singleNumberII(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int n : nums) {
        ones = (ones ^ n) & ~twos;
        twos = (twos ^ n) & ~ones;
    }
    return ones;
}

// Problem 6.8 - Single Number III (LeetCode #260)
vector<int> singleNumberIII(vector<int>& nums) {
    int xorAll = 0;
    for (int n : nums) xorAll ^= n;

    int rightmost = xorAll & (-xorAll);
    int a = 0, b = 0;
    for (int n : nums) {
        if (n & rightmost) a ^= n;
        else b ^= n;
    }
    return {a, b};
}

// Problem 6.9 - Missing Number (LeetCode #268)
int missingNumber(vector<int>& nums) {
    int result = nums.size();
    for (int i = 0; i < nums.size(); i++)
        result ^= i ^ nums[i];
    return result;
}

// Problem 6.10 - Find the Difference (LeetCode #389)
char findTheDifference(string s, string t) {
    char result = 0;
    for (char c : s) result ^= c;
    for (char c : t) result ^= c;
    return result;
}

// ============================================================
// SECTION C: SUBSET GENERATION
// ============================================================

// Problem 6.11 - Subsets (LeetCode #78)
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) subset.push_back(nums[i]);
        result.push_back(subset);
    }
    return result;
}

// Problem 6.12 - Subsets II (LeetCode #90)
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        bool skip = false;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                if (i > 0 && nums[i] == nums[i-1] && !(mask & (1 << (i-1)))) {
                    skip = true; break;
                }
                subset.push_back(nums[i]);
            }
        }
        if (!skip) result.push_back(subset);
    }
    return result;
}

// Problem 6.14 - Count Subsets with Sum K
int countSubsetsWithSum(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) sum += nums[i];
        if (sum == k) count++;
    }
    return count;
}

// Problem 6.15 - Subset Sum Problem
bool subsetSum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) sum += nums[i];
        if (sum == target) return true;
    }
    return false;
}

// ============================================================
// SECTION D: BITMASK DP
// ============================================================

// Problem 6.16 - Traveling Salesman Problem (TSP)
int tsp(vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int newMask = mask | (1 << v);
                dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }

    int result = INT_MAX;
    for (int u = 0; u < n; u++)
        result = min(result, dp[(1 << n) - 1][u] + dist[u][0]);
    return result;
}

// Problem 6.17 - Assignment Problem
int assignmentProblem(vector<vector<int>>& cost) {
    int n = cost.size();
    vector<int> dp(1 << n, INT_MAX / 2);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        int worker = __builtin_popcount(mask);
        for (int job = 0; job < n; job++) {
            if (!(mask & (1 << job))) {
                int newMask = mask | (1 << job);
                dp[newMask] = min(dp[newMask], dp[mask] + cost[worker][job]);
            }
        }
    }
    return dp[(1 << n) - 1];
}

// Problem 6.18 - Minimum XOR Sum (LeetCode #1879)
int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        int i = __builtin_popcount(mask);
        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                int newMask = mask | (1 << j);
                dp[newMask] = min(dp[newMask], dp[mask] + (nums1[i] ^ nums2[j]));
            }
        }
    }
    return dp[(1 << n) - 1];
}

// Problem 6.20 - Shortest Path Visiting All Nodes (LeetCode #847)
int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    int allMask = (1 << n) - 1;
    queue<tuple<int,int,int>> q; // node, mask, distance
    vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

    for (int i = 0; i < n; i++) {
        q.push({i, 1 << i, 0});
        visited[i][1 << i] = true;
    }

    while (!q.empty()) {
        auto [node, mask, dist] = q.front(); q.pop();
        if (mask == allMask) return dist;
        for (int neighbor : graph[node]) {
            int newMask = mask | (1 << neighbor);
            if (!visited[neighbor][newMask]) {
                visited[neighbor][newMask] = true;
                q.push({neighbor, newMask, dist + 1});
            }
        }
    }
    return -1;
}

// ============================================================
// SECTION E: BIT TRICKS
// ============================================================

// Problem 6.21 - Bitwise AND of Range (LeetCode #201)
int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left != right) { left >>= 1; right >>= 1; shift++; }
    return left << shift;
}

// Problem 6.22 - XOR Queries (LeetCode #1310)
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++)
        prefix[i + 1] = prefix[i] ^ arr[i];

    vector<int> result;
    for (auto& q : queries)
        result.push_back(prefix[q[1] + 1] ^ prefix[q[0]]);
    return result;
}

// Problem 6.24 - Minimum Flips (LeetCode #1318)
int minFlips(int a, int b, int c) {
    int flips = 0;
    for (int i = 0; i < 32; i++) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        int bitC = (c >> i) & 1;
        if ((bitA | bitB) != bitC) {
            if (bitA == 0 && bitB == 0) flips++;
            else flips += (bitA != bitC) + (bitB != bitC);
        }
    }
    return flips;
}

// Problem 6.25 - Maximum XOR of Two Numbers (LeetCode #421)
struct TrieNode {
    TrieNode* children[2] = {};
};

void insert(TrieNode* root, int num) {
    TrieNode* node = root;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node->children[bit]) node->children[bit] = new TrieNode();
        node = node->children[bit];
    }
}

int findMaxXOR(TrieNode* root, int num) {
    TrieNode* node = root;
    int result = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int desired = 1 - bit;
        if (node->children[desired]) {
            result |= (1 << i);
            node = node->children[desired];
        } else {
            node = node->children[bit];
        }
    }
    return result;
}

int findMaximumXOR(vector<int>& nums) {
    TrieNode* root = new TrieNode();
    for (int n : nums) insert(root, n);
    int maxXor = 0;
    for (int n : nums) maxXor = max(maxXor, findMaxXOR(root, n));
    return maxXor;
}

// ============================================================
// MAIN - Testing
// ============================================================
int main() {
    cout << "=== Bitmask Solutions ===" << endl;

    cout << "Hamming Weight(11) = " << hammingWeight(11) << endl;

    auto bits = countBits(5);
    cout << "Count Bits: ";
    for (int b : bits) cout << b << " ";
    cout << endl;

    cout << "Power of Two(16) = " << isPowerOfTwo(16) << endl;
    cout << "Power of Three(27) = " << isPowerOfThree(27) << endl;

    vector<int> nums = {4,1,2,1,2};
    cout << "Single Number = " << singleNumber(nums) << endl;

    vector<int> nums2 = {2,2,3,2};
    cout << "Single Number II = " << singleNumberII(nums2) << endl;

    vector<int> nums3 = {1,2,1,3,2,5};
    auto single3 = singleNumberIII(nums3);
    cout << "Single Number III = " << single3[0] << " " << single3[1] << endl;

    vector<int> missArr = {3,0,1};
    cout << "Missing Number = " << missingNumber(missArr) << endl;

    vector<int> nums4 = {1,2,3};
    auto subs = subsets(nums4);
    cout << "Subsets count: " << subs.size() << endl;

    vector<vector<int>> dist = {{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    cout << "TSP = " << tsp(dist) << endl;

    vector<vector<int>> cost = {{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
    cout << "Assignment = " << assignmentProblem(cost) << endl;

    vector<int> xorArr = {3,10,5,25,2,8};
    cout << "Max XOR = " << findMaximumXOR(xorArr) << endl;

    return 0;
}
