/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n)
    // space complexity: o(1)
    /*
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[count] != nums[i]) {
                nums[++count] = nums[i];
            }
        }
        return count + 1;
    }
    */

    // use STL function distance() and unique()
    // time complexity: o(n)
    // spcae complexity: o(1)
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};
// @lc code=end

