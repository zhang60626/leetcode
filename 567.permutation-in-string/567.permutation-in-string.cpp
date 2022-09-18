/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.length();
        unordered_map<char, int> map;
        for (int i = 0; i < len; ++i) {
            map[s1[i]]++;   // int 值默认初始化为 0；所以直接 ++
        }
        for (int right = 0; right < s2.length(); ++right) {
            map[s2[right]]--;
            if (map[s2[right]] == 0) {
                map.erase(s2[right]);
            }
            int left = right - len;
            if (left >= 0) {
                map[s2[left]]++;
                if (map[s2[left]] == 0) {
                    map.erase(s2[left]);
                }
            }
            if (map.size() == 0) return true;
        }
        return false;
    }
    // string only contains lowercase English letters
    bool checkInclusion(string s1, string s2) {
        vector<int> cur(26, 0);
        vector<int> goal(26, 0);
        for (char c : s1) goal[c - 'a']++;
        for (int i = 0; i < s2.length(); ++i) {
            cur[s2[i] - 'a']++;
            if (i >= s1.length()) {
                cur[s2[i - (int)s1.length()] - 'a']--;
            }
            if (cur == goal) return true;
        }
        return false;
    }
};
// @lc code=end

