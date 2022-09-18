/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start

class Solution {
public:
    // time complexity: o(log n)
    // space complexity: o(1)
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int right = x / 2;
        int left = 1;
        int result = left;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long temp = mid * mid;
            if (temp == x) {
                return mid;
            } else if (temp > x) {
                right = mid - 1;
            } else {
                result = mid;
                left = mid + 1;
            }
        }
        return result;
    }
};
// @lc code=end

