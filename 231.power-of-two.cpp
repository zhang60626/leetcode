/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    // count bit that is 1
    bool isPowerOfTwo(int n) {
        if (n <=0 ) return false;
        int count = 0;
        while (n > 0) {
            if (n & 1) count++;
            n >>= 1;
        }
        return  count == 1 ? true : false;
    }

    // if n is power of two, then n & n - 1 must be 0
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};
// @lc code=end

