/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    // hash map & sliding-window approach
    // time complexity: o(n^2) ???
    // space complexity:ｏ(n)
    /*
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        unsigned long maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (map.find(s[i]) != map.end()) {
                int k = i - map.size();
                for (int j = map[s[i]] - 1; j >= k; j--) {
                    map.erase(map.find(s[j]));
                }
            }
            map[s[i]] = i;
            maxLen = max(maxLen, map.size());
        }
        return maxLen;
    }
    */
    // hash map & sliding-window approach Optimized (not remove element outside window)
    // time complexity: o(n)
    // space complexity:ｏ(n)
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int maxLen = 0;
        int start = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (map.find(s[i]) != map.end() && map[s[i]] > start) {
                start = map[s[i]];
            }
            map[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
// @lc code=end

