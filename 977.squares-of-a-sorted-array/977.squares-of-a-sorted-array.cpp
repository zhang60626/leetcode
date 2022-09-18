/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    // square and sort
    // time complexity: o(n log(n))
    // space complexity: o(1)
    /*
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] *= nums[i];
        }
        std::sort(nums.begin(), nums.end(), [](int x, int y) {
            return x < y;
        });
        return nums;
    }
    */
    // two-pointers
    // time complexity: o(n)
    // space complexity: o(n)
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left;
        int right = n - 1;
        int p = n - 1;
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right])) {
                res[p--] = nums[right] * nums[right];
                --right;
            } else {
                res[p--] = nums[left] * nums[left];
                ++left;
            }
        }
        return res;
    }
};
// @lc code=end

