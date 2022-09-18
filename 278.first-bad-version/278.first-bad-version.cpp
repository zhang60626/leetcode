/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // time complexity: o(log n)
    // space complexity: o(1)
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int bad;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                bad = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return bad;
    }
};
// @lc code=end

