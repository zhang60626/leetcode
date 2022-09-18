/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    // use a vector to count each letter
    // time complexity: o(n)
    // space complexity: o(n)
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> si(26, 0);
        vector<int> ti(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            si[s[i] - 'a']++;
            ti[t[i] - 'a']++;
        }
        if (si == ti) return true;
        return false;
    }
    // hash map
    // time complexity: o(n)
    // space complexity: o(n)
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> cmap;
        for (int i = 0; i < s.length(); ++i) {
            cmap[s[i]]++;
        }
        for (int i = 0; i < t.length(); ++i) {
            cmap[t[i]]--;
            if (cmap[t[i]] < 0) return false;
        }
        return true;
    }
};
// @lc code=end

