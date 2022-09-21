/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    // random
    // time complexity: worst o(inf) avg o(n)
    // space complexity: o(1)
    int majorityElement(vector<int>& nums) {
        int hsize = nums.size() / 2;
        while (true) {
            int majority = nums[rand() % nums.size()];
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (majority == nums[i]) count++;
            }
            if (count > hsize) return majority;
        }
        return -1;
    }
};
// @lc code=end

