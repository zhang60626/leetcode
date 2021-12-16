/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    // STL solution
    /*
    void reverseString(vector<char>& s) {
        std::reverse(s.begin(), s.end());
    }
    */
    // two-pointers
    // time complexity: o(n)
    // space complexity: o(1)
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
// @lc code=end

