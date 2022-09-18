/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(m + n)
    // space complexity: o(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (m && n) {
            if (nums1[m - 1] <= nums2[n - 1]) {
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            } else {
                nums1[m + n - 1] = nums1[m - 1];
                m--;
            }
        }
        while (n) {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }
    }
};
// @lc code=end

