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
    // -------not understand----------
    // binary search. see https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation
    // time complexity: o(log min(m, n))
    // space complexity: o(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2 - i;
            if (i && nums1[i - 1] > nums2[j]) {
                right = i - 1;
            } else if (i < m && nums2[j - 1] > nums1[i]) {
                left = i + 1;
            } else {
                int left_max = i ? (j ? max(nums1[i - 1], nums2[j - 1]) : nums1[i - 1]) : nums2[j - 1];
                if ((m + n) % 2) {
                    return left_max;
                }
                int right_min = i != m ? (j != n ? min(nums1[i], nums2[j]) : nums1[i]) : nums2[j];
                return (left_max + right_min) / 2.0;
            }
        }
        return 0.0;
    }
};
// @lc code=end

