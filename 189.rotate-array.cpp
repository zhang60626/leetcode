/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n)
    // space complexity: o(k % n)
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size()) k %= nums.size();
        if (k == 0) return;
        vector<int> temp(nums.end() - k, nums.end());
        for (int i = nums.size() - 1; i - k >= 0; --i) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = temp[i];
        }
    }
    // brute solution (time limit exceeded)
    // time complexity: o(n * (k % n))
    // space complexity: o(1)
    /*
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size()) k %= nums.size();
        if (k == 0) return;
        while (k--) {
            int t = nums[nums.size() - 1];
            for (int i = nums.size() - 1; i > 0; --i) {
                nums[i] = nums[i - 1];
            }
            nums[0] = t;
        }
    }
    */
    // time complexity: o(n)
    // space complexity: o(1)
    /*
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end() - k);
        std::reverse(nums.end() - k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
    */
};
// @lc code=end

