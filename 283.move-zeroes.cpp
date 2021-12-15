/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    // brute solution
    // time complexity: o(n^2)
    // space complexity: o(1)
    /*
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < n; ++j) {
                    nums[j - 1] = nums[j];
                }
                nums[n - 1] = 0;
                --i;
                --n;
            }
        } 
    }
    */
    // use a extra array. this solution is not the expected one that 
    // should be o(1) space complexity.
    // time complexity: o(n)
    // space complexity: o(n)
    /*
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = 0, j = 0; i < n; ++i) {
            if (nums[i] != 0) {
                res[j++] = nums[i];
            }
        }
        nums = res;
    }
    */
    // time complexity: o(n)
    // space complexity: o(1)
    void moveZeroes(vector<int>& nums) {
        int lastNoneZeroIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[lastNoneZeroIndex++] = nums[i];
            }
        }
        while (lastNoneZeroIndex < nums.size()) {
            nums[lastNoneZeroIndex++] = 0;
        }
    }
    // STL solution
    void moveZeroes(vector<int>& nums) {
        stable_partition(begin(nums), end(nums), [](int x) {return x;});
        // stable_partition(rbegin(nums), rend(nums), logical_not<int>());
    }
};
// @lc code=end

