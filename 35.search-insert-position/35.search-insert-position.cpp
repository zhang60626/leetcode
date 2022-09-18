/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(log n)
    // space complexity: o(1)
    /*
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left != right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] >= target) {
            return left;
        } else {
            return left + 1;
        }
    }
    */
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
// @lc code=end

