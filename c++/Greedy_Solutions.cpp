// ============================================================
// GREEDY - 25 Solutions (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// SECTION A: EASY GREEDY
// ============================================================

// Problem 2.1 - Maximum Units on a Truck (LeetCode #1710)
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });
    int total = 0;
    for (auto& box : boxTypes) {
        int take = min(truckSize, box[0]);
        total += take * box[1];
        truckSize -= take;
        if (truckSize == 0) break;
    }
    return total;
}

// Problem 2.2 - Assign Cookies (LeetCode #455)
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    while (child < g.size() && cookie < s.size()) {
        if (s[cookie] >= g[child]) child++;
        cookie++;
    }
    return child;
}

// Problem 2.3 - Best Time to Buy and Sell Stock II (LeetCode #122)
int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
        if (prices[i] > prices[i-1])
            profit += prices[i] - prices[i-1];
    return profit;
}

// Problem 2.4 - Lemonade Change (LeetCode #860)
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
        if (bill == 5) five++;
        else if (bill == 10) { five--; ten++; }
        else if (ten > 0) { ten--; five--; }
        else five -= 3;
        if (five < 0) return false;
    }
    return true;
}

// Problem 2.5 - Array Partition (LeetCode #561)
int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2)
        sum += nums[i];
    return sum;
}

// ============================================================
// SECTION B: INTERVAL SCHEDULING
// ============================================================

// Problem 2.6 - Non-overlapping Intervals (LeetCode #435)
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    int count = 0, end = INT_MIN;
    for (auto& interval : intervals) {
        if (interval[0] >= end) end = interval[1];
        else count++;
    }
    return count;
}

// Problem 2.7 - Minimum Number of Arrows (LeetCode #452)
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    int arrows = 1, end = points[0][1];
    for (auto& point : points) {
        if (point[0] > end) { arrows++; end = point[1]; }
    }
    return arrows;
}

// Problem 2.8 - Merge Intervals (LeetCode #56)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (auto& interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0])
            merged.push_back(interval);
        else
            merged.back()[1] = max(merged.back()[1], interval[1]);
    }
    return merged;
}

// Problem 2.9 - Insert Interval (LeetCode #57)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0;
    while (i < intervals.size() && intervals[i][1] < newInterval[0])
        result.push_back(intervals[i++]);
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    while (i < intervals.size()) result.push_back(intervals[i++]);
    return result;
}

// Problem 2.10 - Meeting Rooms II (LeetCode #253)
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> starts, ends;
    for (auto& interval : intervals) {
        starts.push_back(interval[0]);
        ends.push_back(interval[1]);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    int rooms = 0, endPtr = 0;
    for (int start : starts) {
        if (start < ends[endPtr]) rooms++;
        else endPtr++;
    }
    return rooms;
}

// ============================================================
// SECTION D: COIN CHANGE & DISTRIBUTION
// ============================================================

// Problem 2.14 - Coin Change (Greedy for canonical systems)
int coinChangeGreedy(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            count++;
        }
    }
    return amount == 0 ? count : -1;
}

// Problem 2.16 - Distribute Candies (LeetCode #575)
int distributeCandies(vector<int>& candyType) {
    unordered_set<int> types(candyType.begin(), candyType.end());
    return min(types.size(), candyType.size() / 2);
}

// ============================================================
// SECTION E: STRING & MISCELLANEOUS GREEDY
// ============================================================

// Problem 2.18 - Largest Number (LeetCode #179)
string largestNumber(vector<int>& nums) {
    vector<string> strs;
    for (int n : nums) strs.push_back(to_string(n));
    sort(strs.begin(), strs.end(),
         [](string& a, string& b) { return a + b > b + a; });
    if (strs[0] == "0") return "0";
    string result = "";
    for (string& s : strs) result += s;
    return result;
}

// Problem 2.19 - Reorganize String (LeetCode #767)
string reorganizeString(string s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    priority_queue<pair<int,char>> pq;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0) pq.push({freq[i], (char)('a' + i)});
    string result = "";
    pair<int,char> prev = {-1, '#'};
    while (!pq.empty()) {
        auto [count, ch] = pq.top(); pq.pop();
        result += ch;
        if (prev.first > 0) pq.push(prev);
        prev = {count - 1, ch};
    }
    return result.size() == s.size() ? result : "";
}

// Problem 2.20 - Task Scheduler (LeetCode #621)
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char c : tasks) freq[c - 'A']++;
    int maxFreq = *max_element(freq.begin(), freq.end());
    int maxCount = count(freq.begin(), freq.end(), maxFreq);
    return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxCount);
}

// Problem 2.21 - Candy (LeetCode #135)
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 1; i < n; i++)
        if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
    for (int i = n - 2; i >= 0; i--)
        if (ratings[i] > ratings[i+1])
            candies[i] = max(candies[i], candies[i+1] + 1);
    return accumulate(candies.begin(), candies.end(), 0);
}

// Problem 2.22 - Jump Game (LeetCode #55)
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}

// Problem 2.23 - Jump Game II (LeetCode #45)
int jump(vector<int>& nums) {
    int jumps = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        curFarthest = max(curFarthest, i + nums[i]);
        if (i == curEnd) { jumps++; curEnd = curFarthest; }
    }
    return jumps;
}

// Problem 2.24 - Gas Station (LeetCode #134)
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalTank = 0, currTank = 0, start = 0;
    for (int i = 0; i < gas.size(); i++) {
        totalTank += gas[i] - cost[i];
        currTank += gas[i] - cost[i];
        if (currTank < 0) { start = i + 1; currTank = 0; }
    }
    return totalTank >= 0 ? start : -1;
}

// Problem 2.25 - Hand of Straights (LeetCode #846)
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;
    map<int,int> freq;
    for (int card : hand) freq[card]++;
    while (!freq.empty()) {
        int start = freq.begin()->first;
        for (int i = 0; i < groupSize; i++) {
            if (freq[start + i] == 0) return false;
            if (--freq[start + i] == 0) freq.erase(start + i);
        }
    }
    return true;
}

// ============================================================
// MAIN - Testing
// ============================================================
int main() {
    cout << "=== Greedy Solutions ===" << endl;

    vector<vector<int>> boxes = {{1,3},{2,2},{3,1}};
    cout << "Max Units: " << maximumUnits(boxes, 4) << endl;

    vector<int> g = {1,2,3}, s = {1,1};
    cout << "Content Children: " << findContentChildren(g, s) << endl;

    vector<int> prices = {7,1,5,3,6,4};
    cout << "Max Profit: " << maxProfit(prices) << endl;

    vector<int> bills = {5,5,5,10,20};
    cout << "Lemonade Change: " << lemonadeChange(bills) << endl;

    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Erase Overlap: " << eraseOverlapIntervals(intervals) << endl;

    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    cout << "Gas Station: " << canCompleteCircuit(gas, cost) << endl;

    vector<int> jumpArr = {2,3,1,1,4};
    cout << "Jump Game: " << canJump(jumpArr) << endl;
    cout << "Jump Game II: " << jump(jumpArr) << endl;
    vector<int> numArr = {3,30,34,5,9};
    cout << "Largest Number: " << largestNumber(numArr) << endl;

    return 0;
}
