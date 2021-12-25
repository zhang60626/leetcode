/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    // hash table
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> imap;
        for (int i = 0; i < nums.size(); ++i) {
            imap[nums[i]]++;
        }
        for (pair<int, int> c : imap) {
            if (c.second == 1) return c.first;
        }
        return 0;
    }

    // XOR
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ret ^= nums[i];
        }
        return ret;
    }
};
// @lc code=end

