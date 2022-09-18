/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    // hash map
    // time complexity: o(n)
    // space complexity: o(n)
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> cmap;
        for (int i = 0; i < magazine.length(); ++i) {
            cmap[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.length(); ++i) {
            cmap[ransomNote[i]]--;
            if (cmap[ransomNote[i]] < 0) return false;
        }
        return true;
    }
};
// @lc code=end

