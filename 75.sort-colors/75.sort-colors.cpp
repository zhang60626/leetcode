/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    // pop sort
    // time complexity: o(n^2)
    // space complexity: o(1)
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; j < nums.size() - i; ++j) {
                if (nums[j - 1] > nums[j]) swap(nums[j - 1], nums[j]);
            }
        }
    }

    // select sort
    // time complexity: o(n^2)
    // space complexity: o(1)
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int idx = 0;
            for (int j = 0; j < nums.size() - i; ++j) {
                if (nums[j] > nums[idx]) idx = j;
            }
            swap(nums[idx], nums[nums.size() - i - 1]);
        }
    }

    // three pointers
    // dutch national flag problem
    void sortColors(vector<int>& nums) {
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;
        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[left]);
                mid++;
                left++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};
// @lc code=end

