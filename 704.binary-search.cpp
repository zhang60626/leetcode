/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(log n)
    // space complexity: o(1)
    /*
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    */
    // binary search recursive version
    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
    int helper(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return helper(nums, mid + 1, right, target);
        } else {
            return helper(nums, left, mid - 1, target);
        }
    }
};
// @lc code=end

