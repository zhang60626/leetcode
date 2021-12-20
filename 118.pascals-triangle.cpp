/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(n), n: elements of triangle
    // space complexity: o(n)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows <= 0) return triangle;
        triangle.push_back(vector<int>(1, 1));
        while (--numRows) {
            int n = triangle.size();
            vector<int> temp(n + 1);
            temp[0] = 1;
            temp[n] = 1;
            for (int i = 1; i < n; ++i) {
                temp[i] = triangle[n - 1][i - 1] + triangle[n - 1][i];
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};
// @lc code=end

