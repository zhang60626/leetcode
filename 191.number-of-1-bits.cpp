/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        // GCC built in function
        // return __builtin_popcount(n);
        int count = 0;
        while (n > 0) {
            // if (n & 1) count++;
            // n >>= 1;
            n &= (n - 1);
            count++;
        }
        return count;
    }


};
// @lc code=end

