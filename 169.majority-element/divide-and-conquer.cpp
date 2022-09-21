/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    // divide and conquer
    // time complexity: o(n log(n))
    // space complexity: o(log n)
    int majorityElement(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    int helper(vector<int>& nums, int low, int high) {
        if (low == high) return nums[low];
        int mid = low + (high - low) / 2;
        int left = helper(nums, low, mid);
        int right = helper(nums, mid + 1, high);
        if (left == right) return left;
        int left_count = 0;
        int right_count = 0;
        for (int i = low; i < high + 1; ++i) {
            if (nums[i] == left) left_count++;
            else if (nums[i] == right) right_count++;
        }
        return left_count > right_count ? left : right;
    }
};
// @lc code=end

