/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    // 时间复杂度： o(n * n!)
    // 空间复杂度：o(n)
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0, nums.size());
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int first, int len) {
        if (first == len) { // 所有数数完了
            result.push_back(nums);
            return;
        }
        for (int i = first; i < len; ++i) {
            swap(nums[i], nums[first]);
            backtrack(nums, result, first + 1, len);
            swap(nums[i], nums[first]); // 撤销操作
        }
    }
};
// @lc code=end

