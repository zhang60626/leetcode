/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n) worst, o(log n) best
    // space complaxity: o(1)
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left != right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[left] > nums[mid]){
                if (nums[mid] < target && target <= nums[right - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                ++left;
            }
        }
        return false;
    }
};
// @lc code=end

