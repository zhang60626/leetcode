/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    // brute approach (time limit exceeded).
    // time complexity: o(n^2);
    // space complexity: o(1)
    /*
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                max = sum > max ? sum : max;
            }
        }
        return max;
    }
    */
    // divide and conquer approach
    // time complexity: o(n log(n))
    // space complexity: o(1)
    /*
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
    int solve(vector<int>& nums, int left, int right) {
        if (left > right) return INT_MIN;
        if (left == right) return nums[left];
        int mid = left + (right - left) / 2;
        int lmax = solve(nums, left, mid);  // 左边子列最大和
        int rmax = solve(nums, mid + 1, right); // 右边子列最大和
        int ml = INT_MIN;
        int mr = INT_MIN;
        // ml + mr 为跨两个子列的最大和
        for (int i = mid, sum = 0; i >= left; --i) {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = mid + 1, sum = 0; i <= right; ++i) {
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr);
    }
    */
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxNum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            maxNum = max(sum, maxNum);
            if (sum < 0) sum = 0;
        }
        return maxNum;
    }
};
// @lc code=end


