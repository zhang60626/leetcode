/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(log n)
    // space complexity: o(1)
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        int min = nums[0];
        if (nums[right - 1] > nums[left]) 
            return nums[0];
        while (left != right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid]) {
                if (nums[left] < min) {
                    min = nums[left];
                }
                left = mid + 1;
            } else {
                if (nums[mid] < min) {
                    min = nums[mid];
                }
                right = mid;
            } 
        }
        return min;
    }
};
// @lc code=end

