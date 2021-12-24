/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n)
    // space complexity: o(n)
    /*
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        vector<int> steps(n + 1, 0);
        steps[1] = 1;
        steps[2] = 2;
        return dp(n, steps);
    }
    
    int dp(int n, vector<int>& steps) {
        if (steps[n] != 0) return steps[n];
        steps[n] = dp(n - 1, steps) + dp(n - 2, steps);
        return steps[n];
    }
    */

    // time complexity: o(n)
    // space complexity: o(1)
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int ret = 2;
        int prev = 1;
        for (int i = 3; i <= n; ++i) {
            int t = ret;
            ret = ret + prev;
            prev = t;
        }
        return ret;
    }
};
// @lc code=end


