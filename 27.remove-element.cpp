/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
// similar to leetcode 283 move zeroes
class Solution {
public:
    // time complexity: o(n)
    // space complexity: o(1)
    int removeElement(vector<int>& nums, int val) {
        int lastNoneValIndex = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[lastNoneValIndex++] = nums[i];
            }
        }
        return lastNoneValIndex;
    }
};
// @lc code=end

