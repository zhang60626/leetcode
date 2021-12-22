/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n)
    // space complexity: o(n)
    bool isValid(string s) {
        stack<char> sc;
        for (int i = 0; i < s.length(); ++i) {
            if (sc.empty()) {
                sc.push(s[i]);
                continue;
            }
            if ((sc.top() == '(' && s[i] == ')')  || (sc.top() == '[' && s[i] == ']')
                || (sc.top() == '{' && s[i] == '}')) {
                sc.pop();
            } else sc.push(s[i]);
        }
        if (sc.empty()) return true;
        return false;
    }
};
// @lc code=end

