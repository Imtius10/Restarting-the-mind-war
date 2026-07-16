// ============================================================
// STRING ALGORITHMS - 25 Solutions (LeetCode + Codeforces)
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ============================================================
// SECTION A: BASIC STRING MANIPULATION
// ============================================================

// Problem 5.1 - Valid Anagram (LeetCode #242)
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (char c : t) { count[c - 'a']--; if (count[c-'a'] < 0) return false; }
    return true;
}

// Problem 5.2 - Group Anagrams (LeetCode #49)
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& s : strs) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        mp[sorted].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [key, group] : mp) result.push_back(group);
    return result;
}

// Problem 5.3 - Valid Palindrome (LeetCode #125)
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

// Problem 5.4 - Longest Palindromic Substring (LeetCode #5)
string expandAroundCenter(string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--; right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    string longest = "";
    for (int i = 0; i < s.size(); i++) {
        string odd = expandAroundCenter(s, i, i);
        string even = expandAroundCenter(s, i, i + 1);
        longest = longest.size() > odd.size() ? longest : odd;
        longest = longest.size() > even.size() ? longest : even;
    }
    return longest;
}

// Problem 5.5 - Reverse Words (LeetCode #151)
string reverseWords(string s) {
    stringstream ss(s);
    string word, result;
    while (ss >> word) {
        if (!result.empty()) result = " " + result;
        result = word + result;
    }
    return result;
}

// ============================================================
// SECTION B: PATTERN MATCHING (KMP)
// ============================================================

// Problem 5.6 - KMP Pattern Matching (LeetCode #28)
vector<int> buildLPS(string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int n = haystack.size(), m = needle.size();
    vector<int> lps = buildLPS(needle);
    int i = 0, j = 0;
    while (i < n) {
        if (haystack[i] == needle[j]) { i++; j++; }
        if (j == m) return i - j;
        else if (i < n && haystack[i] != needle[j]) {
            if (j) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}

// Problem 5.7 - Repeated Substring Pattern (LeetCode #459)
bool repeatedSubstringPattern(string s) {
    string doubled = s + s;
    return doubled.substr(1, doubled.size() - 2).find(s) != string::npos;
}

// Problem 5.8 - Shortest Palindrome (LeetCode #214)
string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string combined = s + "#" + rev;
    vector<int> lps = buildLPS(combined);
    return rev.substr(0, s.size() - lps.back()) + s;
}

// Problem 5.9 - Longest Happy Prefix (LeetCode #1392)
string longestPrefix(string s) {
    vector<int> lps = buildLPS(s);
    return s.substr(0, lps.back());
}

// Problem 5.10 - Z-Function
vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
    }
    return z;
}

// ============================================================
// SECTION C: TRIE
// ============================================================

// Problem 5.11 - Implement Trie (LeetCode #208)
class Trie {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    } *root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

// Problem 5.15 - Word Break (LeetCode #139)
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

// ============================================================
// SECTION D: STRING HASHING
// ============================================================

// Problem 5.16 - Rabin-Karp Pattern Matching
vector<int> rabinKarp(string& text, string& pattern) {
    const int base = 31, mod = 1e9 + 7;
    int n = text.size(), m = pattern.size();
    if (m > n) return {};

    long long patternHash = 0, textHash = 0, power = 1;
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % mod;
        textHash = (textHash * base + text[i]) % mod;
        if (i < m - 1) power = (power * base) % mod;
    }

    vector<int> result;
    for (int i = m; i <= n; i++) {
        if (patternHash == textHash && text.substr(i - m, m) == pattern)
            result.push_back(i - m);
        if (i < n) {
            textHash = (textHash - text[i - m] * power % mod + mod) % mod;
            textHash = (textHash * base + text[i]) % mod;
        }
    }
    return result;
}

// Problem 5.18 - Check Binary Codes (LeetCode #1461)
bool hasAllCodes(string s, int k) {
    unordered_set<string> seen;
    for (int i = 0; i <= (int)s.size() - k; i++)
        seen.insert(s.substr(i, k));
    return seen.size() == (1 << k);
}

// Problem 5.19 - Distinct Substrings
int countDistinctSubstrings(string s) {
    unordered_set<string> substrings;
    for (int i = 0; i < s.size(); i++) {
        string current = "";
        for (int j = i; j < s.size(); j++) {
            current += s[j];
            substrings.insert(current);
        }
    }
    return substrings.size() + 1; // +1 for empty string
}

// Problem 5.23 - String Compression (LeetCode #443)
int compress(vector<char>& chars) {
    int i = 0, index = 0;
    while (i < chars.size()) {
        char current = chars[i];
        int count = 0;
        while (i < chars.size() && chars[i] == current) { i++; count++; }
        chars[index++] = current;
        if (count > 1) {
            for (char c : to_string(count)) chars[index++] = c;
        }
    }
    return index;
}

// Problem 5.24 - Decode String (LeetCode #394)
string decodeString(string s) {
    stack<pair<string, int>> stk;
    string current = "";
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) num = num * 10 + c - '0';
        else if (c == '[') {
            stk.push({current, num});
            current = ""; num = 0;
        } else if (c == ']') {
            auto [prev, count] = stk.top(); stk.pop();
            string temp = "";
            for (int i = 0; i < count; i++) temp += current;
            current = prev + temp;
        } else current += c;
    }
    return current;
}

// Problem 5.25 - Minimum Remove for Valid Parentheses (LeetCode #1249)
string minRemoveToMakeValid(string s) {
    stack<int> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') stk.push(i);
        else if (s[i] == ')') {
            if (!stk.empty()) stk.pop();
            else s[i] = '*';
        }
    }
    while (!stk.empty()) { s[stk.top()] = '*'; stk.pop(); }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
}

// ============================================================
// MAIN - Testing
// ============================================================
int main() {
    cout << "=== String Solutions ===" << endl;

    cout << "Anagram: " << isAnagram("anagram", "nagaram") << endl;
    cout << "Longest Palindrome: " << longestPalindrome("babad") << endl;
    cout << "KMP Find: " << strStr("hello", "ll") << endl;
    cout << "Shortest Palindrome: " << shortestPalindrome("aacecaaa") << endl;

    Trie trie;
    trie.insert("apple");
    cout << "Trie Search apple: " << trie.search("apple") << endl;
    cout << "Trie Search app: " << trie.search("app") << endl;
    cout << "Trie StartsWith app: " << trie.startsWith("app") << endl;

    vector<string> words = {"leet", "code"};
    cout << "Word Break: " << wordBreak("leetcode", words) << endl;

    string text = "ABABABA", pattern = "ABA";
    auto matches = rabinKarp(text, pattern);
    cout << "Rabin-Karp matches: ";
    for (int m : matches) cout << m << " ";
    cout << endl;

    string decoded = decodeString("3[a2[c]]");
    cout << "Decoded: " << decoded << endl;

    cout << "Min Remove: " << minRemoveToMakeValid("lee(t(c)o)de)") << endl;

    return 0;
}
