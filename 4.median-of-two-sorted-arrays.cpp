/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    // merge two arrays. (this is not the expected answear that should satisify o(log n) time complexity).
    // time complexity: o(m + n)
    // space complexity: o(m + n)
    /*
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> merged;
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }
        while (i < n1) {
            merged.push_back(nums1[i++]);
        }
        while (j < n2) {
            merged.push_back(nums2[j++]);
        }
        if ((n1 + n2) % 2) {
            return merged[(n1 + n2) / 2];
        } else {
            return (merged[(n1 + n2) / 2] + merged[(n1 + n2) / 2 - 1]) / 2.0;
        }
    }
    */
};
// @lc code=end

