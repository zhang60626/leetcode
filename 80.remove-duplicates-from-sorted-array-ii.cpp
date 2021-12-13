/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n)
    // space complexity: o(1)
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int count = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[count - 2] != nums[i]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
// @lc code=end

