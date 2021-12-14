/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    // brute solution (time limite exceeded)
    // time complexity: o(n^2)
    // space complexity: o(1)
    /*
    int maxArea(vector<int>& height) {
        int result = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                int water = (j - i) * min(height[i], height[j]);
                if (water > result) {
                    result = water;
                }
            }
        }
        return result;
    }
    */
    // two-pointers
    // time complexity; o(n)
    // space complexity: o(1)
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int h = min(height[left], height[right]);
            result = max(result, (right - left) * h);
            while (left < right && height[left] <= h) {
                ++left;
            } 
            while (left < right && height[right] <= h ){
                --right;
            }
        }
        return result;
    }
};
// @lc code=end

