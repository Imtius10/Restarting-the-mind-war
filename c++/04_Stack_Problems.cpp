// ============================================================
// STACK - 10 Practice Problems (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Problem 1: Valid Parentheses (LeetCode #20)
// Check if string has valid matching brackets.
// ============================================================
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if (st.empty()) return false;
            char t = st.top();
            if ((c == ')' && t == '(') || (c == '}' && t == '{') || (c == ']' && t == '['))
                st.pop();
            else return false;
        }
    }
    return st.empty();
}

// ============================================================
// Problem 2: Min Stack (LeetCode #155)
// Stack that supports push, pop, top, and getMin in O(1).
// ============================================================
class MinStack {
    stack<int> s;
    stack<int> minS;
public:
    void push(int val) {
        s.push(val);
        if (minS.empty() || val <= minS.top()) minS.push(val);
    }
    void pop() {
        if (s.top() == minS.top()) minS.pop();
        s.pop();
    }
    int top() { return s.top(); }
    int getMin() { return minS.top(); }
};

// ============================================================
// Problem 3: Reverse a String Using Stack
// ============================================================
string reverseString(string s) {
    stack<char> st;
    for (char c : s) st.push(c);
    string result = "";
    while (!st.empty()) { result += st.top(); st.pop(); }
    return result;
}

// ============================================================
// Problem 4: Next Greater Element (LeetCode #496 / Codeforces)
// For each element, find the next greater element to its right.
// ============================================================
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i])
            st.pop();
        if (!st.empty()) result[i] = st.top();
        st.push(nums[i]);
    }
    return result;
}

// ============================================================
// Problem 5: Daily Temperatures (LeetCode #739)
// For each day, wait how many days for warmer temperature.
// ============================================================
vector<int> dailyTemperatures(vector<int>& temps) {
    int n = temps.size();
    vector<int> result(n, 0);
    stack<int> st;  // store indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temps[st.top()] < temps[i]) {
            result[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return result;
}

// ============================================================
// Problem 6: Largest Rectangle in Histogram (LeetCode #84)
// Find area of largest rectangle in histogram.
// ============================================================
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

// ============================================================
// Problem 7: Implement Queue using Stacks (LeetCode #232)
// ============================================================
class MyQueue {
    stack<int> s1, s2;
public:
    void push(int x) { s1.push(x); }
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) { s2.push(s1.top()); s1.pop(); }
        }
        int val = s2.top(); s2.pop(); return val;
    }
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) { s2.push(s1.top()); s1.pop(); }
        }
        return s2.top();
    }
    bool empty() { return s1.empty() && s2.empty(); }
};

// ============================================================
// Problem 8: Evaluate Reverse Polish Notation (LeetCode #150)
// Evaluate arithmetic expression in postfix notation.
// ============================================================
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (string& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else st.push(a / b);
        } else st.push(stoi(t));
    }
    return st.top();
}

// ============================================================
// Problem 9: Simplify Path (LeetCode #71)
// Simplify Unix-style file path.
// ============================================================
string simplifyPath(string path) {
    stack<string> st;
    string dir = "";
    for (int i = 0; i <= path.size(); i++) {
        if (i == path.size() || path[i] == '/') {
            if (dir == "..") { if (!st.empty()) st.pop(); }
            else if (dir != "" && dir != ".") st.push(dir);
            dir = "";
        } else dir += path[i];
    }
    if (st.empty()) return "/";
    string result = "";
    while (!st.empty()) { result = "/" + st.top() + result; st.pop(); }
    return result;
}

// ============================================================
// Problem 10: Next Smaller Element (Codeforces Pattern)
// For each element, find next smaller element to right.
// ============================================================
vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= nums[i])
            st.pop();
        if (!st.empty()) result[i] = st.top();
        st.push(nums[i]);
    }
    return result;
}

int main() {
    cout << "=== Stack Problems ===" << endl;

    cout << "Valid Parentheses: " << isValid("({[]})") << endl;
    cout << "Reverse String: " << reverseString("hello") << endl;

    vector<int> nums = {4, 5, 2, 10, 8};
    auto nge = nextGreaterElement(nums);
    cout << "Next Greater: ";
    for (int x : nge) cout << x << " ";
    cout << endl;

    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    auto td = dailyTemperatures(temps);
    cout << "Daily Temps: ";
    for (int x : td) cout << x << " ";
    cout << endl;

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle: " << largestRectangleArea(heights) << endl;

    vector<string> rpn = {"2", "1", "+", "3", "*"};
    cout << "RPN Eval: " << evalRPN(rpn) << endl;

    cout << "Simplify Path: " << simplifyPath("/a/./b/../../c/") << endl;

    return 0;
}
