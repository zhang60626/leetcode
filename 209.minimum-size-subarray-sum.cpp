/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    // two-pointers
    // time complexity: o(n)
    // space complexity: o(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = nums[0];
        int min_num = nums.size() + 1;
        while(left < nums.size()) {
            if (sum >= target) {
                min_num = min(min_num, right - left + 1);
                sum -= nums[left++];
            } else {
                ++right;
                if (right >= nums.size()) {
                    break;
                }
                sum += nums[right];
            }
        }
        return min_num < nums.size() + 1 ? min_num : 0;
    }
    // binary search
    // explain: https://leetcode.com/problems/minimum-size-subarray-sum/discuss/59090/C%2B%2B-O(n)-and-O(nlogn)
    // time complexity: o(n log(n))
    // space complexity: o(1)
    /*
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int min_num = nums.size() + 1;
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= nums.size(); ++i) {
            int to_find = target + sums[i - 1];
            // time complexity of lower_bound(): o(log n)
            vector<int>::iterator bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end()) {
                min_num = min(min_num, static_cast<int>(bound - (sums.begin() + i - 1)));
            }
        }
        return min_num < nums.size() + 1 ? min_num : 0;
    }
    */
};
// @lc code=end

