/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    // DP - tabulation
    // time complexity: o(n)
    // space complexity: o(n)
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        nums[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); ++i) {
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
        }
        return nums[n - 1];
    }
};
// @lc code=end

