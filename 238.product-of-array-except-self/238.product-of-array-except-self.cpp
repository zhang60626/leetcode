/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n)
    // space complexity: o(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answear(nums.size(), 0);
        int product = 1;
        int zero_count = 0;
        int index = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) product *= nums[i];
            else { 
                zero_count++;
                index = i;
                if (zero_count > 1) break;
            }
        }
        if (zero_count >= 2) return answear;
        if (zero_count == 1) {
            answear[index] = product;
            return answear;
        }
        for (int i = 0; i < nums.size(); ++i) {
            answear[i] = product / nums[i];
        }
        return answear;
    }
};
// @lc code=end

