/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    // convert to string
    // time: o(n)
    /*
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string s = to_string(x);
        string s_r = s;
        reverse(s_r.begin(), s_r.end());
        if (s_r == s) 
            return true;
        return false;
    }
    */
   /*
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        // use long long to avoid overflow
        // example: 1234567899
        long long reverse_num = 0;
        int temp = x;
        for (; temp > 0; temp /= 10) {
            reverse_num = reverse_num * 10 + temp % 10;
        }
        if (reverse_num == x) 
            return true;
        return false;
    }
    */
    // Revert half of the number then compare
    // don't need to consider overflow
    // time: o(log n)  space: o(1)
    bool isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0))
            return false;
        int sum = 0;
        for (; x > sum; x /= 10) {
            sum = sum * 10 + x % 10;
        }
        if (sum == x || x == sum / 10) 
            return true;
        return false;
    }
};
// @lc code=end

