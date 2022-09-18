/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n)
    // space complexity: o(1)
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int changeIndex = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                index = i - 1;
                break;
            }
        }
        if (index == -1) {  // array is none-increase. just reverse the array.
            reverse(nums.begin(), nums.end());
        } else {
            for (int i = nums.size() - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    changeIndex = i;
                    break;
                }
            }
            swap(nums[changeIndex], nums[index]);
            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};
// @lc code=end

