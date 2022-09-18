/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    // use std::set. you can also use std::unordered_map.
    /*
    bool containsDuplicate(vector<int>& nums) {
        set<int> iset;
        for (int i = 0; i < nums.size(); ++i) {
            if (iset.find(nums[i]) != iset.end()) {
                return true;
            }
            iset.insert(nums[i]);
        }
        return false;
    }
    */
    // time complexity: o(n log n)
    // space complexity: o(1)
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return truel
            }
        }
        return false;
    }
};
// @lc code=end

