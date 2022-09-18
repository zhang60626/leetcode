/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n)
    // space complexity: o(1)
    string reverseWords(string s) {
        int lastIndex = 0;
        for (int i = 0; i <= s.length(); ++i) {
            if (s[i] == ' ' || i == s.length()) {
                reverse(s.begin() + lastIndex, s.begin() + i);
                lastIndex = i + 1;
            }
        }
        return s;
    }
};
// @lc code=end

